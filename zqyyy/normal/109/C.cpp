#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
inline bool pd(int x){
	while(x){
		if(x%10!=4 && x%10!=7)return 0;
		x/=10;
	}
	return 1;
}
int n,pa[N],sz[N];
int find(int x){return x^pa[x]?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(x>y)swap(x,y);
	pa[x]=y,sz[y]+=sz[x];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)pa[i]=i,sz[i]=1;
	for(int i=1;i<n;i++){
		int x=read(),y=read();bool flg=pd(read());
		if(!flg)unin(x,y);
	}
	ll ans=1ll*n*(n-1)*(n-2);
	for(int i=1;i<=n;i++)
		if(find(i)==i){
			if(sz[i]>2)ans-=1ll*sz[i]*(sz[i]-1)*(sz[i]-2);
			ans-=1ll*sz[i]*(sz[i]-1)*(n-sz[i])*2;
		}
	return cout<<ans,0;
}