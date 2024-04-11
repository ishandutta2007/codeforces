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
const int N=1000005,mod=1e9+9;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
int n;
int a[N],b[N],c[N],d[N];
int main(){
	n=read();
	a[0]=1;
	For(i,1,n)
		a[i]=((LL)a[i-1]*2+3)%mod;
	b[0]=0;//b[1] should be 21
	For(i,1,n)
//		b[i]=((LL)b[i-1]*4+2LL*a[i-1]*2*3+3*3)%mod;
		b[i]=(LL)a[i]*a[i]%mod;
	c[n]=2;
	Fod(i,n-1,2)
		if (i&1)
			c[i]=((LL)c[i+1]+2)%mod;
		else
			c[i]=((LL)c[i+1]*a[(i>>1)-1]+2)%mod;
	d[n]=4;
	Fod(i,n-1,3)
		if (i&1)
			d[i]=((LL)d[i+1]+2LL*c[i+1]*2+4)%mod;
		else
			d[i]=((LL)d[i+1]*b[(i>>1)-1]+2LL*2*c[i+1]*a[(i>>1)-1]+4)%mod;
	d[2]=((LL)d[3]+2LL*2*c[3]+4)%mod;
//	outarr(a,0,n);outarr(b,0,n);outarr(c,1,n);outarr(d,1,n);
	int ans=(d[2]+1)*2%mod;
	cout<<ans<<endl;
	return 0;
}