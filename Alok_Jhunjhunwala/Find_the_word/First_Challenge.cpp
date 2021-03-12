#include<bits/stdc++.h>
using namespace std;
void search_word() 
{ 
  
    ifstream ip("EnglishDictionary.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string name;
  string frequency;
	
	string word;
	cin>>word;
	map<string,string> m;
  while(ip.good()){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	
    getline(ip,name,',');
    getline(ip,frequency,'\n');
    
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	m[name]=frequency;
	
	
  }
  

  ip.close();
	if(m.find(word)!=m.end()){
		cout<<"YES,"<<m[word];
	}
	else{
		cout<<"NO";
	}
} 


int main()
{
	search_word();
}
