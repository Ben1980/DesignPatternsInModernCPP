#include <iostream>
#include <vector>
#include <memory>

struct Token
{
  int value;

  Token(int value) : value(value) {}
};

struct Memento
{
  std::vector<std::shared_ptr<Token>> tokens;
};

struct TokenMachine
{
  std::vector<std::shared_ptr<Token>> tokens;

  Memento add_token(int value)
  {
    return add_token(std::make_shared<Token>(value));
  }

  // adds the token to the set of tokens and returns the
  // snapshot of the entire system
  Memento add_token(const std::shared_ptr<Token>& token)
  {
    if(token) {
      tokens.push_back(token);
    }
    Memento memento;
    for(auto t : tokens) {
      memento.tokens.emplace_back(std::make_shared<Token>(t->value));
    }

    return memento;
  }

  // reverts the system to a state represented by the token
  void revert(const Memento& m)
  {
    tokens.clear();
    for(auto t : m.tokens) {
      tokens.emplace_back(std::make_shared<Token>(t->value));
    }
  }
};
