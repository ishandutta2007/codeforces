#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

vi ans;
ll c[100009];
ll kums[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    ll sum=0;
    bool ok=true;
    for(int i=1; i<=m; i++)
    {
      cin>>c[i];
      sum+=c[i];
    }
    if(sum<n)
    {
      cout<<-1<<endl;
      return 0;
    }
    kums[m+1]=0;
    for(int i=m; i>=1; i--)
    {
      kums[i]=kums[i+1]+c[i];
    }
    ll cnt=1;
    for(int i=1; i<=m; i++)
    {
      if(cnt+c[i]-1>n)
      {
        cout<<-1<<endl;
        return 0;
      }
      ll newcnt=cnt+1;
      if(newcnt+kums[i+1]-1<n)
      {
        newcnt=n-kums[i+1]+1;
        ans.push_back(max(cnt, newcnt-c[i]));
      }
      else
      {
        ans.push_back(cnt);
      }
      cnt=newcnt;
    }
    for(int i: ans)
    {
      cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}