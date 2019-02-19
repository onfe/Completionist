#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SegmentTree {
  vector<int> arr;
  vactor<int> heap;

public:
  SegmentTree(vector<int> arr) {
    this->_arr = arr;
  }
private:
  void build(int v, int from, int size) {

  }
};

class SegmentTreeNode {
  int s, min, max, from, to, pval;
  bool pending;
public:
  SegmentTreeNode() {
    s = 0;
    min = 0;
    max = 0;
    from = 0;
    to = 0;
    pval = 0;
    pending = false;
  }

  int size() {
    return to - from + 1;
  }
}
