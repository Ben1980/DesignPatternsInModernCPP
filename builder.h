#include <string>
#include <iostream>
#include <vector>
#include <utility>

// CodeBuilder builds strings based on fields added by the user via add_field(...)
// Example: CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
class CodeBuilder
{
public:
  CodeBuilder(const std::string& class_name)
    :  className(class_name)
  {
  }

  CodeBuilder& add_field(const std::string& name, const std::string& type)
  {
    fields.push_back({name, type});

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& obj)
  {
    os << "class " << obj.className << "\n{\n";
    for(auto field : obj.fields) {
      os << "  " << field.second << " " << field.first << ";\n";
    }
    os << "};";

    return os;
  }

private:
  std::string className;
  std::vector<std::pair<std::string, std::string>> fields;
};
