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
const int N=100005*3;
int n;
int a[N];
int b[N];
int st[N][20],ts[N][20];
int Log[N];
int querymax(int L,int R){
	int d=Log[R-L+1];
	return max(st[L+(1<<d)-1][d],st[R][d]);
}
int querymin(int L,int R){
	int d=Log[R-L+1];
	return min(ts[L+(1<<d)-1][d],ts[R][d]);
}
int findmi(int i,int v){
	int L=i,R=n*3,ans=R+1;
	while (L<=R){
		int mid=(L+R)>>1;
		if (querymin(i,mid)<v)
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	return ans;
}
int findmx(int i,int v){
	int L=i,R=n*3,ans=R+1;
	while (L<=R){
		int mid=(L+R)>>1;
		if (querymax(i,mid)>=v)
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	return ans;
}
int main(){
	n=read();
	a[0]=1e9;
	For(i,1,n)
		a[i]=a[i+n]=a[i+n+n]=read();
	For(i,2,n*3)
		Log[i]=Log[i/2]+1;
	For(i,1,n*3){
		st[i][0]=ts[i][0]=a[i];
		For(j,1,19){
			st[i][j]=st[i][j-1];
			ts[i][j]=ts[i][j-1];
			if (i-(1<<(j-1))>0){
				ckmax(st[i][j],st[i-(1<<(j-1))][j-1]);
				ckmin(ts[i][j],ts[i-(1<<(j-1))][j-1]);
			}
		}
	}
	b[n*3+1]=n*3+1;
	Fod(i,n*3,1){
		b[i]=i;
		int mi=findmi(i,(a[i]+1)/2);
		int mx=findmx(i+1,a[i]);
		if (mx<mi)
			b[i]=b[mx];
		else
			b[i]=mi-1;
	}
	For(i,1,n){
		printf("%d ",b[i]-i>=n*2?-1:b[i]-i+1);
	}
	return 0;
}