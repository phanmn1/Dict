#include <iostream> 
#include <string.h> 
#include <time.h> 
#include <fstream>
using namespace std; 

struct node {
  char *array; 
  int value; 
  node* left; 
  node* right; 
}; 


class BSTree {
public: 
   BSTree(); 
   void insert (char a[], int number); 
   bool find (char a[]); 
protected: 
   void add (node *&root, char a [], int number); 
   int search (node *root, char a []); 
   node* root; 
};

BSTree::BSTree() { root = NULL; } 

void BSTree::insert (char a[], int number) {
       add(root, a, number); 
}

void BSTree::add (node *&root, char a [], int number) {

        if (!root)//if root is null
	{
		root = new node;
		// new allocate dynamic memory 
		root -> left = NULL; 
                root -> right = NULL; 
                root -> array = new char [strlen(a) + 1]; 
                strcpy (root -> array, a); 
                root -> value = number; 
	} 
	//If root pointer is not null 
	else if (strcmp(root -> array, a) > 0) //if less than go left 
		add (root -> left, a, number); 
	else add (root -> right, a, number); //else go right 

}

int BSTree::search (node *root, char keyword []) {
 if (!root) {    
    if (strcmp(root -> array, keyword) == 0) 
     {
	return 1; 
     }
     else if (strcmp(root -> array, keyword) > 0) 
        search (root ->left, keyword); //if smaller go left
     else 
	search (root ->right, keyword); //else go right 
  }

 //return false; 
}

bool BSTree::find (char keyword[]) {
    int i = 0; 
    i = search(root, keyword); 
    if (i == 0) 
       return false; 
    else return true; 
}


void initialize (char name[], int &age) {
  name[0] = '\0';
  age = 0;
}

int main () {

  char FILENAME [200] = "alphabet_testMaster.txt";  
   
  
  int start_s=clock();
	// the code you wish to time goes here
   

  ifstream file_in; //reading from files
  file_in.open(FILENAME);

  BSTree tree;
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
        tree.insert(name, age);
        initialize(name, age); 

      }
  }

  file_in.close(); 
  file_in.open(FILENAME); 
  bool found; 
  if (file_in) {
    while (file_in >> name && !file_in.eof()) {
       for (unsigned int i = 0; i < strlen(name); ++i) {
          name[i] = tolower(name[i]); 
        }
          file_in >> age; 
          found = tree.find(name);
          
         
      
     
      }
     initialize(name, age); 
   }

   //code goes here
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;


return 0; 

}


