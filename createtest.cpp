#include <iostream> 
#include <string.h> 
#include <fstream> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 

void initialize (char array [], int &value) {
  array[0] = '\0'; 
  value = 0; 
}

int main () {

   char FILENAME_OPEN [200];
   char FILENAME_WRITE [200];  
   cout <<"File name to open: "; 
   cin.get(FILENAME_OPEN, 200, '\n'); 
   cin.ignore(100, '\n'); 
   
   cout <<endl<<"Filename to store: ";  
   cin.get(FILENAME_WRITE, 200, '\n'); 
   cin.ignore(100, '\n'); 
   
  ifstream file_in;
  ofstream file_out; 
  
 
  file_in.open(FILENAME_OPEN); 
  file_out.open (FILENAME_WRITE);
  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  int random_int;
  char alphabet [200]; 
  initialize(alphabet, random_int); 
 
  if(file_in && file_out) {
    while (file_in >> alphabet && !file_in.eof()) {
      random_int = rand() % 100000000; 
      file_out << alphabet <<endl;  
      file_out << random_int<<endl;
      initialize(alphabet, random_int);
          
    } 
     
  }
 
  return 0;  
 
}
 

  
