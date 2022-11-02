#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
					For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){	
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
const int N=1000005;
int n;
int fa[N];
int ans[N];
int mx[N],semx[N];
int v[N];
void upd(int x,int v){
	if (v>mx[x])
		semx[x]=mx[x],mx[x]=v;
	else if (v>semx[x])
		semx[x]=v;
}
int main(){
	n=read();
	For(i,2,n+1){
		int f=read();
		fa[i]=f;
		mx[i]=semx[i]=0;
		v[i]=1;
		int x=i,y=fa[x];
		while (1){
			upd(y,v[x]);
			int now;
			if (mx[y]==semx[y])
				now=mx[y]+1;
			else
				now=mx[y];
			if (now!=v[y]){
				v[y]=now;
				x=y,y=fa[x];
			}
			else 
				break;
		}
		printf("%d ",mx[1]);
	}
	return 0;
}