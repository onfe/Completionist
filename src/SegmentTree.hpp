#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
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
    this->heap.resize(this->calcHeap(len));
  }

  void init(std::vector<uint32_t> elements) {
    if (elements.empty()) {
      this->init(0);
    } else {
      this->init(elements.size());
      // start the recursive build process
      this->build(0, 0, elements.size() -1, elements);
    }
  }

  uip_t getMax(uint32_t idxFirst, uint32_t idxLast) {
    return this->qmax(0, 0, this->length - 1, idxFirst, idxLast);
  }

private:
  // Create the heap and parent nodes recursively
  uip_t build (
    uint32_t heapidx,
    uint32_t idx1,
    uint32_t idx2,
    std::vector<uint32_t> weights
  ) {
    uint32_t midpoint = idx1 + (idx2 - idx1) / 2;
    // if idx1 = idx 2, must be pointing at 1 element.
    if (idx1 == idx2) {
      // add the pair [weight, index] to the heap.
      this->heap[heapidx] = uip_t(weights[idx1], idx1);
      return this->heap[heapidx];

    } else {
      // otherwise, get the child nodes (recursive step)
      uip_t left = this->build(heapidx*2 + 1, idx1, midpoint, weights);
      uip_t right = this->build(heapidx*2 + 2, midpoint+1, idx2, weights);
      // and set the values of this node to the best child weight
      this->heap[heapidx] = (left.first > right.first ? left : right);
      return this->heap[heapidx];
    }
  }

  uip_t qmax(
    uint32_t heapidx,
    uint32_t idx1,
    uint32_t idx2,
    uint32_t firstidx,
    uint32_t lastidx
  ) {
    // std::cout << "h1:" << heapidx << " i1:" << idx1 << " i2:" << idx2 << " f:" << firstidx << " l:" << lastidx << std::endl;
    if (idx1 > idx2 || firstidx > idx2 || lastidx < idx1) {
      // the indexes provided are incorrect, return [-1, -1].
      return uip_t((uint32_t)0 - 1, (uint32_t)0 - 1);
    }

    if (idx1 >= firstidx && idx2 <= lastidx) {
      // if node within range, return the node.
      return this->heap[heapidx];
    }

    // otherwise, check the children.
    uint32_t midpoint = idx1 + (idx2 - idx1) / 2;
    uip_t left = this->qmax(heapidx*2 + 1, idx1, midpoint, firstidx, lastidx);
    uip_t right = this->qmax(heapidx*2 + 2, midpoint+1, idx2, firstidx, lastidx);

    if (left.second == (uint32_t)0 - 1) {
      return right;
    } else if (right.second == (uint32_t)0 - 1) {
      return left;
    } else {
      return left.first > right.first? left : right;
    }
  }

  int calcHeap(int len) {
    int out = 0;
    while (len > 1) {
      len /= 2;
      ++out;
    }
    out = 1 << (out + 2);
    std::cout << "### " << out << " ###\n";
    return out;
  }
};
