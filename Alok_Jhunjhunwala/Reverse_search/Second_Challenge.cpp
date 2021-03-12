#include <bits/stdc++.h> 
using namespace std; 

// Structure for Trie 

struct Trie { 
	bool isEndOfName; 
	map<char, Trie*> m; 
	string frequency; 
}; 


// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfName = false; 
	return node; 
} 


// Function to insert a name with its frequency
// in the dictionary built using a Trie 


void insert(Trie*& root, const string& name, 
			const string& frequency) 
{ 

	// If root is null 
	if (root == NULL) 
		root = getNewTrieNode(); 

	Trie* temp = root; 

	for (int i = 0; i < name.length(); i++) { 
		char x = name[i]; 
		if (temp->m.find(x) == temp->m.end()) 
			temp->m[x] = getNewTrieNode(); 

		temp = temp->m[x]; 
	} 
 
	temp->isEndOfName = true; 
	temp->frequency = frequency; 
} 


 
string getFrequency(Trie* root, const string& name) 
{ 

	// If root is null i.e. the dictionary is empty 
	if (root == NULL) 
		return "-1"; 

	Trie* temp = root; 

	for (int i = 0; i < name.length(); i++) { 
		temp = temp->m[name[i]]; 
		if (temp == NULL) 
			return "-1"; 
	} 

 
	if (temp->isEndOfName) 
		return temp->frequency; 
	return "-1"; 
} 

// Main function
 
int main() 
{ 
	Trie* root = NULL; 

 ifstream ip("EnglishDictionary.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string name;
  string frequency;
	
  while(ip.good()){
	
    getline(ip,name,',');
    getline(ip,frequency,'\n');
    
	insert(root,name,frequency);
  }
  

  ip.close();
	
	
	string str ;
	cin>>str; 
	cout << getMarks(root, str); 

	return 0; 
}
