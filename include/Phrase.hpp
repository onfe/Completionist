#pragma once
#include <vector>
#include <string>
#include <stdint.h>

struct Phrase {
  std::uint64_t weight;
  std::string phrase;

  Phrase(std::uint64_t w, std::string p);

  bool operator<(Phrase const &rhs) const;
};
