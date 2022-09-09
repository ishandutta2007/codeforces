#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,i,x,y,l,r,m;
vector<int>ee[N],e[N];
int dcnt,id[N];
void dfs(int x,int fa){
	id[x]=++dcnt;
	for(int y:ee[x])if(y!=fa)dfs(y,x),e[id[x]].push_back(id[y]);
}
int f1[N],f2[N];
inline int calc(int k){
	int i;
	for(i=n;i;--i){
		int v1=0,v2=0,s=0;
		for(int j:e[i]){
			s+=f2[j];
			if(f1[j]>=v1)v2=v1,v1=f1[j];else v2=max(v2,f1[j]);
		}
		if(v1+v2+1>=k)f1[i]=0,f2[i]=s+1;else f1[i]=v1+1,f2[i]=s;
	}
	return f2[1];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),ee[x].push_back(y),ee[y].push_back(x);
	dfs(1,0);
	int mm=sqrt(n);
	for(i=1;i<=mm;++i)printf("%d\n",calc(i));
	for(i=mm+1;i<=n;){
		int vv=calc(i);
		for(l=i,r=n;l<r;){m=l+r+1>>1;if(calc(m)==vv)l=m;else r=m-1;}
		for(;i<=l;++i)printf("%d\n",vv);
	}
	return 0;
}