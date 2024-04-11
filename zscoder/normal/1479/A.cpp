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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<int,int> ma;
int n; 
const int INF = int(1e9);
int ask(int x)
{
	if(x<=0||x>n) return INF;
	if(!ma.count(x))
	{
		cout<<"? "<<x<<'\n';
		fflush(stdout);
		int y; cin>>y; 
		return (ma[x]=y);
	}
	return ma[x];
}

void answer(int x)
{
	cout<<"! "<<x<<'\n';
	fflush(stdout);
}

void check(int x)
{
	int cur=ask(x);
	int l = ask(x-1);
	int r = ask(x+1);
	if(cur<l&&cur<r) 
	{
		answer(x); exit(0);
	}
}

void solve(int l, int r)
{
	if(r-l+1<=5)
	{
		for(int i=l;i<=r;i++) check(i); return ;
	}
	//a[l]>a[l+1], a[r-1]<a[r]
	int mid=(l+r)>>1;
	check(mid);
	if(ask(mid)>ask(mid+1))
	{
		solve(mid,r);
	}
	else
	{
		solve(l,mid+1);
	}
}

int main()
{
	cin>>n;
	check(1); check(n);
	solve(1,n);
}