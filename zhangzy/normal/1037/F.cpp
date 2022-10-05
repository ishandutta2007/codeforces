#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7, N=1e6+7;

set<int>S;
set<int>::iterator it;
pair<int,int>p[N];
#define fi first
#define se second
int n, a[N], k, f[N];

int main(){
  cin>>n>>k;
  for (int i=1;i<=n;++i){
    scanf("%d",&p[i].fi), p[i].se=i;
    f[i]= i<k? 0: (f[i-k+1]+i-k+1)%mod;
  }
  sort(p+1,p+n+1);
  S.insert(0), S.insert(n+1);
  ll ans=0;
  for (int i=n;i;--i){
    int w=p[i].se, l, r;
    r=*(it=S.lower_bound(w));
    l=*--it; S.insert(w);
    ans+=(f[r-l-1]-f[r-w-1]-f[w-l-1])*(ll)p[i].fi%mod;
  }
  cout<<(ans%mod+mod)%mod;
}