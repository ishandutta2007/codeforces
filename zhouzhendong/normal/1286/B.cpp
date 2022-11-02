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
const int N=2005;
int n,rt;
int c[N];
vi e[N];
int a[N];
vi solve(int x){
	vi id;
	for (auto i : e[x]){
		vi now=solve(i);
		for (auto y : now)
			id.pb(y);
	}
	sort(id.begin(),id.end(),[&](int x,int y){
		return a[x]<a[y];
	});
	int diff=0;
	For(i,1,(int)id.size()-1){
		diff+=a[id[i]]==a[id[i-1]]-diff;
		a[id[i]]+=diff;
	}
	if (c[x]>(int)id.size()){
		puts("NO");
		exit(0);
	}
	if (c[x]==(int)id.size()){
		a[x]=id.size()+1;
		id.pb(x);
	}
	else {
		a[x]=a[id[c[x]]];
		id.pb(0);
		Fod(i,(int)id.size()-1,c[x]+1){
			id[i]=id[i-1];
			a[id[i]]++;
		}
		id[c[x]]=x;
	}
	return id;
}
int main(){
	n=read();
	For(i,1,n){
		int p=read();
		c[i]=read();
		if (!p)
			rt=i;
		else
			e[p].pb(i);
	}
	solve(rt);
	puts("YES");
	For(i,1,n)
		printf("%d ",a[i]);
	return 0;
}