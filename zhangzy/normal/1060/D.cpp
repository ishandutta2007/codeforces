//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n, a[101000], b[101000];
ll ans;

int main(){
  cin>>n;
  for (int i=1;i<=n;++i)
    scanf("%d%d",&a[i],&b[i]);
  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  for (int i=1;i<=n;++i) ans+=max(a[i],b[i]);
  cout<<ans+n<<endl;
}