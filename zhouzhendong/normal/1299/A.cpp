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
const int N=1e5+5;
int n;
int a[N];
int pre[N],suf[N];
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		pre[i]=pre[i-1]|a[i];
	Fod(i,n,1)
		suf[i]=suf[i+1]|a[i];
	int ans=-1,id=0;
	For(i,1,n){
		int v=pre[i-1]|suf[i+1];
		v=(a[i]|v)^v;
		if (ans<v)
			ans=v,id=i;
	}
//	outval(ans);
//	outval(id);
	swap(a[1],a[id]);
	For(i,1,n)
		printf("%d ",a[i]);
	return 0;
}