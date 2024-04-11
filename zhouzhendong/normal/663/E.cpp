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
const int N=1<<20;
int k,n;
int a[N];
LL c[N];
LL d[N][21];
int main(){
	k=read(),n=read();
	For(i,0,k-1)
		For(j,1,n){
			int x;
			scanf("%1d",&x);
			a[j]|=x<<i;
		}
	For(i,1,n)
		c[a[i]]++;
	int m=(1<<k)-1;
	For(i,0,m)
		d[i][__builtin_popcount(i)]=1;
	For(i,0,k-1)
		For(j,0,m)
			if (~j>>i&1){
				{
					LL x=c[j],y=c[j|1<<i];
					c[j]=x+y,c[j|1<<i]=x-y;
				}
				{
					For(t,0,k){
						LL x=d[j][t],y=d[j|1<<i][t];
						d[j][t]=x+y,d[j|1<<i][t]=x-y;
					}
				}
			}
	For(i,0,m)
		For(j,0,k)
			d[i][j]*=c[i];
	For(i,0,k-1)
		For(j,0,m)
			if (~j>>i&1){
				For(t,0,k){
					LL x=d[j][t],y=d[j|1<<i][t];
					d[j][t]=(x+y)/2,d[j|1<<i][t]=(x-y)/2;
				}
			}
	int ans=1e9;
	For(i,0,m){
		int now=0;
		LL sum=0;
		For(j,0,k){
			sum+=d[i][j];
			now+=min(j,k-j)*d[i][j];
		}
//		assert(sum==n);
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}