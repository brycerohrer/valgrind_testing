#include <iostream>

using namespace std;

void foo(bool x) {
  if (x) {
    cout << "This worked" << endl;
  } else {
    cout << "Oops this didn't work "<< endl;
  }

}
int main() {

  bool test;

  foo(test);
}
