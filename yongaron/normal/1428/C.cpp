#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int ans = 0;
    int c = 0;
    n = s.size();
    int b = 0;
    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'A')
        c++;
      else
      {
          if(c)
          {
            c--;
            ans -= 2;
          }
          else
          {
              b++;
          }
      }
    }
    cout<<n+ans-b+(b%2)<<endl;
  }
  return 0;
}