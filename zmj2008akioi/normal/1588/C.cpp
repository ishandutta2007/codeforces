#include <cstdio>
#include <vector>
#include <algorithm>
const int inf=1e9,N=3e5,EXT=10;
const long long L=-1e15,R=1e15;
int T,n,rk,unt,a[N+EXT],r[N+EXT],bkt[2*N+EXT],fsegtrr[2][4*N+EXT];
int *segtrr;
long long ans,lst,sum[N+EXT];
namespace basic{
	inline int md(int x,int y){return (x+y)>>1;}
	inline int min(int x,int y){return x<y?x:y;}
}using namespace basic;
struct option{
	int w,v;
	option(){};
	option(int w,int v):w(w),v(v){};
};std::vector<option> vector[N+EXT];
struct unset{
	int id;
	long long val;
	unset(){};
	unset(int id,long long val):id(id),val(val){};
}urr[N+EXT];
inline int lc(int x){return x<<1;}
inline int rc(int x){return (x<<1)+1;}
inline bool cmp(const unset &a,const unset &b){return a.val<b.val;}
inline void setsegtrr(int id){segtrr=fsegtrr[id];}
inline void pushup(int u){segtrr[u]=min(segtrr[lc(u)],segtrr[rc(u)]);}
void modify(int l,int r,int u,int tg,int w){
	if(l==r)segtrr[u]=w;
	else{
		if(md(l,r)>=tg)modify(l,md(l,r),lc(u),tg,w);
		else modify(md(l,r)+1,r,rc(u),tg,w);
		pushup(u);
	}
}
int query(int l,int r,int u,int tl,int tr){
	if(tl>tr)return n+1;
	if(l>=tl&&r<=tr)return segtrr[u];
	else{
		int res=inf;
		if(md(l,r)>=tl)res=min(res,query(l,md(l,r),lc(u),tl,tr));
		if(md(l,r)+1<=tr)res=min(res,query(md(l,r)+1,r,rc(u),tl,tr));
		return res;
	}
}
int main(){
	scanf("%d",&T);
	do{
		scanf("%d",&n);
		for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(register int i=1;i<=4*n;++i)fsegtrr[0][i]=fsegtrr[1][i]=n;
		unt=ans=sum[0]=0;
		for(register int i=1;i<=n;++i){
			if(i&1)sum[i]=sum[i-1]+a[i];
			else sum[i]=sum[i-1]-a[i];
			urr[++unt]=unset(i,sum[i]);
		}
		rk=0,urr[++unt]=unset(0,0),lst=-1e18,std::sort(urr+1,urr+1+unt,cmp);
		for(register int i=1;i<=unt;++i){
			if(lst!=urr[i].val)lst=urr[i].val,bkt[++rk]=0;
			sum[urr[i].id]=rk;
		}
		for(register int i=n;i;--i){
			r[i]=n,setsegtrr(0),r[i]=min(r[i],query(1,rk,1,sum[i-1]+1,rk)),setsegtrr(1),r[i]=min(r[i],query(1,rk,1,1,sum[i-1]-1));
			setsegtrr(i&1),modify(1,rk,1,sum[i],i),vector[i-1].push_back(option(sum[i-1],-1)),vector[r[i]].push_back(option(sum[i-1],1));
		}
		for(register int i=0;i<=n;++i){
			++bkt[sum[i]];
			for(option j:vector[i])ans+=j.v*bkt[j.w];
			vector[i].clear();
		}
		printf("%lld\n",ans);
	}while(--T);
	return 0;
}