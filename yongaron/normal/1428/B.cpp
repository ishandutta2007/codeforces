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
    cin>>n>>s;
    bool left = false;
    bool right = false;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
      if(s[i] == '<')
        left = true;
      if(s[i] == '>')
        right = true;
      if(i < n-1 && (s[i] == '-' || s[i+1] == '-'))
        ans++;  
    }
    if(s[0] == '-' || s[n-1] == '-')
      ans++;
    if(!left || !right)
      cout<<n<<endl;
    else
      cout<<ans<<endl;
  }
  return 0;
}