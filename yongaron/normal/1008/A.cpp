#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

string s;

int main(int argc, char const *argv[]) {
  cin>>s;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n')
    {
      if(i == s.size()-1 || (s[i+1] != 'a' && s[i+1] != 'e' && s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u'))
      {
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}