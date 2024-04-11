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
const int N=300005,mod=998244353;
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
int n,s;
int a[N];
int p[N],q[N];
int main(){
	n=read(),s=0;
	For(i,1,n)
		a[i]=read(),s+=a[i];
	if (s==1)
		return puts("0"),0;
	p[0]=n-1;
	int invn=Pow(n-1,mod-2);
	For(i,1,s-1){
		//p[i]=(p[i]+p[i-1]+1)*i/s+(p[i]+1)*(s-i)/s*(n-2)/(n-1)+1*(s-i)/s/(n-1);
		//(1-i/s-(s-i)/s*(n-2)/(n-1))p[i]=(p[i-1]+1)*i/s+(s-i)/s*(n-2)/(n-1)+(s-i)/s/(n-1)
		//((s-i)/s/(n-1))p[i]=(p[i-1]+1)*i/s+(s-i)/s
		//				=p[i-1]*i/s+1
		int v=(LL)i*Pow(s,mod-2)%mod;
		int mv=Del(1-v);
		p[i]=((LL)p[i-1]*v+1)%mod*Pow((LL)mv*invn%mod,mod-2)%mod;
	}
	q[s]=0;
	Fod(i,s-1,0)
		q[i]=Add(p[i]+q[i+1]);
//	outarr(p,0,s);
//	outarr(q,0,s);
	int ans=Del(-(LL)(n-1)*q[0]%mod);
	For(i,1,n)
		Add(ans,q[a[i]]);
	ans=(LL)ans*Pow(n,mod-2)%mod;
	cout<<ans<<endl;
	return 0;
}
/*
Ei=E'i-sum(j!=i)(Ej+C*Pj)
sum(Ei)=sum(E'i)-(n-1)sum(Ei+C*Pi)
	   =sum(E'i)-(n-1)(ans+C)
n*ans = sum(E'i)-(n-1)*C
C=p[0]
*/