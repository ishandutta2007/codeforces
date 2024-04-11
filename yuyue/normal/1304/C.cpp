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
const int M=555;
int dp[M][M+M];
struct node{
	LL l,r;
};
LL T[M],L[M],R[M];
int n,m;
void work(){
	n=read(); m=read();
	F(i,1,n){
		int t=read(),l=read(),r=read();
		T[i]=t; L[i]=l; R[i]=r;
	}
	node now=(node){m,m};
	F(i,1,n){
		int del=T[i]-T[i-1];
	
		now.l-=del; now.r+=del;
		now.l=max(L[i],now.l);
		now.r=min(R[i],now.r);	
		if (now.r<now.l){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
int main(){
	int T=read(); 
	while (T--) work();
	return 0;
}