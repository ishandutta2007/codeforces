#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
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
typedef pair<int,ll>pii;
typedef pair<ll,int>pil;
vector<pii>e[1010000];
int n,m,s,in[1010000],out[1010000],tot,p,X,Y,L,R,sit,vis[1010000];
ll dis[1010000],W;
priority_queue<pil>q;
#define all 1,1,n
#define lt k<<1,l,mid
#define rt k<<1|1,mid+1,r
I build(int k,int l,int r){
	if(l==r){
		in[k]=out[k]=l;return;
	}
	re mid=(l+r)>>1;
	build(lt);build(rt);
	in[k]=++tot;out[k]=++tot;
	e[out[k<<1]].emplace_back(make_pair(out[k],0));
	e[out[k<<1|1]].emplace_back(make_pair(out[k],0));
	e[in[k]].emplace_back(make_pair(in[k<<1],0));
	e[in[k]].emplace_back(make_pair(in[k<<1|1],0));
}
I modi1(int k,int l,int r,int x,int y,int v,ll w){
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		e[v].emplace_back(make_pair(in[k],w));
		return;
	}
	re mid=(l+r)>>1;
	modi1(lt,x,y,v,w);modi1(rt,x,y,v,w);
}
I modi2(int k,int l,int r,int x,int y,int v,ll w){
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		e[out[k]].emplace_back(make_pair(v,w));
		return;
	}
	re mid=(l+r)>>1;
	modi2(lt,x,y,v,w);modi2(rt,x,y,v,w);
}
int main(){
	read(n);read(m);read(s);tot=n;
	build(all);
	F(i,1,m){
		read(sit);
		switch(sit){
			case 1:{
				read(X);read(Y);read(W);
				e[X].emplace_back(make_pair(Y,W));
				break;
			}
			case 2:{
				read(X);read(L);read(R);read(W);
				modi1(all,L,R,X,W);
				break;
			}
			case 3:{
				read(X);read(L);read(R);read(W);
				modi2(all,L,R,X,W);
				break;
			}
		}
	}
	F(i,1,tot)dis[i]=INF;dis[s]=0ll;
	q.emplace(make_pair(dis[s],s));
	while(!q.empty()){
		p=q.top().second;q.pop();//cout<<"!"<<p<<endl;
		if(vis[p])continue;
		vis[p]=1;
		for(auto &u:e[p]){
			if(!u.first)continue;
			if(dis[p]+u.second<dis[u.first]){
				dis[u.first]=dis[p]+u.second;
				q.emplace(make_pair(-dis[u.first],u.first));
			}
		}
	}
	F(i,1,n){
		if(dis[i]!=INF)printf("%lld ",dis[i]);
		else printf("-1 ");
	}
	return 0;
}