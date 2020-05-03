#pragma once
#include <stdint.h>
#include <vector>

struct PhraseRange {

  uint32_t first, last, weight, index;

  PhraseRange(uint32_t f, uint32_t l, uint32_t w, uint32_t i);

  bool operator<(PhraseRange const &rhs) const;

};
