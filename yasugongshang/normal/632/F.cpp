#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
#define ld long double
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
const int N=2505;
int n,vis[N],a[N][N],dist[N],dep[N],fa[N];
void GG(int x,int y,int z){
	puts("NOT MAGIC"); exit(0);
}
int getdep(int x){
	if(x==0)return 0;
	if(dep[x])return dep[x];
	else return dep[x]=getdep(fa[x])+1;
}
void check(int x,int y,int z){
	if(a[x][y]>a[x][z]&&a[x][y]>a[y][z])GG(x,y,z);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(a[i][j]>a[k][i]&&a[i][j]>a[k][j])GG(i,j,k);
	for(int i=1;i<=n;i++){
		if(a[i][i]!=0){
			GG(i,0,0);
		}
		for(int j=1;j<=n;j++)if(a[i][j]!=a[j][i])GG(i,j,0);
	}
	for(int i=2;i<=n;i++)dist[i]=a[fa[i]=1][i];
	vis[1]=1;
	for(int i=1;i<n;i++){
		int k=0;
		for(int j=1;j<=n;j++)if(!vis[j]&&(k==0||dist[j]<dist[k]))k=j;
		vis[k]=1; 
		for(int j=1;j<=n;j++)if(!vis[j]&&a[k][j]<dist[j]){dist[j]=a[k][j]; fa[j]=k;}
	}
	for(int i=1;i<=n;i++)getdep(i); //cout<<solve(429,787)<<" "<<fa[787]<<" "<<fa[884]<<" "<<a[429][787]<<" "<<a[429][884]<<" "<<a[884][787]<<endl;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(dep[i]>dep[j])check(i,j,fa[i]);
		else check(i,j,fa[j]);
	}
	puts("MAGIC");
}
/*
max()
=a[i][j]
 

0 6 6 6
 0 3 5
  0 4
   0

1
24
234 
 

429 787 884
*/