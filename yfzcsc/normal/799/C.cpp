#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 100100
using namespace std;
typedef pair<int,int> par;
int n,c,d,nc,nd,mxc,mxd,ac,ad,t[maxn];
par C[maxn],D[maxn];
void add(int x,int a){
	for(;x<=max(c,d);x+=x&-x)
		t[x]=max(t[x],a);
}
int query(int x){
	int ans=0;
	for(;x;x-=x&-x)
		ans=max(ans,t[x]);
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&c,&d);
	for(int i=1;i<=n;++i){
		int a,b;char c[2];
		scanf("%d%d%s",&a,&b,c);
		if(c[0]=='C')C[++nc]=par(b,a);
		else D[++nd]=par(b,a);
	}
	sort(C+1,C+nc+1);
	sort(D+1,D+nd+1);
	for(int i=1;i<=nc;++i)if(C[i].first<=c){
		int z=query(c-C[i].first);
		if(z)ac=max(ac,z+C[i].second);
		mxc=max(mxc,C[i].second);
		add(C[i].first,C[i].second);
	}
	memset(t,0,sizeof(t));
	for(int i=1;i<=nd;++i)if(D[i].first<=d){
		int z=query(d-D[i].first);
		if(z)ad=max(ad,z+D[i].second);
		mxd=max(mxd,D[i].second);
		add(D[i].first,D[i].second);
	}
	int ans=max(ac,ad);
	if(mxc&&mxd)ans=max(ans,mxc+mxd);
	printf("%d",ans);
}