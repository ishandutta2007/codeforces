#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int mini[5009][5009];
vi a;

int calc(int l, int r, int depth)
{
    if(l>r) return 0;
    if(l==r)
    {
      if(depth==a[l]) return 0;
      return 1;
    }
    int res=r-l+1;
    int middle=mini[l][r];
    int cres=a[middle]-depth;
    cres+=calc(l, middle-1, a[middle]);
    cres+=calc(middle+1, r, a[middle]);
    res=min(res, cres);
    //cout<<l<<" "<<r<<" : "<<depth<<" ::: "<<res<<endl;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
      int n;
      cin>>n;
      a.resize(n+1);
      for(int i=1; i<=n; i++)
      {
        cin>>a[i];
        a[i]=min(a[i], n);
        mini[i][i]=i;
      }
      for(int i=1; i<=n; i++)
      {
        for(int j=i+1; j<=n; j++)
        {
          mini[i][j]=mini[i][j-1];
          if(a[j]<a[mini[i][j]]) mini[i][j]=j;
        }
      }
      cout<<calc(1, n, 0)<<'\n';
    


    return 0;
}