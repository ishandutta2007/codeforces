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
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
namespace gao{
	const int N=800;
	int n;
	vi a;
	int vis[N];
	int main(){
		while (1){
			int A=N,B=N,C=N;
			For(a,1,N-1) if (!vis[a])
				For(b,1,N-1) if (!vis[b]&&b!=a)
					For(c,1,N-1) if (!vis[c]&&c!=a&&c!=b&&(a^b)==c){
						if (a<A||a==A&&b<B||a==A&&b==B&&c<C)
							A=a,B=b,C=c;
					}
			a.pb(A),a.pb(B),a.pb(C);
			vis[A]=vis[B]=vis[C]=1;
			printf("%d,%d,%d\n",A,B,C);
			if (C>767)
				break;
		}
		outarr(a,0,(int)a.size()-1);
		return 0;
	}
}
int main(){
//	gao::main();
	int T=read();
//	int T=(int)gao::a.size();
	For(_,0,T-1){
		LL n=read();
//		LL n=_+1;
		LL t=(n+2)/3,c=n-(t-1)*3;
//		outval(t),outval(c);
		LL i;
		for (i=1;i<t;i*=4)
			t-=i;
		LL v1=i+t-1,v2=i*2;
		for (i/=4;i;i/=4){
			if (t<=i)
				v2+=0*i,t-=0*i;
			else if (t<=i*2)
				v2+=2*i,t-=1*i;
			else if (t<=i*3)
				v2+=3*i,t-=2*i;
			else
				v2+=1*i,t-=3*i;
		}
		LL v3=v1^v2;
		LL res;
		printf("%lld\n",res=c==1?v1:c==2?v2:v3);
//		assert(res==gao::a[_]);
	}
}