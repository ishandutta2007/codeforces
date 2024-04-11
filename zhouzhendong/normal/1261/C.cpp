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
*/
const int N=4e6+5,INF=1e9;
int n,m;
int v[N],s[N],ans[N],a[N];
#define s(a,b) s[(a)*(m+2)+b]
#define v(a,b) v[(a)*(m+2)+b]
#define ans(a,b) ans[(a)*(m+2)+b]
#define a(x,y) a[(x)*(m+2)+y]
inline int calc_s(int x0,int y0,int x1,int y1){
	return s(x1,y1)-s(x0-1,y1)-s(x1,y0-1)+s(x0-1,y0-1);
}
int check(int x){
	For(i,1,n)
		For(j,1,m)
			a(i,j)=0;
	For(i,1,n-x*2)
		For(j,1,m-x*2)
			if (v(i,j)&&!calc_s(i,j,i+x*2,j+x*2)){
				ans(i+x,j+x)=x;
				a(i,j)++;
				a(i+x*2+1,j)--;
				a(i,j+x*2+1)--;
				a(i+x*2+1,j+x*2+1)++;
			}
	For(i,1,n)
		For(j,1,m){
			a(i,j)=a(i,j)+a(i-1,j)+a(i,j-1)-a(i-1,j-1);
			if (v(i,j)&&!a(i,j))
				return 0;
		}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
//	For(i,0,n+1){
//		v[i].resize(m+2);
//		s[i].resize(m+2);
//		ans[i].resize(m+2);
//		a[i].resize(m+2);
//		now[i].resize(m+2);
//	}
	For(i,1,n){
		string s;
		cin>>s;
		For(j,1,m)
			v(i,j)=s[j-1]=='X';
	}
	For(i,1,n)
		For(j,1,m)
			s(i,j)=(v(i,j)==0)+s(i-1,j)+s(i,j-1)-s(i-1,j-1);
	int L=0,R=max(n,m),cnt=0;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,cnt=mid;
		else
			R=mid-1;
	}
	For(i,1,n)
		For(j,1,m)
			ans(i,j)=-1;
	check(cnt);
	cout<<cnt<<endl;
	For(i,1,n){
		For(j,1,m)
			putchar(ans(i,j)==cnt?'X':'.');
		puts("");
	}
	return 0;
}