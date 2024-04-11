#include<bits/stdc++.h>
#define maxn 30010
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
vector<int>ga[maxn],gb[maxn];
pii a[maxn],b[maxn];
int n,m,lx[maxn<<1],tx,ty,ly[maxn<<1];
char s[2][maxn],s1[2][maxn],s2[2][maxn];
int v[maxn<<1],f[maxn<<1],g[2][maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
//	freopen("a4.in","r",stdin);
int x1,y1,x2,y2;
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].xx,&a[i].yy),
		lx[++tx]=a[i].xx,ly[++ty]=a[i].yy;
	b[++m]=pii(x1,y1);
	b[++m]=pii(x1,y2);
	b[++m]=pii(x2,y1);
	b[++m]=pii(x2,y2);
	for(int i=1;i<=m;++i)
//		scanf("%d%d",&b[i].xx,&b[i].yy),
		lx[++tx]=b[i].xx,ly[++ty]=b[i].yy;
	sort(lx+1,lx+tx+1),tx=unique(lx+1,lx+tx+1)-lx-1;
	sort(ly+1,ly+ty+1),ty=unique(ly+1,ly+ty+1)-ly-1;
	for(int i=1;i<=n;++i){
		int x=lower_bound(lx+1,lx+tx+1,a[i].xx)-lx;
		int y=lower_bound(ly+1,ly+ty+1,a[i].yy)-ly;
		ga[x-1].push_back(y);
	}
	for(int i=1;i<=m;++i){
		int x=lower_bound(lx+1,lx+tx+1,b[i].xx)-lx;
		int y=lower_bound(ly+1,ly+ty+1,b[i].yy)-ly;
		gb[x-1].push_back(y);
	}
	int p=0,np=1,ans=0;
	for(int i=1;i<=ty;++i)g[np][i]=i;
	for(int i=tx;i>=1;--i,swap(p,np)){
		for(int j=1;j<=ty;++j)s[p][j]=s1[p][j]=0;
		for(auto x:ga[i])s[p][x]^=1;
		for(auto x:gb[i])s1[p][x]^=1;
		for(int j=1;j<=ty;++j){
			s[p][j]^=s[np][j]^s[p][j-1]^s[np][j-1];
			s1[p][j]^=s1[np][j]^s1[p][j-1]^s1[np][j-1];
			s2[p][j]=s[p][j]&s1[p][j];
			ans+=s2[p][j];
//			printf("{%d}",s2[p][j]);
		}
//		puts("");
		for(int j=1;j<=ty*2;++j)f[j]=j,v[j]=0;
		for(int j=1;j<=ty;++j){
			if(s2[p][j]==1)
				f[j]=(j!=1&&s2[p][j]==s2[p][j-1]?ans--,f[j-1]:j);
			if(s2[np][j]==1)
				g[np][j]+=ty;
		}
		for(int j=1;j<=ty;++j)if(s2[np][j]==1&&s2[p][j]==1){
//			printf("[%d,%d(%d)]",f[j+ty],find(j+ty),g[np][j]);
			int x=find(g[np][j]),y=find(j);
//			printf("{%d,%d}",x,y);
			if(x!=y)ans--,f[x]=y;
		}
		int tp=0;
		for(int j=1;j<=ty;++j)if(s2[p][j]==1){
			int x=find(j);
			if(!v[x])g[p][j]=++tp,v[x]=tp;
			else g[p][j]=v[x];
		}
//		for(int j=1;j<=ty;++j)
//			printf("[%d]",s2[p][j]?g[p][j]:0);puts("");
	}
	printf("%d",ans);

}