#pragma once
#include <string>
#include "Phrase.hpp"

struct FindPrefix {
  bool operator()(std::string const& prefix, phrase_t const &target) {
    // Compare the prefix to the start of the target phrase.
    int result = target.phrase.compare(0, prefix.size(), prefix);
    return result > 0;
  }

  bool operator()(phrase_t const& target, std::string const &prefix) {
    // Compare the prefix to the start of the target phrase.
    int result = target.phrase.compare(0, prefix.size(), prefix);
    return result < 0;
  }
};
