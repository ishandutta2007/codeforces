#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n,a[M],b[M],m;
multiset<LL> g[500];
LL as[M];
vector<LL> t[500];
int ct;
void add(int x,int y){
	F(i,1,ct){
		LL o=t[i][x%a[i]];
		
		g[i].erase(g[i].lower_bound(o));
		
		o+=y;
		t[i][x%a[i]]=o;
		g[i].insert(o);
		as[i]=*g[i].rbegin();
	}
}
void ADD(int i){
	a[++ct]=i;
	g[ct].clear();
	t[ct].resize(i);
	as[i]=0;
	F(j,0,i-1) t[ct][j]=0,g[ct].insert(0);
}
void work(){
	n=read(); m=read(); ct=0;
	int o=n;
	F(i,2,n){
		if (o%i==0){
			if (i==n) ADD(1);
			else ADD(n/i);
			while (o%i==0) o/=i;
		}
	}
	F(i,1,n){
		b[i]=read();
		add(i,b[i]);
	}
	LL ans=0;
	F(j,1,ct){
		ans=max(ans,as[j]*a[j]);
	}
	cout<<ans<<"\n";
	F(i,1,m){
		int x=read(),y=read();
		add(x,y-b[x]);
		b[x]=y;
		ans=0;
		F(j,1,ct){
			ans=max(ans,as[j]*a[j]);
		}
		cout<<ans<<"\n";
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
4 0
4 1 3 2
*/