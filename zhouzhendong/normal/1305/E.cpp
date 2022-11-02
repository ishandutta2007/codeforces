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
const int N=5005;
int n,m;
int a[N];
int main(){
	n=read(),m=read();
	a[1]=1,a[2]=2;
	For(i,3,n){
		if (m>=(i-1)/2){
			a[i]=i;
			m-=(i-1)/2;
		}
		else if (m>0){
			a[i]=i;
			while (((i-1)-(a[i]-(i-1))+1)/2>m)
				a[i]++;
			m=0;
		}
		else if (m==0){
			a[i]=a[i-1]+n*3;
			while (a[i]%3!=1)
				a[i]++;
			m=-1;
		}
		else {
			a[i]=a[i-1]+n*3;
		}
	}
	if (m>0)
		puts("-1");
	else {
		For(i,1,n)
			printf("%d ",a[i]);
		puts("");
	}
	return 0;
}