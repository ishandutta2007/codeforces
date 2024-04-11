#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
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
const int INF=1e9+7;
struct E{
	int to,nt;
}e[101000];
#define T e[k].to
int n,m,X,Y,root,mx[50500],d[50500],dep[50500],vis[50500],v[101000],siz[50500],w[550],head[50500],N,mini,tot;
ll ans;
I findroot(int x,int fa){
	mx[x]=-1;siz[x]=1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||vis[T]||v[k])continue;
		findroot(T,x);
		mx[x]=max(mx[x],siz[T]);
		siz[x]+=siz[T];
	}
	mx[x]=max(mx[x],N-siz[x]);
	if(mx[x]<mini){
		root=x;
		mini=mx[x];
	}
}
I D_1(int x,int fa){
	siz[x]=1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||vis[T]||v[k])continue;
		dep[T]=dep[x]+1;
		D_1(T,x);
		siz[x]+=siz[T];
	}
}
I D_2(int x,int fa){
	d[++tot]=dep[x];
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||vis[T]||v[k])continue;
		D_2(T,x);
	}
}
I solve(int x){
	memset(w,0,sizeof(w));
	w[0]=1;
	dep[x]=0;
	D_1(x,0);
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(vis[T]||v[k])continue;
		tot=0;
		D_2(T,x);
		F(i,1,siz[T]){
			if(m>=d[i])ans+=1ll*w[m-d[i]];
		}
		F(i,1,siz[T]){
			if(m>=d[i])w[d[i]]++;
		}
	}
}
I divided(int x){
	solve(x);vis[x]=1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(vis[T]||v[k])continue;
		v[k]=v[k^1]=1;
		N=siz[T];mini=INF;
		findroot(T,x);
		divided(root);
	}
}
int main(){
	read(n);read(m);
	memset(head,-1,sizeof(head));
	tot=-1;
	F(i,1,n-1){
		read(X);read(Y);
		e[++tot].to=Y;
		e[tot].nt=head[X];
		head[X]=tot;
		e[++tot].to=X;
		e[tot].nt=head[Y];
		head[Y]=tot;
	}
	N=n;mini=INF;
	findroot(1,0);
	divided(root);
	cout<<ans;
    return 0;
}