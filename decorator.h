#include <string>

// A Rose can be decorated with colors
// Example:
// Rose rose;
// RedFlower red_rose(rose);
// RedFlower red_red_rose(red_rose);
// BlueFlower blue_red_rose(red_rose);
// BlueFlower blue_rose(rose);
// RedFlower red_blue_red_rose(blue_red_rose);

struct Flower
{
  virtual std::string str() = 0;
};

struct Rose : Flower
{
  std::string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
  Flower &mFlower;
  const std::string color;

  RedFlower(Flower &flower) : mFlower(flower), color("red") { }

  std::string str() override {
    std::string ret = mFlower.str();

    if (ret.find("that is") == std::string::npos) {
      ret += " that is " + color;
    }
    else if (ret.find(color) == std::string::npos) {
      ret += " and " + color;
    }

    return ret;
  }
};

struct BlueFlower : Flower
{
  Flower &mFlower;
  const std::string color;

  BlueFlower(Flower &flower) : mFlower(flower), color("blue") { }

  std::string str() override {
    std::string ret = mFlower.str();

    if (ret.find("that is") == std::string::npos) {
      ret += " that is " + color;
    }
    else if (ret.find(color) == std::string::npos) {
      ret += " and " + color;
    }

    return ret;
  }
};
