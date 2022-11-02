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
const int N=400010;
LL n,m,k;
LL a[N];
void IN(){
	n=read(),m=read(),k=read();
	LL las=0;
	For(i,1,m){
		LL now=read();
		a[i]=now-las;
		las=now;
	}
	++m;
	a[m]=n-las;
	k+=m;
}
LL D,U;
int checkD(LL lim){
	LL s=0;
	For(i,1,m){
		if (a[i]<lim)
			return 0;
		s+=a[i]/lim;
	}
	return s>=k;
}
void getD(){
	LL L=D=1,R=n;
	while (L<=R){
		LL mid=(L+R)>>1;
		if (checkD(mid))
			L=mid+1,D=mid;
		else
			R=mid-1;
	}
}
int checkU(LL lim){
	LL s=0;
	For(i,1,m)
		s+=(a[i]+lim-1)/lim;
	return s<=k;
}
void getU(){
	LL L=1,R=U=n;
	while (L<=R){
		LL mid=(L+R)>>1;
		if (checkU(mid))
			R=mid-1,U=mid;
		else
			L=mid+1;
	}
}
vector <pair <LL,LL> > v;
int check1(){
	v.clear();
	For(i,1,m){
		//D<=floor(ai/d)<=ceil(ai/d)<=U
		//D<=ai/d, d<=floor(ai/D);  U>=ai/d, d>=ceil(ai/U);
		LL x=a[i]/D,y=(a[i]+U-1)/U;
		if (y>x)
			//xi=floor(ai/y)<D, yi=ceil(ai/x)>U
			v.pb(mp(a[i]/y,(a[i]+x-1)/x));
	}
	return v.empty();
}
void solve(){
	IN();
	getD(),getU();
	if (check1())
		return (void)printf("%lld\n",U-D);
	sort(v.begin(),v.end());
	LL mx=U;
	LL ans=mx-v[0].fi;
	v.pb(mp(D,U));
	For(i,0,(int)v.size()-2){
		mx=max(mx,v[i].se);
		ans=min(ans,mx-v[i+1].fi);
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	For(_,1,T)
		solve();
	return 0;
}