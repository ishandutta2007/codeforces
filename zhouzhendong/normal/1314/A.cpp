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
map <int,vi> mp;
multiset <int> S;
int aa[N],tt[N];
int main(){
	n=read();
	For(i,1,n)
		aa[i]=read();
	For(i,1,n)
		tt[i]=read();
	For(i,1,n)
		mp[aa[i]].pb(tt[i]);
	int mi=0;
	LL ans=0,sum=0;
	for (auto p : mp){
//		outval(p.fi);outarr(p.se,0,(int)p.se.size()-1);
		while (!S.empty()&&mi<p.fi){
			sum-=*prev(S.end()),ans+=sum;
			S.erase(prev(S.end()));
			++mi;
		}
		if (S.empty())
			mi=max(mi,p.fi);
		for (auto i : p.se)
			S.insert(i),sum+=i;
	}
	while (!S.empty()){
		sum-=*prev(S.end()),ans+=sum;
		S.erase(prev(S.end()));
		++mi;
	}
	cout<<ans<<endl;
	return 0;
}