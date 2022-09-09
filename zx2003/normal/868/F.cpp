//#pragma GCC optimize("O2") 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=100005;
int n,k,i,a[N],cnt[N],u,v;
ll s,f[N],g[N];
inline void work(int l,int r){
	while(u>l)s+=cnt[a[--u]]++;
	while(v<r)
		s+=cnt[a[++v]]++;
	while(u<l)
		s-=--cnt[a[u++]];
	while(v>r)
		s-=--cnt[a[v--]];
}
void solve(int l,int r,int x,int y){
	register int i,m=(x+y)>>1,j=m<r?m:r;
	for(i=j;i>=l;--i){
		work(i,m);
		if(f[i-1]+s<g[m])j=i,g[m]=f[i-1]+s;
	}
	if(x<m && l<=j)solve(l,j,x,m-1);
	if(m<y && j<=r)solve(j,r,m+1,y);
}
int main(){
	//freopen("f.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		s+=cnt[a[i]]++;
		f[i]=g[i]=s;
	}
	memset(cnt+1,0,n<<2);
	for(i=2;i<=k;++i){
		s=0;u=v=cnt[a[1]]=1;solve(1,n,1,n);
		memcpy(f+1,g+1,n<<3);memset(cnt+1,0,n<<2);
	}
	cout<<f[n]<<endl;
	return 0;
}