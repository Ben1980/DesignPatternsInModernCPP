#include <iostream>
#include <vector>
#include <complex>
#include <tuple>

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    std::vector<Creature> creatures;

    CardGame(const std::vector<Creature> &creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int creature1, int creature2)
    {
      hit(creatures[creature1], creatures[creature2]);
      hit(creatures[creature2], creatures[creature1]);

      bool c1Alive = creatures[creature1].health > 0;
      bool c2Alive = creatures[creature2].health > 0;
      if (c1Alive == c2Alive) return -1;
      return c1Alive ? creature1 : creature2;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const std::vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override {
      double oldHealth = other.health;
      other.health -= attacker.attack;
      if(other.health > 0) {
        other.health = oldHealth;
      }
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const std::vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override
    {
      other.health -= attacker.attack;
    }
};
