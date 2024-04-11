#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=50005;
int n,m,mod;
int Pow(int x,int y){
	int ans=1%mod;
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
LL k;
int s[N];
pair <LL,int> b[N];
struct Mat{
	int a00,a01,a10,a11;
	Mat(){}
	Mat(int x){
		a01=a10=0,a00=a11=x%mod;
	}
	Mat(int _a00,int _a01,int _a10,int _a11){
		a00=_a00%mod,a01=_a01%mod,a10=_a10%mod,a11=_a11%mod;
	}
	friend Mat operator * (Mat a,Mat b){
		return Mat(((LL)a.a00*b.a00+(LL)a.a01*b.a10)%mod,
				   ((LL)a.a00*b.a01+(LL)a.a01*b.a11)%mod,
				   ((LL)a.a10*b.a00+(LL)a.a11*b.a10)%mod,
				   ((LL)a.a10*b.a01+(LL)a.a11*b.a11)%mod);
	}
};
Mat Pow(Mat x,LL y){
	Mat ans(1);
	for (;y;y>>=1,x=x*x)
		if (y&1)
			ans=ans*x;
	return ans;
}
Mat val[N<<2];
void build(int rt,int L,int R){
	if (L==R){
		val[rt]=Mat(0,1,L==0?s[n-1]:s[L-1],s[L]);
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	val[rt]=val[rs]*val[ls];
}
Mat Query(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return Mat(1);
	if (xL<=L&&R<=xR)
		return val[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return Query(rs,mid+1,R,xL,xR)*Query(ls,L,mid,xL,xR);
}
unordered_map <LL,int> Mp;
int S(LL x){
	unordered_map <LL,int> :: iterator it=Mp.find(x);
	if (it!=Mp.end())
		return (*it).se;
	return s[x%n];
}
Mat getmat(LL n){
	return Mat(0,1,S(n-1),S(n));
}
int main(){
	k=read(),mod=read();
	n=read();
	For(i,0,n-1)
		s[i]=read()%mod;
	build(1,0,n-1);
	m=read();
	For(i,1,m){
		b[i].fi=read(),b[i].se=read()%mod;
		Mp[b[i].fi]=b[i].se;
	}
	m++;
	b[m].fi=k;
	if (k<=1)
		return cout<<k%mod<<endl,0;
	sort(b+1,b+m+1);
	Mat M(0,0,1,0);
	LL las=1;
	For(i,1,m){
		LL now=b[i].fi;
		if (las+1==now)
			M=getmat(las)*M;
		else {
			M=getmat(las+1)*getmat(las)*M,las+=2;
			if (las<now){
				LL L=las,R=now-1;
				LL idL=L/n,idR=R/n;
				if (idL==idR)
					M=Query(1,0,n-1,L%n,R%n)*M;
				else {
					M=Query(1,0,n-1,L%n,n-1)*M;
					M=Pow(val[1],idR-idL-1)*M;
					M=Query(1,0,n-1,0,R%n)*M;
				}
			}
		}
		las=now;
		if (now==k)
			break;
	}
	cout<<M.a10<<endl;
	return 0;
}