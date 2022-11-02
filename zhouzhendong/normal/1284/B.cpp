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
/*
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
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
*/
const int N=100005,INF=1e9;
int n;
vi a[N];
int cnt=0;
vi v0,v1;
int main(){
	n=read();
	For(i,1,n){
		int l=read();
		while (l--)
			a[i].pb(read());
	}
	For(i,1,n){
		int flag=0;
		int mi=INF,mx=-INF;
		for (auto v : a[i]){
			if (v>mi){
				flag=1;
				break;
			}
			mi=min(mi,v);
			mx=max(mx,v);
		}
		if (flag){
			cnt++;
			continue;
		}
		v0.pb(mi),v1.pb(mx);
	}
	LL ans=(LL)cnt*(n-cnt)*2+(LL)cnt*(cnt-1)+cnt;
//	outval(ans);
//	outval(cnt);
	int p=0;
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
//	outarr(v0,0,(int)v0.size()-1);
//	outarr(v1,0,(int)v1.size()-1);
	for (auto i : v0){
		while (p<(int)v1.size()&&v1[p]<=i)
			p++;
		ans+=(int)v1.size()-p;
//		outval(ans);
	}
	cout<<ans<<endl;
	return 0;
}