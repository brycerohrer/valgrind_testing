// Useful for showing data-races
// 
// Compile g++ -g -fopenmp test4.cc
// Test:
// valgrind --tool=helgrind a.out 
//
#include <iostream>

int main() {
  int sum = 0;
  #pragma omp parallel for
  for (int i=0;i<100;i++) {
    sum+=i;
  }
}
