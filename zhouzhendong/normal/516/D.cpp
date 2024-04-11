#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005;
int n;
LL L;
vector <pair <int,int> > e[N];
int ax,ay;
int p[N];
LL dis[N],dx[N],dy[N],md[N];
int findfar(int x,int pre,LL d){
	dis[x]=d;
	int res=x;
	for (auto E : e[x])
		if (E.fi!=pre){
			int tmp=findfar(E.fi,x,d+E.se);
			if (dis[tmp]>dis[res])
				res=tmp;
		}
	return res;
}
int fa[N],size[N],vis[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Solve(){
	For(i,1,n)
		fa[i]=i,size[i]=1,vis[i]=0;
	int ans=1;
	for (int i=1,j=1;i<=n;i++){
		while (j<i&&md[p[j]]-md[p[i]]>L){
			size[getf(p[j])]--;
			vis[p[j]]=-1;
			j++;
		}
		int x=p[i];
		for (auto E : e[x])
			if (vis[E.fi]==1){
				fa[E.fi]=x;
				size[x]+=size[E.fi];
			}
		vis[x]=1;
		ans=max(ans,size[x]);
	}
	printf("%d\n",ans);
}
bool cmp(int a,int b){
	return md[a]>md[b];
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read(),z=read();
		e[x].pb(mp(y,z));
		e[y].pb(mp(x,z));
	}
	ax=findfar(1,0,0),ay=findfar(ax,0,0);
	For(i,1,n)
		dx[i]=dis[i];
	findfar(ay,0,0);
	For(i,1,n)
		dy[i]=dis[i],md[i]=max(dx[i],dy[i]);
	For(i,1,n)
		p[i]=i;
	sort(p+1,p+n+1,cmp);
	int q=read();
	while (q--){
		L=read();
		Solve();
	}
	return 0;
}