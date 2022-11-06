#include<stdio.h>
#define lim 1000000
int a[1000002][2],n,m,f[2000002],s[2000002];
char c[1000002];
int ans;
inline int gf(int p){return f[p]==p?p:(f[p]=gf(f[p]));}
inline int Min(int p,int q){return p<q?p:q;}
inline void add(int p,int q,bool typ){
	p=gf(p);q=gf(q);
	if(p>=lim)p-=lim,typ=!typ;
	if(q>=lim)q-=lim,typ=!typ;
	if(p==q)return;
	ans-=Min(s[p],s[p+lim])+Min(s[q],s[q+lim]);
	if(typ){
		f[q]=p;s[p]+=s[q];
		f[q+lim]=p+lim;s[p+lim]+=s[q+lim];
	}else{
		f[q+lim]=p;s[p]+=s[q+lim];
		f[q]=p+lim;s[p+lim]+=s[q];
	}ans+=Min(s[p],s[p+lim]);
}
int main(){
	scanf("%d%d%s",&m,&n,c+1);
	for(int i=1;i<=2000000;i++)f[i]=i;
	for(int i=1;i<=n;i++)s[i]=1,s[i+lim]=0;
	s[0]=lim;s[lim]=-lim;ans=-lim;
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		while(k--){
			int p;scanf("%d",&p);
			if(a[p][0])a[p][1]=i;
			else a[p][0]=i;
		}
	}for(int i=1;i<=m;i++){
		if(a[i][0])add(a[i][0],a[i][1],c[i]=='1');
		printf("%d\n",ans+lim);
	}
}