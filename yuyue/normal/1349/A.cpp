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
const int M=2e5+10;
int n,a[M];
vector<int> p[M];
int main(){
	n=read();
	int mx=0;
	F(i,1,n){
		a[i]=read();
		int x=a[i];
		for (int j=2;j*j<=x;j++){
			if (x%j==0){
				int ct=0;
				while (x%j==0) x/=j,ct++; 
				p[j].pb(ct);
//				cout<<j<<" <- "<<ct<<"  ? \n"; 
			}
		}
		if (x>1){
			p[x].pb(1);
		}
		mx=max(mx,a[i]);
	}
	LL tmp=1;
	F(i,2,mx){
		if (SZ(p[i])+1<=n-2) continue;
		if (SZ(p[i])+1==n-1) p[i].pb(0);
		sort(p[i].begin(),p[i].end());
		int z=p[i][1];
		F(j,1,z) tmp=tmp*i;
	}
	cout<<tmp<<"\n";
	return 0;
}