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
#define T e[k].to
int n,m,Q,X,Y,R,_n,_m,sum,now;
int d[303000],ned[303000],a[303000];
IN rea(){
	re res;
	read(res);
	res=(res+R)%n;
	if(!res)res=n;
	return res;
}
struct Graph{
	vector<int>v[303000];
	int root[303000],dep[303000],id[303000],son[303000],siz[303000],top[303000],ma[303000];
	int head[303000],tot;
	int vis[303000],dfn[303000],low[303000],clr[303000],color,mill;
	int sn;
	stack<int>s;
	struct E{
		int to,nt;
	}e[606000];
	I addin(int x,int y){
		v[y].emplace_back(x);
	}
	I add(int x,int y){
		//cout<<"!"<<x<<" "<<y<<endl;
		e[++tot].to=y;
		e[tot].nt=head[x];
		head[x]=tot;
	}
	I tarjan(int x,int fa){
		dfn[x]=low[x]=++mill;
		vis[x]=1;s.emplace(x);
		for(re k=head[x];k!=-1;k=e[k].nt){
			if(k==(fa^1))continue;
			if(!dfn[T]){
				tarjan(T,k);
				low[x]=min(low[T],low[x]);
			}
			else if(vis[T])low[x]=min(low[x],dfn[T]);
		}
		if(dfn[x]==low[x]){
			++color;
			while(s.top()!=x)clr[s.top()]=color,vis[s.top()]=0,s.pop();
			clr[x]=color;vis[x]=0;s.pop();
		}
	}
	I D_1(int x,int fa,int depth,int Root){
		ma[x]=fa;dep[x]=depth;son[x]=-1;root[x]=Root;siz[x]=1;
		re maxi=-1;
		for(auto p:v[x]){
			if(p==fa)continue;
			D_1(p,x,depth+1,Root);
			siz[x]+=siz[p];
			if(maxi<siz[p])maxi=siz[p],son[x]=p;
		}
	}
	I D_2(int x,int fa,int topi){
		top[x]=topi;id[x]=++sum;
		if(son[x]!=-1)D_2(son[x],x,topi);
		for(auto p:v[x]){
			if(p==fa||p==son[x])continue;
			D_2(p,x,p);
		}
	}
	IN ques_lca(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=ma[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		return x;
	}
	I build(){
		tot=-1;C(head,-1);
		F(i,1,m){
			read(X);read(Y);add(X,Y);add(Y,X);
		}
		F(i,1,n)if(!dfn[i])tarjan(i,-1);
		F(i,1,n)for(re k=head[i];k!=-1;k=e[k].nt)if(clr[i]!=clr[T])addin(clr[i],clr[T]);
		F(i,1,color)if(!root[i])D_1(i,0,1,i),D_2(i,0,i);
		//F(i,1,n)cout<<clr[i]<<" ";
		//cout<<endl;
		//F(i,1,color)cout<<i<<":"<<dep[i]<<" "<<son[i]<<" "<<siz[i]<<" "<<root[i]<<" "<<id[i]<<" "<<ma[i]<<endl;
	}
	I solve(){
		//F(i,1,now)cout<<a[i]<<" ";
		//cout<<endl;
		sn=1;
		F(i,1,now)if(!dfn[a[i]])tarjan(a[i],-1);
		F(i,2,_n)
			if(clr[d[i]]!=clr[d[1]]){
				sn=0;
				break;
			}
		if(sn)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		F(i,1,now)head[a[i]]=-1,dfn[a[i]]=low[a[i]]=clr[a[i]]=ned[a[i]]=0,mill=color=0;
	}
}G,g;
inline bool bbb(int x,int y){
	return G.id[x]<G.id[y];
}
int q[303000],r;
int main(){
	read(n);read(m);read(Q);sum=0;C(g.head,-1);
	G.build();
	F(t,1,Q){
		read(_n);read(_m);sum=0;g.tot=-1;
		//cout<<"Read";
		F(i,1,_n){
			d[i]=G.clr[rea()];//cout<<d[i]<<" ";
			if(!ned[d[i]])ned[d[i]]=1,a[++sum]=d[i];
		}
		//cout<<endl;
		//F(i,1,G.color)if(ned[i])cout<<i<<" ";
		//cout<<endl;
		
		F(i,1,_m){
			X=G.clr[rea()];Y=G.clr[rea()];//cout<<X<<" "<<Y<<endl;
			g.add(X,Y);g.add(Y,X);
			if(!ned[X])ned[X]=1,a[++sum]=X;
			if(!ned[Y])ned[Y]=1,a[++sum]=Y;
		}
		sort(a+1,a+1+sum,bbb);r=0;now=sum;
		F(i,1,sum){
			if(!r||G.root[q[r]]!=G.root[a[i]]){
				while(r>1)g.add(q[r],q[r-1]),g.add(q[r-1],q[r]),r--;
				q[r=1]=G.root[a[i]];
				if(!ned[G.root[a[i]]])ned[G.root[a[i]]]=1,a[++now]=G.root[a[i]];
				else continue;
			}
			re lca=G.ques_lca(q[r],a[i]);
			while(G.id[q[r]]>G.id[lca]){
				if(G.id[q[r-1]]>G.id[lca])g.add(q[r-1],q[r]),g.add(q[r],q[r-1]),r--;
				else g.add(lca,q[r]),g.add(q[r],lca),q[r]=lca,a[++now]=lca;
			}
			q[++r]=a[i];
		}
		while(r>1)g.add(q[r],q[r-1]),g.add(q[r-1],q[r]),r--;
		g.solve();
		if(g.sn)R=(R+t)%n;
	}
	return 0;
}