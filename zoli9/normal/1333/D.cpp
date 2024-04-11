#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
char s[3009];
int n, k;
vector<vi> solution;
int swaps;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1; i<=n; i++)
  {
    cin>>s[i];
  }
  while(1)
  {
    bool done=true;
    vi cur;
    for(int i=1; i<n; i++)
    {
      if(s[i]=='R' && s[i+1]=='L')
      {
        cur.push_back(i);
        done=false;
      }
    }
    if(done) break;
    solution.push_back(cur);
    for(int pos: cur)
    {
      swap(s[pos], s[pos+1]);
      swaps++;
    }
  }
  if(k<solution.size() || k>swaps)
  {
    cout<<-1<<'\n';
    return 0;
  }
  reverse(solution.begin(), solution.end());
  for(int i=(int)(solution.size())-1; i>=0; i--)
  {
    while(k>solution.size() && solution[i].size()>0)
    {
      cout<<1<<" "<<solution[i].back()<<'\n';
      k--;
      solution[i].pop_back();
    }
    if(solution[i].size()==0)
    {
      solution.pop_back();
    }
    else
    {
      for(int j=i; j>=0; j--)
      {
        cout<<solution[j].size();
        for(int z: solution[j]) cout<<" "<<z;
        cout<<'\n';
      }
      return 0;
    }
  }
  return 0;
}