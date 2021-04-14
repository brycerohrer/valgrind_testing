#include <iostream>

using namespace std;

int foo(bool x) {
  if (x) {
    cout << "This worked" << endl;
  } else {
    cout << "Oops this didn't work "<< endl;
  }

}
int main() {

  bool test=true;

  cout << foo(test) << endl;
}
