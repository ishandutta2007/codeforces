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
const int N=100005;
const ULL mod=1ULL<<58;
ULL Pow(ULL x,ULL y){
	ULL ans=1;
	for (;y;y>>=1,x*=x)
		if (y&1)
			ans*=x;
	return ans;
}
int n;
ULL inv5=Pow(5,mod/2-1);
struct P{
	ULL v[4];
	P(){clr(v);}
	P(ULL x){
		clr(v),v[0]=x;
	}
	friend P operator + (P a,P b){
		For(i,0,3)
			a.v[i]+=b.v[i];
		return a;
	}
	friend P operator - (P a,P b){
		For(i,0,3)
			a.v[i]-=b.v[i];
		return a;
	}
	friend P operator * (P a,P b){
		ULL v[7];
		clr(v);
		For(i,0,3)
			For(j,0,3)
				v[i+j]+=a.v[i]*b.v[j];
		Fod(i,6,4)
			For(j,1,4)
				v[i-j]-=v[i];
		For(i,0,3)
			a.v[i]=v[i];
		return a;
	}
}w[10],a[N];
P PowP(P x,int y){
	P ans(1);
	for (;y;y>>=1,x=x*x)
		if (y&1)
			ans=ans*x;
	return ans;
}
void DFT10(P *a,int dim,int flag){
	int n=1e5;
	if (flag<0)
		reverse(w+1,w+10);
	For(d,0,dim-1){
		int base=Pow(10ULL,(ULL)d);
		For(i,0,n-1)
			if (i/base%10==0){
				P x[10],y[10];
				For(j,0,9)
					x[j]=a[i+base*j];
				For(j,0,9)
					For(k,0,9)
						y[j]=y[j]+x[k]*w[j*k%10];
				For(j,0,9)
					a[i+base*j]=y[j];
			}
	}
	if (flag<0){
		reverse(w+1,w+10);
		ULL inv=Pow(inv5,5);
		For(i,0,n-1){
			assert(a[i].v[1]==0&&a[i].v[2]==0&&a[i].v[3]==0);
			a[i].v[0]>>=5,a[i].v[0]*=inv;
		}
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[read()].v[0]++;
	w[0].v[0]=1,w[1].v[3]=-1;
	For(i,2,9)
		w[i]=w[i-1]*w[1];
	DFT10(a,5,1);
	For(i,0,1e5-1)
		a[i]=PowP(a[i],n);
	DFT10(a,5,-1);
	For(i,0,n-1)
		printf("%llu\n",(a[i].v[0]&(mod-1)));
	return 0;
}