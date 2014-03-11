#include <iostream> 
#include <string.h> 
#include <time.h> 
#include <fstream>
using namespace std; 

 

struct node {
  int value; 
  char *array; 
  node* next; 
};

class hashtable {
  public: 
     hashtable(int SIZE);
     void insert (char array [], int a);  
     //int table (int SIZE);  
     int hashfunction(char array[]);
     void displayAll(); 
     int find(char a[]); 
  private: 
     node** hashTable; 
     int tablesize; 
};
     
hashtable::hashtable(int SIZE) { 
        
    
    hashTable = new node*[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
	hashTable[i] = NULL; 
    }
       tablesize = SIZE;  
}

int hashtable::hashfunction (char array []) {
  int hashvalue = 0; 
  for (int i = 0; i < strlen(array); ++i) {
     hashvalue += array[i]; 
      
  }
  return hashvalue % tablesize; 
}
  

void hashtable::insert(char a [], int number) {
   int index = hashfunction(a); 


   node *temp = new node; 
   temp -> value = number;
   temp -> array = new char [strlen(a) + 1];  
   strcpy (temp -> array, a);
   temp -> next = hashTable[index]; 
   hashTable[index] = temp; 
   temp = NULL; //set temp to null 

   
} 




int hashtable::find (char a[]) { 
   int index = hashfunction(a); 
    
   node *current = NULL; //initialize to NULL
	
   current = hashTable[index]; 
    
    while (current != NULL) //while current is not NULL 
    { 
          if (strcmp (current -> array, a) == 0) { 
             //cout <<"Found" <<endl; 
             return 1; 
            }
           current = current -> next; 
			 
     }
        
}


void initialize (char name[], int &age) {
  name[0] = '\0';
  age = 0;
}

int main () {
 

   char FILENAME [200] = "alphabet_testMaster.txt";  
   int SIZE = 2000; 
  /*
   cout <<"File name to test : " << endl; 
   cin.get(FILENAME, 200, '\n'); 
   cin.ignore(100, '\n'); 
   cout <<"Size of Hash table : "; 
   cin >> SIZE; 
   cin.ignore(); 
  */ 
   

  
  int start_s=clock();
	// the code you wish to time goes here

  ifstream file_in; //reading from files
  file_in.open(FILENAME);

  hashtable hash(SIZE);
  //char s1 [200] = "testfile2";
  char name[200];
  int age;
  initialize(name, age);
 
  if (file_in) {
    while (file_in >> name && !file_in.eof()) {

       for (unsigned int i = 0; i < strlen(name); ++i) {
          name[i] = tolower(name[i]); 
        }
        file_in >> age;
        
      // cout <<"Name: " << name <<endl;
      // cout <<"Age:" << age << endl;
        hash.insert(name, age);
        initialize(name, age); 

      }
  }

  file_in.close(); 
  file_in.open(FILENAME); 
  
  if (file_in) {
    while (file_in >> name && !file_in.eof()) {
       for (unsigned int i = 0; i < strlen(name); ++i) {
          name[i] = tolower(name[i]); 
        }
          file_in >> age; 
          hash.find(name);
      
     
      }
     initialize(name, age); 
   }

   int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;


return 0; 


} 
