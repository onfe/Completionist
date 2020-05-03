#pragma once
#include <vector>
#include <string>
#include <stdint.h>

struct Phrase {
  std::uint32_t weight;
  std::string phrase;

  Phrase(std::uint32_t w, std::string p);

  bool operator<(Phrase const &rhs) const;
};
