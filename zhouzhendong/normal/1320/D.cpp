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
#define outtime() cerr<<"User Time = "<<(double)clock()/CLOCKS_PER_SEC<<endl
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
const int mod=998244353;
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
int inv(int x){
	return Pow(x,mod-2);
}
const int N=2e5+5;
int n;
int a[N];
int b[2]={348323,238234},ib0[2]={inv(b[0]),inv(b[1])};
pii o(pii a,pii b){
	//a(b(x))=a.fi(b.fi*x+b.se)+a.se
	return pii((LL)a.fi*b.fi%mod,((LL)a.fi*b.se+a.se)%mod);
}
pii arc(pii a){
	//a(b(x))=a.fi(b.fi*x+b.se)+a.se
	//a.fi*b.fi=1,a.fi*b.se+a.se=0
	pii b;
	b.fi=inv(a.fi);
	b.se=(LL)Del(-a.se)*b.fi%mod;
	return b;
}
pii h[N][2];
pii geth(int L,int R,int k){
	return o(h[R][k],arc(h[L-1][k]));
}
int main(){
	n=read();
	For(i,1,n)
		scanf("%1d",&a[i]);
	h[0][0]=h[0][1]=mp(1,0);
	For(i,1,n)
		For(j,0,0)
			if (a[i]==1)
				h[i][j]=o(mp(mod-1,0),h[i-1][j]);
			else
				h[i][j]=o(mp(b[j],1),h[i-1][j]);
	int q=read();
	while (q--){
		int l1=read(),l2=read(),len=read(),r1=l1+len-1,r2=l2+len-1;
		int flag=0;
		For(i,0,0)
			if (geth(l1,r1,i)!=geth(l2,r2,i))
				flag=1;
		puts(flag?"No":"Yes");
	}
	return 0;
}