#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
string s, r;

bool possible()
{
  int is = 0, ir = 0;
  while(is < s.size() && ir < r.size())
  {

    if(s[is] != r[ir])
      return false;
    int ss = 0;
    while(is < s.size()-1 && s[is] == s[is+1])
    {
      is++;
      ss++;
    }
    int rr = 0;
    while(ir < r.size()-1 && r[ir] == r[ir+1])
    {
      ir++;
      rr++;
    }
    if(ss > rr)
      return false;
    is++;
    ir++;
  }
  if(is < s.size() || ir < r.size())
    return false;
  return true;
}

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>s>>r;
    if(possible())
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}