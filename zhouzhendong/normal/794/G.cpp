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
typedef unsigned long long ull;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
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
int md(int x){
	return (x%mod+mod)%mod;
}
const int N=300005*2;
int fac[N],ifac[N],pow2[N];
void prework(){
	int n=N-1;
	fac[0]=1;
	For(i,1,n)
		fac[i]=(LL)fac[i-1]*i%mod;
	ifac[n]=Pow(fac[n],mod-2);
	Fod(i,n,1)
		ifac[i-1]=(LL)ifac[i]*i%mod;
	pow2[0]=1;
	For(i,1,n)
		pow2[i]=2LL*pow2[i-1]%mod;
}
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return (LL)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n;
string s1,s2;
int a1,b1,c1,a2,b2,c2;
int sign(int x){
	return (x>0)-(x<0);
}
int shit[N];
int main(){
	prework();
	cin>>s1>>s2;
	n=read();
	for (auto c : s1)
		if (c=='A')
			a1++;
		else if (c=='B')
			b1++;
		else
			c1++;
	for (auto c : s2)
		if (c=='A')
			a2++;
		else if (c=='B')
			b2++;
		else
			c2++;
	int ans=0;
	For(i,0,c1+c2){
		int ta=a1-a2,tb=b1-b2;
		ta+=c1-i;
		tb+=-c2+i;
		if (sign(ta)!=sign(-tb))
			continue;
		if (!ta&&!tb){
			int res=0;
			clr(shit);
			Fod(i,n,1){
				Add(shit[i],(LL)(n/i)*(n/i)%mod);
				for (int j=i<<1;j<=n;j+=i)
					Del(shit[i],shit[j]);
				Add(res,(LL)shit[i]*pow2[i]%mod);
			}
//			outarr(shit,1,n);
			Add(ans,(LL)C(c1+c2,i)*res%mod);
			int cnt=0;
			For(i,0,(int)s1.size()-1){
				if (s1[i]=='?'&&s2[i]=='?')
					cnt++;
				else if (s1[i]!='?'&&s2[i]!='?'&&s1[i]!=s2[i]){
					cnt=-1;
					break;
				}
			}
			if (cnt!=-1){
				int way=Del(pow2[n+1]-2);
				way=(LL)way*way%mod;
				Add(ans,(LL)pow2[cnt]*Del(way-res)%mod);
			}
			continue;
		}
		ta=abs(ta),tb=abs(tb);
		int g=__gcd(ta,tb);
		ta/=g,tb/=g;
		Add(ans,(LL)C(c1+c2,i)*Del(pow2[n/max(ta,tb)+1]-2)%mod);
	}
	cout<<ans<<endl;
	return 0;
}