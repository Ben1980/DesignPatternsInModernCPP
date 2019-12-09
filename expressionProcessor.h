#include <map>
#include <string>
#include <vector>
#include <regex>
#include <iostream>

inline std::vector<std::string> split(const std::string& stringToSplit)
{
  std::vector<std::string> result;
  size_t pos = 0, lastPos = 0;
  while ((pos = stringToSplit.find_first_of("+-", lastPos)) != std::string::npos)
  {
    result.push_back(stringToSplit.substr(lastPos, pos-lastPos+1));
    lastPos = pos+1;
  }
  result.push_back(stringToSplit.substr(lastPos));
  return result;
}

struct ExpressionProcessor
{
  std::map<char,int> variables;

  enum NextOp
  {
    nothing,
    plus,
    minus
  };

  int calculate(const std::string& expression)
  {
    int current;
    auto next_op = nothing;

    auto parts = split(expression);

    std::cout << "parts (" << parts.size() << "): ";
    for (auto& part : parts)
      std::cout << "`" << part << "` ";
    std::cout << std::endl;

    for (auto& part : parts)
    {
      auto no_op = split(part);
      auto first = no_op[0];
      int value, z;

      try
      {
        value = stoi(first);
      }
      catch (const std::invalid_argument&)
      {
        if (first.length() == 1 &&
            variables.find(first[0]) != variables.end())
        {
          value = variables[first[0]];
        }
        else return 0;
      }

      switch (next_op)
      {
        case nothing:
          current = value;
          break;
        case plus:
          current += value;
          break;
        case minus:
          current -= value;
          break;
      }

      if (*part.rbegin() == '+') next_op = plus;
      else if (*part.rbegin() == '-') next_op = minus;
    }

    return current;
  }
};
