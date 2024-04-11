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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=400005;
int n;
int a[N];
pii p[N];
int cnt;
int r,c;
int _ans[N];
#define ans(n,m) _ans[(n)*c+m]
int gonext(int &x,int &y){
	x=(x+1)%r;
	if (ans(x,y)){
		if (y==c-1)
			return 0;
		y++;
	}
	return 1;
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1);
	cnt=0;
	For(i,1,n){
		if (a[i]!=p[cnt].se)
			cnt++,p[cnt].se=a[i];
		p[cnt].fi++;
	}
	sort(p+1,p+cnt+1);
	int sq=(int)sqrt(n);
	int sum=0,pos=0;
	r=0,c=0;
	For(i,1,sq){
		while (pos<cnt&&p[pos+1].fi<=i)
			pos++,sum+=p[pos].fi;
		int nr=i,nc=(sum+i*(cnt-pos))/nr;
		if (nr<=nc&&nr*nc>r*c)
			r=nr,c=nc;
	}
	For(i,1,cnt)
		ckmin(p[i].fi,r);
	int x=0,y=0;
	Fod(i,cnt,1){
		int flag=0;
		while (p[i].fi--){
			ans(x,y)=p[i].se;
			if (!gonext(x,y)){
				flag=1;
				break;
			}
		}
		if (flag)
			break;
	}
	printf("%d\n%d %d\n",r*c,r,c);
	For(i,0,r-1){
		For(j,0,c-1)
			printf("%d ",ans(i,(j-i+c)%c));
		puts("");
	}
	return 0;
}