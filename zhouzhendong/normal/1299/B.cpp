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
const int N=2e5+5;
int n;
int x[N],y[N];
int check(){
	if (n&1)
		return 0;
	For(i,1,n/2){
		if (x[i+1]-x[i]!=x[i+n/2]-x[i+n/2+1])
			return 0;
		if (y[i+1]-y[i]!=y[i+n/2]-y[i+n/2+1])
			return 0;
	}
	return 1;
}
int main(){
	n=read();
	For(i,1,n)
		x[i]=read(),y[i]=read(),x[i+n]=x[i],y[i+n]=y[i];
	puts(check()?"YES":"NO");
	return 0;
}