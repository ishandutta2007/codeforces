#include<set>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 300100
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,int> par;
typedef pair<int,int> par2;
par p[maxn];
set<par2>st;
int n,m,d[maxn],bel[maxn];
int fr[maxn],f[maxn],to[maxn],tp,tp2;
int ptr[maxn],a[maxn],b[maxn];
ull h[maxn]={1};
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)h[i]=h[i-1]*19260817;
	for(int i=1;i<=n;++i)p[i]=par(h[i],i);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),p[u].first=p[u].first+h[v],fr[i]=u,
		to[i]=v,p[v].first=p[v].first+h[u];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		if(p[i].first!=p[i-1].first)bel[p[i].second]=p[i].second,tp++;
		else bel[p[i].second]=bel[p[i-1].second];
	}
//	for(int i=1;i<=n;++i)printf("[%d]",bel[i]);
	for(int i=1;i<=m;++i)if(bel[fr[i]]!=bel[to[i]]){
		int x=bel[fr[i]],y=bel[to[i]];
		if(x>y)swap(x,y);
		if(!st.count(par2(x,y)))
			d[x]++,d[y]++,st.insert(par2(x,y)),(ptr[x]==0?a[x]=y,ptr[x]++:b[x]=y),
			(ptr[y]==0?a[y]=x,ptr[y]++:b[y]=x);//,printf("<%d,%d>",x,y);
	}
	if(st.size()>=tp)return printf("NO"),0;
	for(int i=1;i<=n;++i)if(i==bel[i]&&d[i]>=3)return printf("NO"),0;
//	for(int i=1;i<=n;++i)printf("{%d,%d}",fr[i],to[i]);
	for(int i=1;i<=n;++i)if(i==bel[i]&&d[i]<=1){
//		printf("<%d>")
		for(int j=i,k=1,lst=0;j;j=(b[j]==lst?a[lst=j]:b[lst=j]))
			f[j]=k++;
		break;
	}
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d ",f[bel[i]]);
}