#include<bits/stdc++.h>
using namespace std;
#define I 2*k
#define J 2*k+1
#define d (l+r)/2
const int N=2e6;
int n,m,x,y,u[N],v[N],f[N],g[N],A[N],h[N];
string s;
void F(int k,int x){
	h[k]+=x,u[k]+=x,v[k]+=x,f[k]-=x,g[k]-=x;
}
void U(int k){
	F(I,h[k]),F(J,h[k]),h[k]=0;
}
void V(int k){
	u[k]=max(u[I],u[J]),v[k]=min(v[I],v[J]),f[k]=max({f[I],f[J],u[J]-2*v[I]}),g[k]=max({g[I],g[J],u[I]-2*v[J]}),A[k]=max({A[I],A[J],g[I]+u[J],f[J]+u[I]});
}
void C(int k,int l,int r,int L,int R,int x){
	if(L<=l&&r<=R){
		F(k,x);
		return;
	}
	U(k);
	if(L<=d)
		C(I,l,d,L,R,x);
	if(R>d)
		C(J,d+1,r,L,R,x);
	V(k);
}
int main(){
	cin>>n>>m>>s,s=' '+s,n=2*n-2;
	for(int i=1;i<=n;i++)
		C(1,1,n,i,n,s[i]=='('?1:-1);
	cout<<A[1]<<'\n';
	for(;cin>>x>>y;){
		C(1,1,n,x,n,s[x]=='('?-2:2),C(1,1,n,y,n,s[y]=='('?-2:2),swap(s[x],s[y]);
		cout<<A[1]<<'\n';
	}
}