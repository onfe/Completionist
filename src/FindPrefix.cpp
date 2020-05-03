#include <string>

#include "FindPrefix.hpp"

#include "Phrase.hpp"

bool FindPrefix::operator()(std::string const& prefix, Phrase const &target) {
  // Compare the prefix to the start of the target phrase.
  int result = target.phrase.compare(0, prefix.size(), prefix);
  return result > 0;
}

bool FindPrefix::operator()(Phrase const& target, std::string const &prefix) {
  // Compare the prefix to the start of the target phrase.
  int result = target.phrase.compare(0, prefix.size(), prefix);
  return result < 0;
}
