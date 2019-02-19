#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SegmentTreeNode.hpp"

typedef std::pair<uint32_t, uint32_t> uip_t;
typedef std::vector<uip_t> uipv_t;

class SegmentTree {
  /*
   * Builds a heap based Segment Tree, given a length
   * of indicies to represent.
   */
  uint32_t length;
  uipv_t heap;

public:
  SegmentTree(uint32_t len = 0) {
    this->init(len);
  }

  void init(uint32_t len) {
    this->length = len;
    this->heap.clear();
    // this->heap.resize to log2(length) + 2
  }

  void init(std::vector<uint32_t> elements) {
    if (elements.empty()) {
      init(0)
    } else {
      this->init(elements.size());
      // start the recursive build process
      this->build(0, 0, elements.size(), elements);
    }
  }

private:
  // Create the heap and parent nodes recursively
  uip_t build(uint32_t heapIdx, uint32_t idx1,
  uint32_t idx2, std::vector<uint32_t> weights) {
    uint32_t midpoint = idx1 + (idx2 - idx1) / 2;
    // if idx1 = idx 2, must be pointing at 1 element.
    if (idx1 == idx2) {
      // add the pair [weight, index] to the heap.
      this->heap[heapIdx] = uip_t(weights[idx1], idx1);
      return this->heap[heapIdx];

    } else {
      // otherwise, get the child nodes (recursive step)
      uip_t left = this->build(heapIdx*2 + 1, idx1, midpoint, weights);
      uip_t right = this->build(heapIdx*2 + 2, midpoint+1, idx2, weights);
      // and set the values of this node to the best child weight
      this->heap[heapIdx] = (leftChild.first > rightChild.first ? left : right);
      return this->heap[heapIdx];
    }
  }
};
