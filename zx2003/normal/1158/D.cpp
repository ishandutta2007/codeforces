#include<bits/stdc++.h>
const int N=2e3+5;
typedef long long ll;
struct P{
int x,y;
inline void in(){scanf("%d%d",&x,&y);}
inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
}a[N];
inline ll cross(const P&a,const P&b){return 1ll*a.x*b.y-1ll*b.x*a.y;}
inline int sgn(ll x){return x?(x>0?1:-1):0;}
inline bool cmp(int x,int y){return a[x].x==a[y].x?a[x].y<a[y].y:a[x].x<a[y].x;}
int n,i,j,c[N],xb,id[N],ans[N];
char s[N];
bool b[N];
inline void CH(){
	static int st[N];int w=0,i;
	for(i=1;i<=n;++i)if(!b[id[i]]){
		for(;w>1 && cross(a[id[i]]-a[st[w-1]],a[st[w]]-a[st[w-1]])<=0;--w);
		st[++w]=id[i];
	}
	int ow=w;
	for(i=n-1;i>=1;--i)if(!b[id[i]]){
		for(;w>ow && cross(a[id[i]]-a[st[w-1]],a[st[w]]-a[st[w-1]])<=0;--w);
		st[++w]=id[i];
	}
	xb=--w;memcpy(c+1,st+1,w<<2);
}
int tang(int o){
	for(int i=1;i<=xb;++i){
		int pr=i==1?xb:i-1,nx=i==xb?1:i+1,s1,s2;
		s1=sgn(cross(a[c[i]]-a[ans[::i-1]],a[c[pr]]-a[ans[::i-1]]));
		s2=sgn(cross(a[c[i]]-a[ans[::i-1]],a[c[nx]]-a[ans[::i-1]]));
		if(s1!=s2)continue;
		if(o?s1==1:s1==-1)return c[i];
	}
	assert(0);
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)a[i].in(),id[i]=i;scanf("%s",s+1);	
	std::sort(id+1,id+n+1,cmp);
	CH();
	ans[1]=c[1];b[c[1]]=1;
	for(i=2;i<n;++i){
		CH();
		if(s[i-1]=='L')ans[i]=tang(1);else ans[i]=tang(0);
		b[ans[i]]=1;
	}
	for(i=1;i<=n;++i)if(!b[i])ans[n]=i;
	for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}