#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10,mod=998244353;
int n,m,a[M],b[M],L[M],R[M],p[M],rp[M]; 
void solve(){
	n=read(); m=read();
	F(i,1,n) a[i]=read(),p[i]=0,L[i]=i-1,R[i]=i+1,rp[a[i]]=i;
	F(i,1,m) b[i]=read(),p[rp[b[i]]]=i;
	int ans=1; 
	F(i,1,m){
		int u=L[rp[b[i]]],v=R[rp[b[i]]];
		int num=(u && p[u]<i)+(v<=n && p[v]<i);
//		cout<<u<<" "<<v<<" "<<num<<"\n"; 
		ans=ans*num%mod;
		if (!ans){
			cout<<"0\n";
			return ; 
		}
		if (u && p[u]<i){
			R[u]=v;
			L[v]=u;
		}
		else{
			R[u]=v;
			L[v]=u;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--) solve();
	return 0;
}