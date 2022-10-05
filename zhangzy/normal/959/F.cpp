#include<bits/stdc++.h>
#define N 1<<17
#define F(x) for (int i=1;i<=x;++i)
using namespace std;
vector<int>v,q[N];
int n,m,x,a[N],b[N],c[N],A=1;
int chk(int x){
  for (auto o:v) x=min(x,x^o);
  return x;
}

int main(){
  cin>>n>>m;
  F(n) cin>>a[i];
  F(m) {
    cin>>x>>b[i];
    q[x].push_back(i);
  }
  F(n) {
    chk(a[i])? v.push_back(chk(a[i])),0: A=A*2%1000000007;
    for (auto o:q[i]) c[o]= chk(b[o])? 0: A;
  }
  F(m) printf("%d\n",c[i]);
}