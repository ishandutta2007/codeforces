#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;
string s;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    cin>>s;
    int c = 1;
    int ans = 0;
    int first;
    for(int i = 1; i < s.size(); i++)
    {
      if(s[i] == s[i-1])
        c++;
      else
      {
        if(c == i)
        {
          first = c;
        }
        else
          ans += c/3;
        c = 1;
      }
    }
    if(c == s.size())
    {
      int ans = n/3;
      if(n%3)
        ans++;
      cout<<ans<<endl;
      continue;
    }
    if(s[0] == s[n-1])
    {
      ans += (first+c)/3;
    }
    else
    {
      ans += first/3;
      ans += c/3;
    }
    cout<<ans<<endl;
  }
  return 0;
}