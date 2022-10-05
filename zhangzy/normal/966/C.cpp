#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x, a[101000], now;
queue<ll>q[66];

int main(){
  cin>>n;
  for (int i=n;i--;)
    cin>>x, q[63-__builtin_clzll(x)].push(x);
  for (int i=1;i<=n;++i){
    int pos=0;
    for (;q[pos].empty()||(now>>pos&1);++pos)
      if (pos>60) return puts("No"), 0;
    a[i]=q[pos].front(); q[pos].pop();
    now^=a[i];
  }
  puts("Yes");
  for (int i=1;i<=n;++i) cout<<a[i]<<' ';
}