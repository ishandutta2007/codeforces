#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
inline long long	read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
const long long N=2000005;
long long M[N],z,nextt[N],ans,n,m,s1[N],s2[N],rd[N],zs,nedge,son[N],ed[N],vis[N];
inline void aedge(long long a,long long b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;  rd[a]++;
}
inline void dfs(long long p){
	zs++; vis[p]=1;
	for(long long i=son[p];i;i=nextt[i])if(!vis[ed[i]])dfs(ed[i]);
}
int main(){
	n=read(); m=read(); if(m==1){
		puts("0"); return 0;
	}
	for(long long i=1;i<=m;i++){
		s1[i]=read(); s2[i]=read(); M[s1[i]]=1; M[s2[i]]=1;if(s1[i]==s2[i]){z++;continue;}
		
		aedge(s1[i],s2[i]); aedge(s2[i],s1[i]); 
	}
	int zzz=0;
	for(int i=1;i<=n;i++)zzz+=M[i]; //cout<<zzz<<endl;
	for(int i=1;i<=n;i++)if(M[i]){dfs(i); break;}
	if(zs!=zzz){
		cout<<0<<endl; return 0;
	}
	for(long long i=1;i<=m;i++){
		if(s1[i]!=s2[i])ans+=rd[s1[i]]-1+rd[s2[i]]-1;
	}
	cout<<ans/2+z*(m-z)+z*(z-1)/2<<endl;
}