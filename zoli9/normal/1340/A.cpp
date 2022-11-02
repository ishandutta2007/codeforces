#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[100009];
int hol[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    int n;
    while(test--)
    {
      bool ok=true;
      cin>>n;
      for(int i=1; i<=n; i++)
      {
        cin>>a[i];
        hol[a[i]]=i;
      }
      int maxi=n+1;
      int cnt=1;
      while(cnt<=n)
      {
        int maxinext=hol[cnt];
        for(int i=maxinext; i<maxi; i++)
        {
          if(a[i]==cnt)
          {
            cnt++;
          }
          else
          {
            ok=false;
            break;
          }
        }
        if(!ok) break;
        maxi=maxinext;
      }
      if(ok) cout<<"Yes"<<'\n';
      else cout<<"No"<<'\n';
    }


    return 0;
}