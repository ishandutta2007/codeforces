#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[(1<<21)+10];
int mark[(1<<21)+10];
int moves[(1<<21)+10];

int lc(int u) {return 2*u+1;}
int rc(int u) {return 2*u+2;}
int cnt=0;

int getft(int u)
{
	int l = lc(u); int r = rc(u);
	if(a[l]==0&&a[r]==0) return u;
	if(a[l]>a[r]) return getft(l);
	else return getft(r);
}

void pushft(int u)
{
	int l = lc(u); int r = rc(u);
	if(a[l]==0&&a[r]==0) {a[u]=0; return ;}
	if(a[l]>a[r]) {a[u]=a[l]; pushft(l);}
	else {a[u]=a[r]; pushft(r);}
}

void run(int u)
{
	//cerr<<"RUN "<<u<<' '<<a[u]<<'\n';
	if(a[u]==0) return ;
	int l = lc(u); int r = rc(u);
	if(a[l]==0&&a[r]==0) return ;
	int ft = getft(u);
	if(mark[ft])
	{
		run(l); run(r); return ;
	}
	moves[cnt++]=u;
	pushft(u);
	run(u);
}

void solve()
{
	int h,g; scanf("%d %d",&h,&g);
	int n=(1<<h)-1; int m=(1<<g)-1;
	for(int i=0;i<=2*n;i++) a[i]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		mark[i]=0;
	}
	cnt=0;
	for(int i=n;i<=2*n;i++) mark[i]=0;
	for(int i=0;i<m;i++)
	{
		mark[i]=1;
	}
	run(0);
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		ans+=a[i];
	}
	printf("%lld\n", ans);
	for(int i=0;i<n-m;i++)
	{
		printf("%d",moves[i]+1);
		if(i+1<n-m) printf(" ");
	}
	printf("\n");
}

int main()
{
	int t; scanf("%d",&t);
	while(t--) solve();
}