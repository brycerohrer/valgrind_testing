#include <iostream>

using namespace std;

int foo(bool x) {
  if (x) {
    cout << "This worked" << endl;
    return 0;
  } else {
    cout << "Oops this didn't work "<< endl;
    return false;
  }

}
int main() {

  bool test=true;

  cout << foo(test) << endl;
}
