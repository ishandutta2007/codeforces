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
	int to,nt,v;
}e[2020];
#define T e[k].to
int n,m,head[1010],tot,X,Y,Z,v[1010],dis[1010],sn,cnt,q[1010];
I add(int x,int y){
	e[++tot].to=y;e[tot].nt=head[x];head[x]=tot;e[tot].v=0;
}
I findcent(int x,int fa){
	dis[x]=dis[fa]+1;if(dis[x]>dis[Y])Y=x;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||e[k].v)continue;
		findcent(T,x);
	}
}
I findc(int x,int fa){
	dis[x]=dis[fa]+1;if(dis[x]>dis[X])X=x;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||e[k].v)continue;
		findc(T,x);
	}
}
I getpath(int x,int fa){
	if(x==Y){
		sn=1;return;
	}
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||e[k].v)continue;
		q[++cnt]=k;
		getpath(T,x);
		if(sn)return;--cnt;
	}
}
I D_1(int x,int fa){
	v[x]=0;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||e[k].v)continue;
		D_1(T,x);
	}
}
int main(){
	read(n);C(head,-1);tot=-1;
	F(i,1,n-1){
		read(X);read(Y);add(X,Y);add(Y,X);
	}
	dis[0]=-1;
	while(1){
		X=0;Y=0;
		F(i,1,n)if(!v[i]){
			X=i;break;
		}
		findcent(X,0);
		if(X==Y){
			cout<<"! "<<X<<endl;fflush(stdout);return 0;
		}
		X=Y;findc(Y,0);
		cnt=0;sn=0;
		getpath(X,0);
		//F(i,1,cnt)cout<<e[q[i]].to<<" "<<e[q[i]^1].to<<endl;
		cout<<"? "<<X<<" "<<Y<<endl;fflush(stdout);read(Z);
		F(i,1,cnt)e[q[i]].v=e[q[i]^1].v=1;
		F(i,1,n)v[i]=1;
		D_1(Z,0);
	}
	return 0;
}