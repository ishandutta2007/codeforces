#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1005;
int n;
int r[N],c[N];
pair <int,int> p1[N],p2[N];
int cnt=0;
int main(){
	n=read();
	For(i,1,n)
		r[i]=read();
	For(i,1,n)
		c[i]=read();
	For(i,1,n-1){
		int pr,pc;
		For(j,1,n){
			if (r[j]==i)
				pr=j;
			if (c[j]==i)
				pc=j;
		}
		if (pr==i&&pc==i)
			continue;
		cnt++;
		p1[cnt]=mp(i,pc),swap(c[i],c[pc]);
		p2[cnt]=mp(pr,i),swap(r[i],r[pr]);
	}
	printf("%d\n",cnt);
	For(i,1,cnt)
		printf("%d %d %d %d\n",p1[i].fi,p1[i].se,p2[i].fi,p2[i].se);
	return 0;
}