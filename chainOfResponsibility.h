#include <vector>

struct Creature;
struct Game
{
  std::vector<Creature*> creatures;
};

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;
  virtual void query(void* source, StatQuery& sq) = 0;
};

class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) {}

  int get_attack() override {
    return get_statistic(StatQuery::attack);
  }

  int get_defense() override {
    return get_statistic(StatQuery::defense);
  }
  
  void query(void *source, StatQuery &sq) override {
    if (source == this)
    {
      switch (sq.statistic)
      {
        case StatQuery::attack:
          sq.result += base_attack;
          break;
        case StatQuery::defense:
          sq.result += base_defense;
          break;
      }
    } else
    {
      if (sq.statistic == StatQuery::defense)
      {
        sq.result++;
      }
    }
  }
  
 private:
  int get_statistic(StatQuery::Statistic stat) {
    StatQuery q{stat,0};
    for (auto c : game.creatures)
      c->query(this, q);
    return q.result;
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}
  void query(void *source, StatQuery &sq) override {
    if (source != this && sq.statistic == StatQuery::attack)
    {
      sq.result++;
    }
    else Goblin::query(source, sq);
  }
};
