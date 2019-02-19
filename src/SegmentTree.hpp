#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SegmentTreeNode.hpp"

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
