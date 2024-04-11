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
struct E{
	int to,nt;
}e[202000];
#define T e[k].to
int n,m,X,Y,tot,now,S,head[101000],a[101000],s[101000],son[101000],siz[101000];
ll cnt,ans[101000];
I add(int x,int y){
	e[++tot].to=y;e[tot].nt=head[x];head[x]=tot;
}
I D_1(int x,int fa){
	siz[x]=1;son[x]=0;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_1(T,x);siz[x]+=siz[T];
		if(siz[T]>siz[son[x]])son[x]=T;
	}
}
I D_3(int x,int fa,int sn){
	s[a[x]]+=sn;
	if(s[a[x]]>now)now=s[a[x]],cnt=(ll)a[x];
	else if(s[a[x]]==now)cnt+=(ll)a[x];
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||T==S)continue;
		D_3(T,x,sn);
	}
}
I D_2(int x,int fa,int sn){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||T==son[x])continue;
		D_2(T,x,0);
	}
	if(son[x])D_2(son[x],x,1),S=son[x];
	D_3(x,fa,1);ans[x]=cnt;S=0;
	if(!sn)D_3(x,fa,-1),now=cnt=0;
}
int main(){
	read(n);tot=-1;C(head,-1);
	F(i,1,n)read(a[i]);
	F(i,1,n-1){
		read(X);read(Y);add(X,Y);add(Y,X);
	}
	D_1(1,0);D_2(1,0,1);
	F(i,1,n)printf("%lld ",ans[i]);
	return 0;
}