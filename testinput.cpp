#include <iostream> 
#include <fstream> 
using namespace std; 

int const SIZE = 5; 
struct type {
     char name [500]; 
     int age; 
};




int main () {

ifstream file_in;  //reading from files 
ofstream file_out; //writing to file


//file_in("test.txt"); //initialize file or do 
file_in.open("test.txt"); 

type array [SIZE]; 
char name [500]; 

for (int i = 0; i < SIZE; ++i) {
   array[i].age = 0; 
} 



for (int i = 0; i < SIZE; i++) {
  //  if (file_in) {
      
        
//      if (file_in >> array[i].name && !file_in.eof()) {

// 	//file_in >> array[i].name; 
//         file_in >> array[i].age;
        
	 
// 	cout <<"Name[" << i << "]: " << array[i].name <<endl; 
// 	cout <<"Age[" << i << "]:" << array[i].age << endl; 
//                                      }

//                  }
       
// } 





return 0; 
}

