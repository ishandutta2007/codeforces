#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m,ans[N];
Pii s[N];int len;
int main() {
	read(n);read(m);
	rep(i,1,n){int x;read(x);s[++len]=Pii(x,i);}
	rep(i,1,m){int x,y;read(x);read(y);s[++len]=Pii(x,-y);}
	sort(s+1,s+len+1);int cur=0;
	rep(i,1,len)
		if(s[i].se<0)cur-=s[i].se;else ans[s[i].se]=cur;
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}