#pragma once
#include <vector>
#include <string>
#include <stdint.h>

struct phrase_t {
  std::uint32_t weight;
  std::string phrase;

  phrase_t(std::uint32_t w, std::string p) : weight(w), phrase(p) {}

  bool operator<(phrase_t const &rhs) const {
    return this->phrase < rhs.phrase;
  }

};
