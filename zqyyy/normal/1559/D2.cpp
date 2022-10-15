#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+7;
int pa[N<<1];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int n,m1,m2;
vector<pii>res;
int main(){
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=n+n;i++)pa[i]=i;
	for(int i=1;i<=m1;i++){
		int x=read(),y=read();
		pa[find(x)]=find(y);
	}
	for(int i=1;i<=m2;i++){
		int x=read(),y=read();
		pa[find(x+n)]=find(y+n);
	}
	int ans=n-1-max(m1,m2);
	printf("%d\n",ans);
	for(int i=2;i<=n;i++){
		if(find(1)==find(i) || find(n+1)==find(i+n))continue;
		res.emplace_back(1,i),pa[find(1)]=find(i),pa[find(n+1)]=find(i+n),ans--;
	}
	for(int i=2,j=2;ans;i++){
		if(find(1)==find(i))continue;
		while(find(n+1)==find(n+j))j++;
		res.emplace_back(i,j),pa[find(j)]=find(i),pa[find(n+j)]=find(i+n),ans--;
	}
	for(auto i:res)printf("%d %d\n",i.fi,i.se);
	return 0;
}