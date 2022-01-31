#pragma once

#include <iostream>
#include <vector>

#include "screen.h"

class Sorter {
 public:
  Sorter(Screen *screen, size_t size);
  ~Sorter();
  int Randomize();
  int InsertionSort();

 private:
  std::vector<unsigned int> data_;
  Screen *screen_;
};
