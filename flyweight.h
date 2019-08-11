#include <string>
#include <vector>
#include <sstream>

// External data representation, e.g. map, vector, etc
// Example:
// Sentence sentence("hello world");
// sentence[1].capitalize = true;
class Sentence
{
public:
  Sentence(const std::string& text) {
    std::istringstream stream(text);
    std::string s;

    while (std::getline(stream, s, ' ')) {
      sentence.push_back( {s, false} );
    }
  }

  struct WordToken
  {
    std::string word;
    bool capitalize;
  };

  WordToken& operator[](size_t index)
  {
    return sentence[index];
  }

  std::string str() const
  {
    std::string str;

    for(size_t tokeIndex = 0; tokeIndex < sentence.size(); ++tokeIndex) {
      WordToken token = sentence[tokeIndex];
      
      if(token.capitalize) {
        for(size_t charIndex = 0; charIndex < token.word.length(); ++charIndex) {
          auto c = std::toupper(token.word[charIndex]);
          token.word[charIndex] = c;
        }
      }

      str += token.word + (tokeIndex < sentence.size()-1 ? " " : "");
    }

    return str;
  }

private:
  std::vector<WordToken> sentence;
};
