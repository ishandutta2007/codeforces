#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
char ibuf[1<<25],*ih=ibuf,obuf[1<<23],*oh=obuf;
inline void read(int&x){
	int f=1;for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
inline void write(ll x){
	if(x<0)*oh++='-',x=-x;
	if(x==0)return void(*oh++='0');
	static int buf[30],xb;
	for(xb=0;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
inline ui R(){
    static ui seed=19260817;
    return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
int C,C1,C2;
const int N=1e6+5;
struct node{
	int l,r,fa,sz;ll v,t,mx,mn;
	inline void add(const ll&z){v+=z;mx+=z;mn+=z;t+=z;}
}t[N];
inline void pushdown(int x){if(t[x].t)t[t[x].l].add(t[x].t),t[t[x].r].add(t[x].t),t[x].t=0;}
inline void maintain(int x){
	t[x].sz=t[t[x].l].sz+t[t[x].r].sz+1;
	t[x].mx=t[x].r?t[t[x].r].mx+t[x].t:t[x].v;
	t[x].mn=t[x].l?t[t[x].l].mn+t[x].t:t[x].v;
}
void split(int x,int&p,int&q,const ll&v){
++C1;
	if(!x){p=q=0;return;}
	if(t[x].mx<v){p=x;q=0;return;}
	if(v<=t[x].mn){p=0;q=x;return;}
	pushdown(x);
	if(t[x].v<v)p=x,split(t[x].r,t[p].r,q,v),t[t[p].r].fa=p,maintain(p);
		else q=x,split(t[x].l,p,t[q].l,v),t[t[q].l].fa=q,maintain(q);
}
int merge(int x,int y){
++C;
	if(!x || !y)return x|y;
	pushdown(x);pushdown(y);
	if(R()%(t[x].sz+t[y].sz)<t[x].sz)return t[x].r=merge(t[x].r,y),t[t[x].r].fa=x,maintain(x),x;
		else return t[y].l=merge(x,t[y].l),t[t[y].l].fa=y,maintain(y),y;
}
int ins(int x,int y){
	int l,r;t[y].sz=1;t[y].mn=t[y].mx=t[y].v;
	split(x,l,r,t[y].v);
	return merge(merge(l,y),r);
++C;
	if(!(R()%(t[x].sz+1))){split(x,t[y].l,t[y].r,t[y].v);t[t[y].l].fa=t[t[y].r].fa=y;maintain(y);return y;}
	pushdown(x);int&z=t[x].v<=t[y].v?t[x].r:t[x].l;z=ins(z,y);t[z].fa=x;maintain(x);return x;
}
int getsz(int x){return x>0?getsz(t[x].l)+getsz(t[x].r)+1:0;}
int join(int x,int y){
++C2;
	if(!x || !y)return x|y;
	if(t[x].mx<=t[y].mn)return merge(x,y);if(t[x].mn>=t[y].mx)return merge(y,x);
	if(R()%(t[x].sz+t[y].sz)<t[x].sz)swap(x,y);
	pushdown(x);pushdown(y);
	int p,q;split(x,p,q,t[y].v);
	t[y].l=join(p,t[y].l);t[y].r=join(q,t[y].r);
	t[t[y].l].fa=t[t[y].r].fa=y;maintain(y);
	return y;
}
inline ll ask(int x){
	ll ans=t[x].v;
	for(;x=t[x].fa;)ans+=t[x].t;
	return ans;
}
int n,m,p,a[N],l,r,rt,i;
vector<pair<int,int>>qu[N];
ll ans[N];
int main(){
//	freopen("11","r",stdin);freopen("3","w",stdout);
	scanf("%d%d%d",&n,&m,&p);fread(ibuf,1,1<<25,stdin);
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=m;++i)read(l),read(r),qu[r].push_back(make_pair(l,i));
int mx=0;
	for(i=1;i<=n;++i){
if(i==5e5){
++i,--i;
}
int oc=C;
		rt=ins(rt,i);t[rt].add(a[i]);
		split(rt,l,r,p);t[l].fa=t[r].fa=0;t[r].add(-p);rt=join(l,r);t[rt].fa=0;
mx=max(mx,C-oc);
		for(auto u:qu[i])ans[u.second]=ask(u.first);
	}
	for(i=1;i<=m;++i)write(ans[i]),*oh++='\n';
cerr<<C1<<' '<<C<<' '<<C2<<' '<<mx<<endl;
	return fwrite(obuf,1,oh-obuf,stdout),0;
}