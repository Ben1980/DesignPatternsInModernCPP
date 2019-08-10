#include <string>
#include <ostream>

struct Person
{
  int id;
  std::string name;
};

// Example:
// PersonFactory personFactory;
// Person p1 = personFactory.create_person("Tom");
class PersonFactory
{
public:
  Person create_person(const std::string& name)
  {
    return {instanceCounter++, name};
  }

private:
  int instanceCounter = 0;
};
