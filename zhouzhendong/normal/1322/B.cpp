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
#define outtime() cerr<<"User Time = "\
	<<(double)clock()/CLOCKS_PER_SEC<<endl
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
const int N=(1<<25)+5;
int n;
int c[N],_s[N],*s=_s+1;
int f(int L,int R){
	return s[R]-s[L-1];
}
int main(){
	n=read();
	int ans=0;
	For(i,1,n)
		c[read()]++;
	Fod(i,24,0){
		int n=1<<(i+1);
		s[-1]=0;
		For(i,0,n-1)
			s[i]=s[i-1]+c[i];
		LL now=0;
		For(i,0,n-1)//n/2<=(i+j)%n<n
			if (c[i]){
				int L=(n/2-i+n)%n,R=L+n/2-1;
				if (R<n)
					now+=(LL)c[i]*f(L,R);
				else
					now+=(LL)c[i]*(f(L,n-1)+f(0,R-n));
				if ((i<<1)&(n>>1))
					now-=c[i];
			}
		ans^=(now>>1&1)<<i;
		For(i,n/2,n-1)
			c[i-n/2]+=c[i];
	}
	cout<<ans<<endl;
	return 0;
}