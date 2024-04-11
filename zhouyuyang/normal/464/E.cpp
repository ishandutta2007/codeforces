#include<bits/stdc++.h>
#define N 100505
#define mx 100500
#define M 20000005
#define mo 1000000007
#define uint unsigned
#define pa pair<int,int>
#define ull unsigned long long
using namespace std;
uint P1=23,P2=47,p1[N],p2[N];
int ls[M],rs[M],f[M],rt0,ncnt;
map<pa,int> pos;
ull H[M];
void upd(int x,int l,int r){
	int mid=(l+r)/2;
	f[x]=(f[ls[x]]?f[ls[x]]:f[rs[x]]);
	uint x1=H[ls[x]]&((1ll<<32)-1),y1=H[ls[x]]>>32;
	uint x2=H[rs[x]]&((1ll<<32)-1),y2=H[rs[x]]>>32;
	uint xx=x1+x2*p1[mid-l+1],yy=y1+y2*p2[mid-l+1];
	H[x]=xx+(1ll<<32)*yy;
}
void build(int &x,int l,int r){
	x=++ncnt;
	pos[pa(l,r)]=x;
	if (l==r){
		H[x]=0;
		f[x]=l;
		return;
	}
	int mid=(l+r)/2;
	build(ls[x],l,mid);
	build(rs[x],mid+1,r);
	upd(x,l,r);
}
void set0(int &x,int y,int l,int r,int ql,int qr){
	if (ql<=l&&qr>=r){
		x=pos[pa(l,r)];
		return;
	}
	x=++ncnt;
	ls[x]=ls[y]; rs[x]=rs[y];
	int mid=(l+r)/2;
	if (ql<=mid) set0(ls[x],ls[y],l,mid,ql,qr);
	if (qr>mid) set0(rs[x],rs[y],mid+1,r,ql,qr);
	upd(x,l,r);
}
void set1(int &x,int y,int l,int r,int t){
	x=++ncnt; ls[x]=ls[y]; rs[x]=rs[y];
	if (l==r){
		f[x]=0;
		H[x]=(1ll<<32)+1;
		return;
	}
	int mid=(l+r)/2;
	if (t<=mid) set1(ls[x],ls[y],l,mid,t);
	else set1(rs[x],rs[y],mid+1,r,t);
	upd(x,l,r);
}
int ask(int x,int l,int r,int ql,int qr){
	if (ql<=l&&qr>=r) return f[x];
	int mid=(l+r)/2;
	if (qr<=mid) return ask(ls[x],l,mid,ql,qr);
	if (ql>mid) return ask(rs[x],mid+1,r,ql,qr);
	int tmp=ask(ls[x],l,mid,ql,qr);
	if (tmp) return tmp;
	return ask(rs[x],mid+1,r,ql,qr);
}
int Add(int x,int w){
	int t=ask(x,1,mx,w,mx),ans,tmp;
	if (t>w) set0(tmp,x,1,mx,w,t-1);
	else tmp=x;
	set1(ans,tmp,1,mx,t);
	return ans;
}
int ans,cur=1;
void getval(int x,int l,int r){
	if (l==r){
		ans=(ans+cur*(H[x]!=0)%mo)%mo;
		cur=(cur*2)%mo; return;
	}
	int mid=(l+r)/2;
	getval(ls[x],l,mid);
	getval(rs[x],mid+1,r);
}
bool cmp(int x,int y,int l,int r){
	if (l==r) return H[x]<H[y];
	int mid=(l+r)/2;
	if (H[rs[x]]==H[rs[y]])
		return cmp(ls[x],ls[y],l,mid);
	return cmp(rs[x],rs[y],mid+1,r);
}
struct data{
	int x,d;
	bool operator <(const data &b)const{
		return cmp(b.d,d,1,mx);
	}
};
struct edge{int to,next,v;}e[N*2];
int dis[N],head[N],vis[N],st[N],pre[N];
int n,m,x,y,z,tot,S,T,cnt;
priority_queue<data> Q;
void add(int x,int y,int z){
	e[++tot]=(edge){y,head[x],z};
	head[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	p1[0]=p2[0]=1;
	for (int i=1;i<=mx;i++)
		p1[i]=p1[i-1]*P1,
		p2[i]=p2[i-1]*P2;
	build(rt0,1,mx);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z+1); add(y,x,z+1);
	}
	scanf("%d%d",&S,&T);
	Q.push((data){S,rt0});
	vis[S]=1; dis[S]=rt0;
	while (!Q.empty()){
		int x=Q.top().x,d=Q.top().d; Q.pop();
		if (dis[x]!=d) continue;
		for (int i=head[x];i;i=e[i].next){
			int nw=Add(d,e[i].v);
			if (!vis[e[i].to]||cmp(nw,dis[e[i].to],1,mx)){
				vis[e[i].to]=1;
				dis[e[i].to]=nw;
				pre[e[i].to]=x;
				Q.push((data){e[i].to,nw});
			}
		}
	}
	if (!vis[T])
		return puts("-1"),0;
	getval(dis[T],1,mx);
	printf("%d\n",ans);
	for (;T;T=pre[T])
		st[++cnt]=T;
	printf("%d\n",cnt);
	for (;cnt;printf("%d ",st[cnt--]));
}