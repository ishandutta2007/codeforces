#include <cstdio>
const int N=1e5+10;
int T,n,m,a[N];
namespace SGT{
	int len[N<<2];
	long long ans,pa[N<<2];
	struct node{
		int l,r,c;long long ls,rs;node(){};
		node(int x){ls=rs=c=1,l=r=x;}
	}t[N<<2];
	int lc(int x){return x<<1;}
	int rc(int x){return (x<<1)|1;}
	int md(int x,int y){return (x+y)>>1;}
	void pushup(int x){
		int l=lc(x),r=rc(x),k=t[l].r==t[r].l;
		t[x].l=t[l].l,t[x].r=t[r].r,t[x].c=t[l].c+t[r].c-k;
		t[x].ls=t[l].ls+(t[r].ls+1ll*len[r]*(t[l].c-k));
		t[x].rs=t[r].rs+(t[l].rs+1ll*len[l]*(t[r].c-k));
		ans+=(pa[x]=t[l].rs*len[r]+t[r].ls*len[l]-1ll*k*len[l]*len[r]);
	}
	void build(int l,int r,int u){
		len[u]=r-l+1;if(l==r)t[u]=node(a[l]),ans+=(pa[u]=1);
		else build(l,md(l,r),lc(u)),build(md(l,r)+1,r,rc(u)),pushup(u);
	}
	void modify(int l,int r,int u,int g,int d){
		if(l==r){t[u]=node(d);return;}ans-=pa[u];
		if(md(l,r)>=g)modify(l,md(l,r),lc(u),g,d);
		else modify(md(l,r)+1,r,rc(u),g,d);
		pushup(u);
	}
	void fb(){build(1,n,1);}
	void fm(int g,int d){modify(1,n,1,g,d);}
	long long fq(){return ans;}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	SGT::fb();
	for(int x,d,i=1;i<=m;++i){
		scanf("%d %d",&x,&d);
		SGT::fm(x,d),printf("%lld\n",SGT::fq());
	}
	return 0;
}