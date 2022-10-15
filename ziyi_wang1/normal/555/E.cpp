#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
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
struct E{
	int to,nt;
}e[404000];
#define T e[k].to
int n,m,Q,tot,X,Y,sn,head[202000];
int dfn[202000],low[202000],clr[202000],color,mill,vis[202000];
int dep[202000],fa[202000],f[202000][20],lg[202000],top[202000];
int up[202000],down[202000];
stack<int>s;
vector<int>v[202000];
vector<int>::iterator it;
I tarjan(int x,int pre){
	dfn[x]=low[x]=++mill;
	s.push(x);vis[x]=1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(k==(pre^1))continue;
		if(!dfn[T]){
			tarjan(T,k);
			low[x]=min(low[x],low[T]);
		}
		else if(vis[T])low[x]=min(low[x],dfn[T]);
	}
	if(dfn[x]==low[x]){
		++color;
		while(s.top()!=x){clr[s.top()]=color;vis[s.top()]=0;s.pop();}
		clr[x]=color;vis[x]=0;s.pop();
	}
}
I D_1(int x,int fat,int depth,int topi){
	//cout<<x<<":";
	f[x][0]=fat;top[x]=topi;dep[x]=depth;
	F(i,1,lg[dep[x]])f[x][i]=f[f[x][i-1]][i-1];
	for(auto k:v[x]){
		//cout<<k<<" ";
		if(k==fat)continue;
		D_1(k,x,depth+1,topi);
	}
	//cout<<endl;
}
I add(int x,int y){v[x].emplace_back(y);}
IN ques_lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	re len=dep[x]-dep[y];
	FOR(i,lg[len],0){
		if((len>>i)&1)x=f[x][i];
	}
	if(x==y)return x;
	FOR(i,lg[dep[x]],0){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
I D_3(int x,int fat){
	if(!sn)return;
	for(auto k:v[x]){
		if(k==fat)continue;
		D_3(k,x);
		if(!sn)return;
		up[x]+=up[k];down[x]+=down[k];
	}
	//cout<<x<<" "<<up[x]<<" "<<down[x]<<endl;
	if(up[x]&&down[x])sn=0;
}
int main(){
	read(n);read(m);read(Q);tot=-1;
	memset(head,-1,sizeof(head));
	F(i,1,m){
		read(X);read(Y);
		e[++tot].to=Y;
		e[tot].nt=head[X];
		head[X]=tot;
		e[++tot].to=X;
		e[tot].nt=head[Y];
		head[Y]=tot;
	}
	F(i,1,n){
		if(!dfn[i])tarjan(i,-1);
	}
	F(i,1,n){
		for(re k=head[i];k!=-1;k=e[k].nt){
			if(clr[i]!=clr[T])add(clr[i],clr[T]);
		}
	}	
	lg[0]=-1;
	F(i,1,n)lg[i]=lg[i>>1]+1,top[i]=i;
	F(i,1,color){
		sort(v[i].begin(),v[i].end());
		it=unique(v[i].begin(),v[i].end());
		v[i].erase(it,v[i].end());
		//cout<<i<<":";
		//for(auto k:v[i])cout<<k<<" ";
		//cout<<endl;
	}
	F(i,1,color){
		if(top[i]==i)dep[i]=1,D_1(i,0,1,i);
	}//STS;
	re P;sn=1;
	while(Q--){
		read(X);read(Y);X=clr[X];Y=clr[Y];
		if(top[X]!=top[Y]){cout<<"No";return 0;}
		P=ques_lca(X,Y);//cout<<X<<" "<<Y<<" "<<P<<endl;
		up[X]++;down[Y]++;up[P]--;down[P]--;
	}
	//F(i,1,color)cout<<up[i]<<" "<<down[i]<<endl;
	F(i,1,color){
		if(top[i]==i)D_3(i,0);
		if(!sn)break;
	}
	if(sn)cout<<"Yes";
	else cout<<"No";
	return 0;
}
/*
8 13 4
5 3
2 7
5 8
2 4
6 4
2 6
5 8
1 4
6 7
3 1
6 7
3 1
8 3
8 7
8 7
5 1
6 8
*/