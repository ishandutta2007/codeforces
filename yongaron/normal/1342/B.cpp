#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int t, n;
string s, ans;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>s;
    n = s.size();
    bool same = true;
    for(int i = 0; i < n-1; i++)
      if(s[i] != s[i+1])
        same = false;
    if(same)
    {
      cout<<s<<endl;
      continue;
    }
    for(int i = 0; i < n; i++)
    {
      cout<<"01";
    }
    cout<<endl;
  }
  return 0;
}