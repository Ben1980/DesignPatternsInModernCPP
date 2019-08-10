#include <iostream>
#include <string>
#include <vector>
#include <numeric>

struct ContainsIntegers {
  virtual int sum() const = 0;
};

struct SingleValue : public ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }
  
  int sum() const override {
    return value;
  }
};

struct ManyValues : std::vector<int>, public ContainsIntegers
{
  void add(const int value)
  {
    push_back(value);
  }

  int sum() const override {
    int sum = 0;
    for(const int &element : *this) {
      sum += element;
    }

    return sum;
  }
};

// Example:
// SingleValue single{1};
// ManyValues many;
// many.add(2);
// many.add(3);
// std::cout << sum({&single, &many}) << std::endl;
int sum(const std::vector<ContainsIntegers*> items) {
  int sum = 0;
  for(ContainsIntegers *element : items) {
    sum += element->sum();
  }

  return sum;
}
