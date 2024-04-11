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
const int N=2505;
const LD Eps=1e-13L;
int n;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x,y=_y;
	}
	friend P operator + (P a,P b){
		return P(a.x+b.x,a.y+b.y);
	}
	friend P operator - (P a,P b){
		return P(a.x-b.x,a.y-b.y);
	}
}p[N];
LL cross(P a,P b){
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
int getp(P a){
	if (a.x>=0&&a.y>=0)
		return 0;
	if (a.y>=0)
		return 1;
	if (a.x<=0)
		return 2;
	return 3;
}
int check1(P a,P b){
	int pa=getp(a),pb=getp(b);
	if (pa!=pb)
		return pa<pb;
	return cross(a,b)>0;
}
int check2(P a,P b){
	return cross(a,b)>0;
}
LL calc(vector <P> v){
	sort(v.begin(),v.end(),check1);
	int n=(int)v.size();
	For(i,0,n-1)
		v.pb(v[i]);
	LL res=(LL)n*(n-1)*(n-2)/6;
	int p=0;
	For(i,0,n-1){
		p=max(p,i);
		while (p+1<(int)v.size()&&p+1<i+n&&check2(v[i],v[p+1]))
			p++;
		int c=p-i;
		res-=(LL)c*(c-1)/2;
	}
//	outval(res);
	return res;
}
int main(){
	n=read();
	For(i,1,n)
		p[i].x=read(),p[i].y=read();
	LL ans=0;
	For(i,1,n){
		vector <P> v;
		For(j,1,n)
			if (j!=i)
				v.pb(p[j]-p[i]);
		ans+=calc(v)*(n-4);
	}
	cout<<ans/2<<endl;
	return 0;
}