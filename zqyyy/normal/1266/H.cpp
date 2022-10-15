#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=60;
const ull mod1=9019283818374625387,mod2=9019283818374625391;
inline ull qmul(ull a,ull b,ull mod){
	return (__uint128_t)a*b%mod;
}
inline ull qpow(ull a,ull b,ull mod){
	ull res=1;
	for(;b;b>>=1,a=qmul(a,a,mod))
		if(b&1)res=qmul(a,res,mod);
	return res;
}
int n,Q,b[N],r[N];
char str[N];
vector<int>B[N],R[N];
struct node{
	ull x,y;
	node(ull _x=0){x=y=_x;}
	node operator +(node a){
		node r;
		r.x=(x+a.x)%mod1,r.y=(y+a.y)%mod2;
		return r;
	}
	node operator -(node a){
		node r;
		r.x=(x+mod1-a.x)%mod1,r.y=(y+mod2-a.y)%mod2;
		return r;
	}
	node operator *(node a){
		node r;
		r.x=qmul(x,a.x,mod1),r.y=qmul(y,a.y,mod2);
		return r;
	}
	node inv(){
		node r;
		r.x=qpow(x,mod1-2,mod1),r.y=qpow(y,mod2-2,mod2);
		return r;
	}
	node operator /(node a){return (*this)*a.inv();}
	node& operator +=(node a){return *this=*this+a;}
	node& operator -=(node a){return *this=*this-a;}
	node& operator *=(node a){return *this=*this*a;}
	node& operator /=(node a){return *this=*this/a;}
};
node a[N][N],A[N][N],c[N],x[N];
bool flg[N],vis[N];
inline void Gauss(){
	for(int i=1;i<=n;i++)A[i][i]=node(1);
	for(int i=1;i<=n;i++){
		assert(a[i][i].x && a[i][i].y);
		node inv=a[i][i].inv();
		for(int j=i;j<=n;j++)a[i][j]*=inv;
		for(int j=1;j<=n;j++)A[i][j]*=inv;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			node mul=a[j][i];
			for(int k=i;k<=n;k++)a[j][k]-=a[i][k]*mul;
			for(int k=1;k<=n;k++)A[j][k]-=A[i][k]*mul;
		}
	}
}
inline ll work(){
	int v=read();scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		c[i]=node((str[i]=='R')+(i==1)),c[i]-=node(i==v);
		for(int x:B[i])c[i]-=node(str[x]=='R');
	}
	ull res=0;
	for(int i=1;i<=n;i++){
		x[i]=node(0);
		for(int j=1;j<=n;j++)x[i]+=A[i][j]*c[j];
		if(x[i].x!=x[i].y)return -1;
		if(!x[i].x && str[i]=='R')return -1;
		res+=x[i].x+x[i].x-(str[i]=='R'),flg[i]=x[i].x!=0;
	}
	for(int i=1;i<=n;i++){
		if(!flg[i])continue;
		fill(vis+1,vis+n+2,0);
		int x=i;
		while(!vis[x]){
			vis[x]=1,x=str[x]=='R'?r[x]:b[x];
			if(x>n)break;
		}
		if(!vis[v])return -1;
	}
	return res;
}
int main(){
	n=read()-1;
	for(int i=1;i<=n;i++){
		b[i]=read(),r[i]=read();
		B[b[i]].push_back(i),R[r[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		a[i][i]=node(2);
		for(int x:B[i])a[i][x]-=node(1);
		for(int x:R[i])a[i][x]-=node(1);
	}
	Gauss(),Q=read();
	while(Q--)printf("%lld\n",work());
	return 0;
}