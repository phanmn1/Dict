#include <iostream> 
#include <fstream> 
#include <string.h> 
#include <fstream>

using namespace std; 
const int ALSIZE = 26; 

struct TrieNode {

  TrieNode(char a); 
  char letter; 
  TrieNode *links [ALSIZE]; //array of 26 TrieNode pointers 
  bool fullWord;
  int value; 
 
}; 

TrieNode::TrieNode(char a) {
  letter = a; 
  for (int i = 0; i < ALSIZE; ++i) {
    links[i] = NULL; 
  }
  fullWord = false; 
  value = 0; 
}

class PrefixTree {
public: 
  PrefixTree (); 
  //  TrieNode createTree (); 
  void insertWord( char Word[], int a); 
  bool find ( char Word[]);
  void printTree (TrieNode *root, int level, char branch []);   
private: 
  TrieNode* root; 
 
}; 

PrefixTree::PrefixTree(){root = new TrieNode('\0');}
//TrieNode PrefixTree::createTree () {} 

void PrefixTree::insertWord (char Word[], int number) {
  int offset = 97;  //offset for ascii value of characters 
  int length = strlen(Word); 
  char *letters = new char [length + 1];  
  strcpy (letters, Word); 
  TrieNode* currentNode = root; 
  for (int i = 0; i < length; ++i) {
    if (currentNode->links[letters[i] - offset]  == NULL)
      currentNode->links[letters[i] - offset] = new TrieNode(letters[i]); //if current  
    currentNode = currentNode->links[letters[i] - offset]; 
  }

  currentNode->fullWord = true; 
  currentNode->value = number; 
  cout <<currentNode->fullWord<<endl; 
  cout <<currentNode->value<<endl; 
} 

bool PrefixTree:: find (char Word[]) {
  int length = strlen(Word); 
  char * letters = new char[length + 1];
  strcpy(letters, Word); 
  int offset = 97; 
  TrieNode* currentNode = root; 
  int i; 
  for (i = 0; i < length; ++i) {
    if (currentNode == NULL){
      cout <<"Root node is null"<<endl; 
      return false; 
       }
    cout <<currentNode -> links[letters[i] - offset]->letter; 
    currentNode = currentNode->links[letters[i] - offset];
     
  }

  if (i == length && currentNode == NULL) {
    cout <<"Length == i && currentNode->fullWord)" <<endl; 
    return false; 
  }
  if (currentNode != NULL && !currentNode->fullWord) {
    cout<<"currentNode != NULL && !currentNode->fullWord)" <<endl; 
    return false; 
  }
  return true; 


}

void initialize (char name[], int &age) {
  name[0] = '\0'; 
  age = 0; 
}



int main () {


  ifstream file_in;  //reading from files
  file_in.open("test.txt");  

  PrefixTree tree; 
  char s1 [200] = "testfile"; 
  char name[200];  
  int age; 
  initialize(name, age);  
 
  if (file_in) {
    while (file_in >> name && !file_in.eof()) {

	//file_in >> array[i].name; 
        file_in >> age;
        
      	cout <<"Name: " << name <<endl; 
	cout <<"Age:" << age << endl; 
        tree.insertWord(name, age);

                                     }
  }
 
       
 
 
 
  if( tree.find(s1)) 
   cout <<"Found" <<endl;
  else 
    cout <<"Not found"<<endl;   


return 0;

}
