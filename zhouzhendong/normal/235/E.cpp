#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define outval(x) printf(#x" = %d\n",x)
#define For(x,a,b) for (int x=a;x<=b;x++)
#define Fod(x,b,a) for (int x=b;x>=a;x--)
#define pb push_back
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
const int N=2005,mod=1<<30,amod=mod-1;
int a,b,c;
int u[N];
int gcd[N][N];
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int main(){
	a=read(),b=read(),c=read();
	u[1]=1;
	For(i,1,N-1)
		for (int j=i<<1;j<N;j+=i)
			Del(u[j],u[i]);
	For(i,0,N-1)
		For(j,0,N-1)
			gcd[i][j]=gcd[j][i]=j?gcd[j][i%j]:i;
	int ans=0;
	For(p,1,a)
		For(z,1,c){
			if (gcd[p][z]!=1)
				continue;
			int sa=0,sb=0;
			For(i,1,a/p)
				if (gcd[i][z]==1)
					Add(sa,a/p/i);
			For(i,1,b/p)
				if (gcd[i][z]==1)
					Add(sb,b/p/i);
			Add(ans,(LL)u[p]*(c/z)%mod*sa%mod*sb%mod);
		}
	cout<<ans<<endl;
	return 0;
}