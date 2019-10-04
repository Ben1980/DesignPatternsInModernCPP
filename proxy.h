#include <string>

class Person
{
  friend class ResponsiblePerson;
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age=age; }

  std::string drink() const { return "drinking"; }
  std::string drive() const { return "driving"; }
  std::string drink_and_drive() const { return "driving while drunk"; }
};

// Acts as simple proxy of Person
class ResponsiblePerson
{
public:
    ResponsiblePerson(const Person &person) : person(person) {}
    
    int get_age() const { return person.get_age(); }
    void set_age(int age) { person.set_age(age); }

    std::string drink() const { return person.get_age() > 17 ? person.drink() : "too young"; }
    std::string drive() const { return person.get_age() > 17 ? person.drive() : "too young"; }
    std::string drink_and_drive() const { return "dead"; }
private:
    Person person;
};
