#pragma once
#include <string>
#include "phrase.hpp"

struct FindPrefix {
  bool operator()(std::string prefix, phrase_t target) {
    // Compare the prefix to the start of the target phrase.
    int result = target.phrase.compare(0, prefix.size(), prefix);
    return result > 0;
  }

  bool operator()(phrase_t target, std::string prefix) {
    // Compare the prefix to the start of the target phrase.
    int result = target.phrase.compare(0, prefix.size(), prefix);
    return result > 0;
  }
};
