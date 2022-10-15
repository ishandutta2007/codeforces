#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
typedef __int128 i128;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
#define Debug(x,y) F(i,1,y)cout<<x[i]<<" ";cout<<endl;
template<class D>I read(D &res){
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
#define fi(x) x.first
#define se(x) x.second
#define mp(x,y) make_pair(x,y)
typedef pair<int,int>pii; 
struct E{
	int to,nt,w,v;
}e[404000];
#define T e[k].to
int n,m,t,head[202000],r[202000],vis[202000],sn,tot=-1;
vector<pii>vec[202000];
IN get(int x){
	re res=0;
	while(x){
		if(x&1)res^=1;
		x>>=1;
	}
	return res;
}
I add(int x,int y,int w,int v){
	e[++tot].to=y;
	e[tot].nt=head[x];
	head[x]=tot;
	e[tot].w=w;e[tot].v=v;
}
I D_1(int x,int fa,int val){
	if(val!=-1)r[x]=val;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		if(e[k].w==-1||val==-1)D_1(T,x,-1);
		else D_1(T,x,val^e[k].w);
	}
}
I D_2(int x){
	vis[x]=1;
	for(auto d:vec[x]){
		if(r[fi(d)]==-1)r[fi(d)]=r[x]^se(d);
		else if(r[fi(d)]^r[x]^se(d))sn=0;
		if(vis[fi(d)])continue;
		D_2(fi(d));
	}
}
I D_3(int x,int fa){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		if(e[k].v==-1)e[k].v=r[x]^r[T];
		cout<<x<<" "<<T<<" "<<e[k].v<<endl;
		D_3(T,x);
	}
}
int main(){
	read(t);
	while(t--){
		read(n);read(m);C(head,-1);tot=-1;
		F(i,1,n)r[i]=-1,vis[i]=0;
		F(i,1,n)vec[i].clear();
		F(i,1,n-1){
			re X,Y,W,V;
			read(X);read(Y);read(V);
			if(V!=-1)W=get(V);else W=-1;
			add(X,Y,W,V);add(Y,X,W,V);
			if(V!=-1)vec[X].emplace_back(mp(Y,W)),vec[Y].emplace_back(mp(X,W));
		}
		F(i,1,m){
			re X,Y,W;
			read(X);read(Y);read(W);
			vec[X].emplace_back(mp(Y,W));
			vec[Y].emplace_back(mp(X,W)); 
		}
		D_1(1,0,0);
//		F(i,1,n)cout<<r[i]<<" ";
//		cout<<endl;
		sn=1;
		F(i,1,n)if(r[i]!=-1&&!vis[i])D_2(i);
		if(!sn){
			cout<<"NO"<<endl;
			continue;
		}
		F(i,1,n)if(r[i]==-1){
			r[i]=0;D_2(i);
		}
		if(!sn){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		D_3(1,0);
	}
	return 0;
}