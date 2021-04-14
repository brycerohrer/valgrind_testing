//******************************
//* A simple C++ program with several bugs.
//* The bugs are easy to find with valgrind (Linux/mac) or DISCOVER (solaris).
//*
//* Compile as follows:
//  g++ -g -O2 test.cc
//  valgrind ./a.out
//  discover -o test.disc a.out
//  ./test.disc
//
//********************************************** 
#include <vector>

#include <iostream>


using namespace std;


int main() {

   vector<int> vec;

   vec.resize(10);
   for (int i=0;i<10;i++) {
      vec[i] = i;
   }
   int sum = 0;
   for (int i=0;i<10;i++) {
       sum+=vec[i];
   }
   cout << "The sum is: " << sum << endl;
}
