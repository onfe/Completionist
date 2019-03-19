#pragma once
#include <vector>
#include <queue>
#include <stdint.h>

#include "PhraseRange.hpp"
#include "PhraseList.hpp"
#include "SegmentTree.hpp"
#include "Phrase.hpp"

typedef std::vector<phrase_t> pvc_t;
typedef pvc_t::iterator pvci_t;
typedef std::pair<pvci_t, pvci_t> pvcip_t;
typedef std::pair<uint32_t, uint32_t> uip_t;

pvc_t suggest (
  PhraseList& pl,
  SegmentTree& st,
  std::string& prefix,
  uint32_t numResults = 16
) {
  // Get the pointers [first, last] for the candidate phrases.
  pvcip_t candidates = pl.query(prefix);

  // transform the pointers to indexes.
  uint32_t first = candidates.first - pl.pl.begin();
  uint32_t last = candidates.second - pl.pl.begin();

  // if there are no results, return an empty phrase vector.
  if (first == last) { return pvc_t(); }

  // the indexes are from first match to next non-match
  // decrement the last index to instead use first - last match.
  --last;
  pvc_t results;

  // The queue automatically orders elements so that .top() returns the largest element.
  // in this case, the largest element is the phrase range with the greatest weight.
  std::priority_queue<PhraseRange> queue;
  uip_t best = st.getMax(first, last);
  queue.emplace(first, last, best.first, best.second);

  while (results.size() < numResults && !queue.empty()) {
    PhraseRange curr = queue.top();
    queue.pop();

    // The best result is added to the result
    results.push_back(pl.pl[curr.index]);

    uint32_t lo = curr.first;
    uint32_t hi = curr.index - 1;

    // Check for underflows in indexing.
    if (curr.index -1 < curr.index && lo <= hi) {
      // index is ok, so add to queue.
      best = st.getMax(lo, hi);
      queue.emplace(lo, hi, best.first, best.second);
    }

    lo = curr.index + 1;
    hi = curr.last;

    // Check for overflows in indexing.
    if (curr.index + 1 > curr.index && lo <= hi) {
      // index is ok, so add to queue.
      best = st.getMax(lo, hi);
      queue.emplace(lo, hi, best.first, best.second);
    }
  }

  return results;
}
