#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
#define outarr(a,L,R) printf(#a"[%d...%d] = ",L,R);\
						For(_v2,L,R)printf("%d ",a[_v2]);puts("");
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=200005;
int n;
int b[N],c[N],a[N];
LL sum=0;
int bit[30];
int check(int x){
	LL vb=0,vc=0;
	For(i,0,29){
		if (a[x]>>i&1){
			vb+=(1LL<<i)*bit[i];
			vc+=(1LL<<i)*n;
		}
		else {
			vc+=(1LL<<i)*bit[i];
		}
	}
	return vb==b[x]&&vc==c[x];
}
int main(){
	n=read();
	For(i,1,n)
		b[i]=read(),sum+=b[i];
	For(i,1,n)
		c[i]=read(),sum+=c[i];
	if (sum%(n*2)!=0)
		return puts("-1"),0;
	sum/=n*2;
	For(i,1,n)
		if (b[i]+c[i]<sum||(b[i]+c[i]-sum)%n!=0)
			return puts("-1"),0;
		else
			a[i]=(b[i]+c[i]-sum)/n;
	For(i,1,n)
		For(j,0,29)
			if (a[i]>>j&1)
				bit[j]++;
	For(i,1,n)
		if (!check(i))
			return puts("-1"),0;
	For(i,1,n)
		printf("%d ",a[i]);
	return 0;
}