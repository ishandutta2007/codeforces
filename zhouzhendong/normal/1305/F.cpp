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
const int N=200005;
int n;
LL ans=N;
LL a[N];
void get(LL x,vector <LL> &v){
	for (int i=2;(LL)i*i<=x;i++)
		while (x%i==0)
			v.pb(i),x/=i;
	if (x>1)
		v.pb(x);
}
void chkans(LL x){
	LL res=0;
	For(i,1,n)
		res+=a[i]<x?x-a[i]:min(a[i]%x,x-a[i]%x);
	ans=min(ans,res);
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	srand(233);
	vector <LL> v;
	random_shuffle(a+1,a+n+1);
	For(x,1,100){
		get(a[x]-1,v);
		get(a[x],v);
		get(a[x]+1,v);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for (auto i : v)
		chkans(i);
	cout<<ans<<endl;
	return 0;
}