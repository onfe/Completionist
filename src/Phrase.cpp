#include <vector>
#include <string>
#include <stdint.h>

#include "Phrase.hpp"

Phrase::Phrase(std::uint32_t w, std::string p) : weight(w), phrase(p) {}

bool Phrase::operator<(Phrase const &rhs) const {
  return this->phrase < rhs.phrase;
}
