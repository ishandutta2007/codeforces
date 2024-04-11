#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
I read(ll &res){
	res=0;re g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const ll INF=1e18+9;
ll n,m,root,tot,ch[101000][2],fa[101000],laz[101000],siz[101000],w[101000],a[101000],ans;
I push_up(ll x){
	siz[x]=siz[ch[x][1]]+siz[ch[x][0]]+1;
}
I modi(ll x,ll val){
	w[x]+=val;laz[x]+=val;
}
I push_down(ll x){
	if(laz[x]){
		re &w=laz[x];
		if(ch[x][1])modi(ch[x][1],w);
		if(ch[x][0])modi(ch[x][0],w);
		w=0;
	}
}
I tags(ll x){
	if(fa[x])tags(fa[x]);
	push_down(x);
}
I rotate(ll x){
	re old=fa[x],oldf=fa[old],dir=(ch[old][1]==x);
	fa[ch[x][dir^1]]=old;ch[old][dir]=ch[x][dir^1];
	fa[old]=x;ch[x][dir^1]=old;
	fa[x]=oldf;
	if(oldf)ch[oldf][ch[oldf][1]==old]=x;
	push_up(old);push_up(x);
}
I splay(ll x,ll goal=0){
	tags(x);
	while(fa[x]!=goal){
		re old=fa[x];
		if(fa[old]!=goal&&(ch[fa[old]][1]==old)^(ch[old][1]!=x))rotate(old);
		rotate(x);
	}
	root=x;
	push_up(x);
}
I find(ll &x,ll ma,ll cur,ll W){
	//cout<<x<<endl;
	if(!x){
		x=++tot;
		siz[x]=1;ch[x][0]=ch[x][1]=0;if(ma)fa[x]=ma,siz[ma]++;
		w[x]=W*(cur+1);
		splay(x);
		return ;
	}
	re sum=cur+siz[ch[x][0]]+1;
	push_down(x);
	if(w[x]>=sum*W)find(ch[x][1],x,sum,W);
	else find(ch[x][0],x,cur,W);
}
I build(ll x,ll &cur){
	push_down(x);
	if(ch[x][0])build(ch[x][0],cur);
	cur+=w[x];
	ans=max(ans,cur);
	if(ch[x][1])build(ch[x][1],cur);
}
int main(){
	//freopen("subsequence.in","r",stdin);
	//freopen("subsequence.out","w",stdout);
	read(n);
	F(i,1,n){
		read(a[i]);
	}
	F(i,1,n){
		find(root,0,0,a[i]);
		//system("pause");
		modi(ch[root][1],a[i]);
	}
	//system("pause");
	re cur=0;tot=0;ans=0;
	build(root,cur);
	cout<<ans;
	//cout<<a[tot];
	return 0;
}