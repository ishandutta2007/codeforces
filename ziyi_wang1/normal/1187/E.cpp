// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
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
struct E{
	ll to,nt;
}e[404000];
ll n,m,siz[202000],head[202000],f[202000],g[202000],X,Y,tot=-1;
I add(ll x,ll y){
	e[++tot].to=y;
	e[tot].nt=head[x];
	head[x]=tot;
}
#define T e[k].to
I D_1(ll x,ll fa){
	siz[x]=1;f[x]=0;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_1(T,x);
		siz[x]+=siz[T];
		f[x]+=f[T];
	}
	f[x]+=siz[x];
}
I D_2(ll x,ll fa){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		g[T]=n-siz[T]+g[x]+f[x]-siz[x]-f[T];
		D_2(T,x);
	} 
}
IN max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	read(n);
	memset(head,-1,sizeof(head));
	F(i,1,n-1){
		read(X);read(Y);
		add(X,Y);
		add(Y,X);
	}
	D_1(1,0);
	D_2(1,0);
	re ans=f[1];
	F(i,2,n){
		ans=max(ans,f[i]+g[i]+n-siz[i]);
	}
	cout<<ans;
    return 0;
}