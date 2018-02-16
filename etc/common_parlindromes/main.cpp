#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

void list_print();

int palindrome_check(char *str);

int main(void){

  char s[50000];
  char t[50000];

  cin >> s;
  cin >> t;

  cout << s << endl;
  cout << t << endl;

  cout << strlen(s) << endl;
  cout << strlen(t) << endl;

  vector<vector<char> > str_data;

  for(int i=0;i<strlen(s);i++){

    /*
    for_each(str_data.begin(),str_data.end(),[](vector<char>& x){
	//x.push_back(s[i]);
	for_each(x.begin(),x.end(),[](char& y){
	    cout << y ;
	  });
	cout << endl;
      });
    vector<char> test(1,s[i]);
    str_data.push_back(test);
    */
  }
  
  return 0;
  
}
