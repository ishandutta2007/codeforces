#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int t;
string st;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>st;
    int r, p, s;
    r = p = s = 0;
    for(int i = 0; i < st.size(); i++)
    {
      if(st[i] == 'R')
        p++;
      if(st[i] == 'P')
        s++;
      if(st[i] == 'S')
        r++;
    }
    char c = 'S';
    if(p >= s && p >= r)
      c = 'P';
    else if(r > s)
      c = 'R';
    for(int i = 0; i < st.size(); i++)
      cout<<c;
    cout<<endl;
  }
  return 0;
}