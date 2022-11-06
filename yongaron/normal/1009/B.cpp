#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

string s;
vector<char> v;

int main(int argc, char const *argv[]) {
  cin>>s;
  int n = s.size();
  int c = 0;
  int z = 0, o = 0, t = 0;
  int zt = 0;
  int st;
  for(int i = 0; i < n; i++)
  {
    if(s[i] == '1')
      o++;
    else if(s[i] == '0')
      z++;
    else if(s[i] == '2')
    {
      if(t == 0)
        st = i;
      t++;
    }
    if(s[i] == '0' && t == 0)
      zt++;
  }
  for(int i = 0; i < zt; i++)
    cout<<'0';
  for(int i = 0; i < o; i++)
    cout<<'1';
  for(int i = st; i < n; i++)
  {
    if(s[i] == '0')
      cout<<'0';
    else if(s[i] == '2')
      cout<<'2';
  }
  return 0;
}