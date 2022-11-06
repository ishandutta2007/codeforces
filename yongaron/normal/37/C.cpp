#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
pair<int, int> l[1234];
string ans[1234];
int c = 0;

void dfs(string s)
{
  if(c >= n)
    return;
  if(s.size() == l[c].first)
  {
    ans[l[c++].second] = s;
    return;
  }
  dfs(s+'0');
  dfs(s+'1');
}

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>l[i].first;
    l[i].second = i;
  }
  sort(l, l+n);
  dfs("");
  if(ans[l[n-1].second].size())
  {
    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++)
      cout<<ans[i]<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}