#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=17,INF=1e9;
int n,k;
int a[(1<<N)+1];
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
struct S{
	int v[2][2];
	S(){}
	S(int x){
		v[0][0]=v[0][1]=v[1][0]=v[1][1]=x;
	}
	S(int a,int b,int c,int d){
		v[0][0]=a,v[0][1]=b,v[1][0]=c,v[1][1]=d;
	}
	friend S operator + (S a,S b){
		S c(-INF);
		For(ua,0,1)For(la,0,1)
			For(ub,0,1)For(lb,0,1)
				For(m1,0,1)For(m2,0,1)For(m3,0,1){
					int v=a.v[ua][la]+b.v[ub][lb];
					// turn 1 ua vs ub
					v+=ua|ub;
					int w0=m1?ua:ub;
					// turn 2 la vs lb
					v+=la|lb;
					int w1=m2?la:lb;
					// turn 3 w0 vs w1
					v+=w0|w1;
					int w2=m3?w0:w1;
					ckmax(c.v[m1?ub:ua][w2],v);
				}
		return c;
	}
};
S Solve(int L,int R){
	if (L+1==R){
		S c(-INF);
		c.v[a[L]][a[R]]=c.v[a[R]][a[L]]=a[L]|a[R];
		return c;
	}
	int mid=(L+R)>>1;
	return Solve(L,mid)+Solve(mid+1,R);
}
int main(){
	n=read(),k=read();
	while (k--)
		a[read()]=1;
	S res=Solve(1,1<<n);
	int ans=-INF;
	For(a,0,1)
		For(b,0,1)
			ans=max(ans,res.v[a][b]+(a|b));
	cout<<ans<<endl;
	return 0;
}