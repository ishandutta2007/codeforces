#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __uint128_t lll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=7,mod=1e9+7;
int n,U,p[N][N],a[N][1<<N];
struct hasH{
#define M 700001
#define T 40007
	int s_e,head[M],val[T],nxt[T];
	lll to[T];
	inline void add_e(int x,lll y){
		to[++s_e]=y,val[s_e]=0,nxt[s_e]=head[x],head[x]=s_e;
	}
	vector<lll>vec;
	inline int H(lll x){
		return x%M;
	}
	inline int& operator [](lll v){
		int x=H(v);
		for(int i=head[x];i;i=nxt[i])
			if(to[i]==v)return val[i];
		return add_e(x,v),vec.push_back(v),val[head[x]];
	}
	inline void clear(){
		s_e=0;
		for(lll x:vec)head[H(x)]=0;
		vec.clear();	
	}
#undef M
#undef T
}f[2];
lll trans[N],pw[1<<N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),U=(1<<n)-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			p[i][j]=570000004ll*read()%mod;
	for(int i=0;i<n;i++)
		for(int s=0;s<=U;s++){
			a[i][s]=1;
			for(int j=0;j<n;j++)
				a[i][s]=(ll)a[i][s]*(s>>j&1?p[i][j]:mod+1-p[i][j])%mod;
		}
	pw[0]=1;
	for(int i=1;i<=U;i++)pw[i]=pw[i-1]*2;
	f[0][1]=1;
	for(int i=0,o=1;i<n;i++,o^=1){
		f[o].clear();
		for(lll x:f[o^1].vec){
			int v=f[o^1][x];
			for(int j=0;j<n;j++){
				trans[j]=0;
				for(int s=0;s<=U;s++)
					if(!(s>>j&1) && (x>>s&1))
						trans[j]|=pw[s|1<<j];
			}
			for(int s=0;s<=U;s++){
				lll y=0;
				for(int i=0;i<n;i++)
					if(s>>i&1)y|=trans[i];
				if(y){
					int &V=f[o][y];
					V=(V+(ll)v*a[i][s])%mod;
				}
			}
		}
	}
	printf("%d\n",f[n&1][pw[U]]);
	return 0;
}