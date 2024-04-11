#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
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
const int mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
const int N=1000005;
int n,p;
int a[N];
void Solve(){
	n=read(),p=read();
	For(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=0,pos=1e6;
	LL now=0;
	For(i,1,n){
		ans=(LL)ans*Pow(p,pos-a[i])%mod;
		if (now==0)
			pos=a[i];
		while (pos>a[i]&&now<2.1e6&&p!=1)
			now*=p,pos--;
		pos=a[i];
		now--;
		Del(ans,1);
		if (now<0)
			now=-now,ans=(mod-ans)%mod;
	}
	ans=(LL)ans*Pow(p,pos)%mod;
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while (T--)
		Solve();
	return 0;
}