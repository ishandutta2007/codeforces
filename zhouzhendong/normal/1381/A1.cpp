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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (x>y)
		x=y;
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
const int N=100005;
int n;
int a[N],b[N],A[N],B[N];
void check(vi res){
	outarr(A,1,n);
	for (auto i : res){
		reverse(A+1,A+i+1);
		For(j,1,i)
			A[j]^=1;
		outarr(A,1,n);
	}
	For(i,1,n)
		assert(B[i]==A[i]);
}
void solve(){
	n=read();
	For(i,1,n)
		scanf("%1d",&a[i]),A[i]=a[i];
	For(i,1,n)
		scanf("%1d",&b[i]),B[i]=b[i];
	int L=1,R=n;
	vi res;
	int flag=0;
	Fod(i,n,2){
		if (L<R){
//			For(i,L,R)printf("%d",a[i]^flag);puts("");
			assert(R-L+1==i);
			if (a[R]^b[i]^flag){
				if (a[L]^a[R]){
					res.pb(1);
					a[L]^=1;
				}
				res.pb(i);
				swap(L,R);
				flag^=1;
				R++;
			}
			else
				R--;
		}
		else if (R<L){
//			Fod(i,L,R)printf("%d",a[i]^flag);puts("");
			assert(L-R+1==i);
			if (a[R]^b[i]^flag){
				if (a[L]^a[R]){
					res.pb(1);
					a[L]^=1;
				}
				res.pb(i);
				swap(L,R);
				flag^=1;
				R--;
			}
			else
				R++;
		}
		else
			assert(0);
	}
	if (a[L]^b[1]^flag)
		res.pb(1);
	printf("%d ",(int)res.size());
	for (auto i : res)
		printf("%d ",i);
	puts("");
//	check(res);
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}