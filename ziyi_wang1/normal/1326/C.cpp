#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
const int Mod=998244353;
ll ans1;
int n,m,a[202000],p[202000],tot,ans2;
int main(){
	read(n);read(m);
	F(i,1,n)read(a[i]);
	tot=0;
	F(i,1,n)if(a[i]>n-m)p[++tot]=i;
	ans1=(ll)(n+n-m+1)*m/2ll;ans2=1;
	F(i,2,tot)ans2=(ll)ans2*(p[i]-p[i-1])%Mod;
	cout<<ans1<<" "<<ans2;
	return 0;
}