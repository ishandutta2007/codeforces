#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int pa[N];
int find(int x){return x^pa[x]?pa[x]=find(pa[x]):x;}
int n,m,L[N],R[N];
ll s1[N],s2[N];
bool flg[N];
vector<int>vec[N];
inline void clear(){
	for(int i=0;i<=n;i++)vec[i].clear(),flg[i]=0;
}
inline void work(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)s1[i]=s1[i-1]+read();
	for(int i=1;i<=n;i++)s2[i]=s2[i-1]+read();
	iota(pa,pa+n+2,0);
	for(int i=1;i<=m;i++){
		L[i]=read()-1,R[i]=read();
		vec[L[i]].push_back(i);
		vec[R[i]].push_back(i);
	}
	queue<int>q;
	for(int i=0;i<=n;i++)
		if(s1[i]==s2[i])q.push(i),pa[i]=i+1,flg[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i:vec[x]){
			int y=L[i]^R[i]^x;
			if(!flg[y])continue;
			int l=x;
			if(l>y)swap(l,y);
			for(int j=find(l);j<=y;j=find(j))
				pa[j]=j+1,q.push(j),flg[j]=1;
		}
	}
	puts(count(flg,flg+n+1,1)==n+1?"Yes":"No");
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work(),clear();
	return 0;
}