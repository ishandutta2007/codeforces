#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, x, y;
vi cnt, cnt2, ans;
vi t;
vi idxs[100009];

int getnewcol()
{
  int res;
  for(res=1; res<=n+1; res++)
  {
    if(cnt[res]==0) return res;
  }
}
    
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n>>x>>y;
    cnt.resize(n+2);
    cnt2.resize(n+2);
    ans.resize(n+1);
    for(int i=1; i<=n+1; i++)
    {
      cnt[i]=0;
      cnt2[i]=0;
      idxs[i].clear();
    }
    t.resize(n+1);
    for(int i=1; i<=n; i++)
    {
      cin>>t[i];
      cnt[t[i]]++;
      idxs[t[i]].push_back(i);
    }
    int newC=getnewcol();
    priority_queue<pii> Q;
    for(int i=1; i<=n+1; i++)
    {
      if(cnt[i]==0) continue;
      Q.push(make_pair(cnt[i], i));
    }
    for(int i=1; i<=x; i++)
    {
      pii maxi=Q.top();
      Q.pop();
      ans[idxs[maxi.second].back()]=maxi.second;
      idxs[maxi.second].pop_back();
      maxi.first--;
      Q.push(maxi);
    }
    vector<pii> r;
    for(int i=1; i<=n+1; i++)
    {
      for(int j: idxs[i])
      {
        r.push_back(make_pair(i, j));
      }
    }
    sort(r.begin(), r.end());
    int extra=r.size();
    int noMatch=0;
    for(int i=0; i<extra; i++)
    {
      ans[r[i].second]=r[(i+extra/2)%extra].first;
      if(ans[r[i].second]==r[i].first)
      {
        noMatch++;
        ans[r[i].second]=newC;
      }
    }
    if(noMatch>n-y)
    {
      cout<<"NO"<<'\n';
      continue;
    }
    if(noMatch<n-y)
    {
      for(int i=1; i<=n; i++)
      {
        if(ans[i]!=t[i] && ans[i]!=newC)
        {
          ans[i]=newC;
          noMatch++;
          if(noMatch==n-y) break;
        }
      }
    }
    cout<<"YES"<<'\n';
    for(int i=1; i<=n; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<'\n';
  }
	return 0;
}