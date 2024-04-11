#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct que{
	int x,y,t;
}a[N],b[N*4];
int p[N*2],fa[N*2];
int co[N*2],n,m,cnt;
bool cmp(que a,que b){
	return a.t<b.t;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
		p[++*p]=a[i].x; p[++*p]=a[i].y;
	}
	sort(p+1,p+*p+1);
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=(*p)+1;i++) fa[i]=i,co[i]=-1;
	for (int i=1;i<=m;i++){
		int x=lower_bound(p+1,p+*p+1,a[i].x)-p;
		int y=lower_bound(p+1,p+*p+1,a[i].y)-p-1;
		for (x=get(x);x<=y;x=fa[x]=get(x+1))
			co[x]=a[i].t; 
	}
	for (int i=1;i<=*p;i++)
		if (co[i]!=-1){
			b[++cnt]=(que){1,0,co[i]-p[i+1]};
			b[++cnt]=(que){-1,0,co[i]-p[i]};
		}
	sort(b+1,b+cnt+1,cmp);
	int l=1,ans=0,K=0;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (;l<=cnt&&x>=b[l].t;l++)
			ans+=K*(b[l].t-b[l-1].t),K+=b[l].x;
		printf("%d\n",ans+K*(x-b[l-1].t));
	}
}