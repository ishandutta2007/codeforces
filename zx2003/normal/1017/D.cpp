#include<bits/stdc++.h>
const int N=15,S=4099,Q=500005;
int su[S],w[N],id[S],i,j,k,x,f[S],aa[S],ans[Q],n,m,q;
char c[N];
struct query{
	int id,s,f;
	bool operator<(const query&rhs)const{return f<rhs.f;}
}qu[Q];
bool cmp(int x,int y){
	return su[x]<su[y];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;++i)scanf("%d",w+i);
	for(i=1;i<=m;++i){
		scanf("%s",c+1);x=0;
		for(j=1;j<=n;++j)x=x<<1|(c[j]-'0');++aa[x];
	}
	int all=1<<n;
	for(i=0;i<all;++i){
		for(j=0;j<n;++j)if(!(i>>j&1))su[i]+=w[n-1-j];
		id[i]=i;
	}
	std::sort(id+1,id+all+1,cmp);
	for(i=1;i<=q;++i){
		scanf("%s%d",c+1,&qu[i].f);x=0;
		for(j=1;j<=n;++j)x=x<<1|(c[j]-48);
		qu[i].id=i;qu[i].s=x;
	}
	std::sort(qu+1,qu+q+1);
	j=1;
	for(i=1;i<=q;++i){
		for(;j<=all && su[id[j]]<=qu[i].f;++j){
			x=id[j];
			for(k=0;k<all;++k)f[k^x]+=aa[k];
		}
		ans[qu[i].id]=f[qu[i].s];
	}
	for(i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}