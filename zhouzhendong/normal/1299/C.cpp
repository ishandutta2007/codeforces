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
const int N=1000005;
int n;
LL a[N];
int nxt[N];
int st[N],top=0;
int main(){
	n=read();
	For(i,1,n)
		a[i]=read()+a[i-1];
	Fod(i,n,0){
		while (top>1){
			int j=st[top],k=st[top-1];
			if ((a[k]-a[i])*(j-i)<=(a[j]-a[i])*(k-i))
				top--;
			else
				break;
		}
		nxt[i]=top?st[top]:n;
		st[++top]=i;
	}
	for (int i=0;i<n;i=nxt[i]){
		double val=(double)(a[nxt[i]]-a[i])/(nxt[i]-i);
		For(j,i+1,nxt[i]){
			printf("%.10lf\n",val);
		}
	}
	return 0;
}