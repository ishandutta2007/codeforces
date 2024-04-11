#include <cstdio>
#include <queue>
#include <algorithm>
const int N=2e5+10;
const long long inf=1e12;
int n,m,k,dnt,top,stk[N],head[N],to[N],val[N],next[N];
long long f[N],ans[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
struct cpx{
	long long x,y;cpx(){}
	cpx(long long x,long long y):x(x),y(y){};
	cpx operator+(cpx nxt){return cpx(x+nxt.x,y+nxt.y);}
	cpx operator-(cpx nxt){return cpx(x-nxt.x,y-nxt.y);}
	long long operator&(cpx nxt){return x*nxt.y-y*nxt.x;}
}crr[N];
struct st{
	int u;long long w;st(){};
	st(int u,long long w):u(u),w(w){};
	bool operator<(const st &nxt)const{return w>nxt.w;}
};std::priority_queue<st> heap;
long long sq(int x){return 1ll*x*x;}
bool chk(cpx a,cpx b,cpx c){return ((b-a)&(c-b))>0;}
void ad(int u,int v,int w){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,val[dnt]=w;}
long long g(cpx a,int p){return a.y-p*a.x;}
void update(){
	for(int i=1;i<=n;++i)heap.push(st(i,f[i])),f[i]=-1;
	while(heap.size()){
		while(heap.size()&&f[heap.top().u]!=-1)heap.pop();
		if(!heap.size())break;st t=heap.top();heap.pop();
		int u=t.u;long long w=t.w;f[u]=w;
		for(int i=head[u];i;i=next[i])heap.push(st(to[i],w+val[i]));
	}
	for(int i=1;i<=n;++i)cmin(ans[i],f[i]);
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)f[i]=ans[i]=inf;
	for(int u,v,w,i=1;i<=m;++i)scanf("%d %d %d",&u,&v,&w),ad(u,v,w),ad(v,u,w);
	f[1]=0,update();
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j)crr[j]=cpx(j<<1,f[j]+sq(j));top=0;
		for(int j=1;j<=n;++j){
			while(top>1&&!chk(crr[stk[top-1]],crr[stk[top]],crr[j]))--top;
			stk[++top]=j;
		}
		for(int p=1,j=1;j<=n;++j){
			while(p<top&&chk(crr[stk[p]],crr[stk[p+1]],crr[stk[p+1]]+cpx(1,j)))++p;
			f[j]=g(crr[stk[p]],j)+sq(j);
		}
		update();
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}