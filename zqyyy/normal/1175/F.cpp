#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int n,a[N];
vector<int>pos;
ull s[N],sum[N],val[N];
inline ull rnd(){
	return (((ull)rand())<<31ull)+(ull)rand();
}
inline bool check(ll l,ll r){
	return (s[r]^s[l-1])==sum[r-l+1];
}
int main(){
	n=read(),pos.push_back(0),srand(114514);
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==1)pos.push_back(i);
	}
	pos.push_back(n+1);
	for(int i=1;i<=n;i++)val[i]=rnd(),sum[i]=sum[i-1]^val[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]^val[a[i]];
	int ans=pos.size()-2;
	for(int x=1;x<(int)pos.size()-1;x++){
		int mx=1;
		for(int i=pos[x]-1;i>pos[x-1];i--){
			mx=max(mx,a[i]);
			if(i+mx<=pos[x+1])ans+=check(i,i+mx-1);
		}
		mx=1;
		for(int i=pos[x]+1;i<pos[x+1];i++){
			mx=max(mx,a[i]);
			if(i-mx>=pos[x-1])ans+=check(i-mx+1,i);
		}
	}
	return cout<<ans,0;
}