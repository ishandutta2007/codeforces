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
const int mod=1e9+7;
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
const int N=500005;
int n,k;
int x[N],y[N];
double d[N];
int main(){
	n=read(),k=read();
	vi id;
	For(i,1,n){
		x[i]=read(),y[i]=read();
		d[i]=sqrt((LL)x[i]*x[i]+(LL)y[i]*y[i]);
		if (x[i]!=0||y[i]!=0){
			int g=__gcd(abs(x[i]),abs(y[i]));
			x[i]/=g,y[i]/=g;
		}
		id.pb(i);
	}
	sort(id.begin(),id.end(),[&](int a,int b){
		if (x[a]!=x[b])
			return x[a]<x[b];
		if (y[a]!=y[b])
			return y[a]<y[b];
		return d[a]<d[b];
	});
	vector <double> v;
	for (int i=0,j;i<n;i=j+1){
		for (j=i;j<n-1&&x[id[j+1]]==x[id[j]]&&y[id[j+1]]==y[id[j]];j++);
		int L=i,R=j;
		For(i,0,k/2-1){
			v.pb(d[id[R--]]*(k-1-i*2));
			if (L>R)
				break;
		}
		double sum=0;
		while (L<=R){
			v.pb(-(sum+(k&1?0:d[id[L]])));
			sum+=2*d[id[L]];
			L++;
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	double ans=0;
	For(i,0,k-1)
		ans+=v[i];
	printf("%.7lf\n",ans);
	return 0;
}