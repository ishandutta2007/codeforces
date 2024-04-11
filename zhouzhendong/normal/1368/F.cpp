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
const int N=1005;
int n,k;
int a[N],b[N];
int f(int x){
	return (n+x-1)/x+x-1;
}
vi get(){
	vi s;
	For(i,0,n-1)
		if (b[i]&&!a[i])
			s.pb(i);
	if (s.size()<k){
		puts("0");
		fflush(stdout);
		exit(0);
	}
	s.resize(k);
	return s;
}
void gao(vi v){
	printf("%d",(int)v.size());
	for (auto i : v)
		printf(" %d",i+1),a[i]=1;
	puts("");
	fflush(stdout);
	int t=read()-1;
	For(i,0,k-1)
		a[(t+i)%n]=0;
}
int main(){
	n=read();
	k=1;
	For(i,2,n)
		if (f(i)<f(k))
			k=i;
	For(i,0,n-2)
		b[i]=i%k<k-1;
	while (1)
		gao(get());
	return 0;
}