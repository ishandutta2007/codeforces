#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      int n;
      cin>>n;
      vi a(n);
      bool same=true;
      for(int i=0; i<n; i++)
      {
        cin>>a[i];
        if(i>0 && a[i]!=a[i-1]) same=false;
      }
      if(same)
      {
        cout<<0<<'\n';
        continue;
      }
      int bestans=n-1;
      for(int fi=1; fi<n; fi++)
      {
        int sum=0;
        for(int i=0; i<fi; i++) sum+=a[i];
        int cans=fi-1;
        int cur=0;
        bool ok=true;
        for(int i=fi; i<n; i++)
        {
          if(cur+a[i]==sum)
          {
            if(cur>0) cans++;
            cur=0;
          }
          else if(cur+a[i]>sum)
          {
            ok=false;
            break;
          }
          else
          {
            if(cur>0) cans++;
            cur+=a[i];
          }
        }
        if(cur>0) ok=false;
        if(ok && cans<bestans)
        {
          //cout<<fi<<"*"<<endl;
          bestans=cans;
        }
      }
      cout<<bestans<<'\n';
    }
    return 0;
}