#pragma once
#include <string>
#include "Phrase.hpp"

struct FindPrefix {
  bool operator()(std::string const& prefix, Phrase const &target);

  bool operator()(Phrase const& target, std::string const &prefix);
};
