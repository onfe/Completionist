#include <stdint.h>
#include <vector>

#include "PhraseRange.hpp"

PhraseRange::PhraseRange(uint32_t f, uint32_t l, uint32_t w, uint32_t i)
: first(f), last(l), weight(w), index(i) {}

bool PhraseRange::operator<(PhraseRange const &rhs) const {
  return this->weight < rhs.weight;
}
