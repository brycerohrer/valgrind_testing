// cmos.cc
// Main program.  Includes HW1.yy.cc.

#include "HW1.yy.cc"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

bool check_similar(fingerbook* a, fingerbook* b);
//Returns true if a and b have matching fingerprints.

int main (int argc, char* argv[]) {
  string source = argv[1];
  cout << source << endl; //DEBUG
  int no_dirs = 0; //Number of directories
  YY_BUFFER_STATE this_state;

  DIR *this_dir; //Directory
  struct dirent *that_entry; //Directory entry
  struct fingerbook *check_book, *check_other_book;
   //Iterators for fingerprint books
  struct fingerbook* first_book = NULL; //Book of fingerprints
  struct fingerbook* that_book = NULL; //Traces the last book

  this_dir = opendir(argv[1]);
  if(this_dir == NULL) {
    cout << source << "?  Are you pranking me?" << endl;
    exit(-1);
  }

  string path, id;

  while((that_entry = readdir(this_dir)) != NULL) {
    id = that_entry->d_name;
    if(id.length() >= 2 && id.substr(id.length()-2,2) == ".c") {
      //open the file given by that_entry->d_name
      cout << "*****" << source << "/" << id << endl; //DEBUG
      path = source + "/" + id;

      ifstream in_str;
      
      in_str.open(path.c_str());

      cout << "Checkpoint 1" << endl; //DEBUG
      // FlexLexer *lexer;

      lexer = new yyFlexLexer(&in_str, &cout);
//      this_state = lexer->yy_create_buffer(that_entry, YY_BUF_SIZE);
//      lexer->yypush_buffer_state(this_state);

      cout << "Checkpoint 2" << endl; //DEBUG

      that_book = new fingerbook;
      that_book->name_of_file = id;

      cout << "Checkpoint 3" << endl; //DEBUG

      that_book->first_print = winnow();
      that_book->next_book = NULL;

      cout << "Checkpoint 4" << endl; //DEBUG

      if(no_dirs > 0) {
        check_book = first_book;
        while(check_book -> next_book != NULL) {
          check_book = check_book -> next_book;
        }
        check_book->next_book = that_book;
      } else first_book = that_book;
      that_book = that_book->next_book;
      no_dirs++;
      in_str.close();
    }
  }

  cout << "Directory cleaned!" << endl; //DEBUG

  closedir(this_dir);

  //Now check to see what files are similar
  int similar_count = 0; //Keep track of how many matches are found
  check_book = first_book;
  do {
    check_other_book = check_book->next_book;
    while(check_other_book != NULL) {
      if(check_similar(check_book, check_other_book)) {
        cout << check_book->name_of_file << " and " <<
        check_other_book->name_of_file << " are similar!" << endl;
        similar_count++;
      }
      check_other_book = check_other_book->next_book;
    } //while check_other_book
    check_book = check_book->next_book;
  } while(check_book != NULL);

  cout << endl << similar_count << " match(es) found." << endl;
  
  return 0;
}


//Returns true if books a and b contain comparable fingerprints.
bool check_similar(fingerbook* a, fingerbook* b) {
  //This is just a placeholder until I manage to implement it for real
  return true;
}
