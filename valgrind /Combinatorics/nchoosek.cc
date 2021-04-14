#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  bool x[10];
  
  for (int i=0;i<10;i++) {
    x[i] = false;
    if (10-i <=3) {
      x[i] = true;
    }
  }
  
  // Permutations on boolean arrays gives combinations
  do {
    cout << "Set ";
    for (int i=0;i<10;i++) {
      if (x[i]) cout << i+1 << " ";
    }
    cout << endl;

  }  while (next_permutation(x,x+10));

    
}
