#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const bool DEBUG=0;
int a;
int cnt=0;
int ask(int x, int y)
{
	cnt++;
	if(DEBUG)
	{
		if(x%a>=y%a) return 1;
		else return 0;
	}
	cout<<"? "<<x<<' '<<y<<'\n';
	fflush(stdout);
	char c; cin>>c;
	if(c=='x') return 1;
	else return 0;
}

void output(int x)
{
	cout<<"! "<<x<<'\n';
	if(DEBUG) assert(x==a);
	fflush(stdout);
}

void solve_case()
{
	cnt=0;
	int l=1; int r=1;
	while(1)
	{
		//is a in [l,r]?
		int tmp = ask(l-1,r); //is (r mod a) >= l
		if(!tmp)
		{
			//yes, so a > r
			r*=2; r++; l*=2;
		}
		else
		{
			//a is in [l,r]
			break;
		}
	}
	int lo=l; int hi=r;
	int ans = 0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		int tmp = ask(l-1,mid); //is (mid mod a) <= l-1
		if(tmp)
		{
			ans=mid; hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	assert(cnt<=60);
	output(ans);
}

int main()
{
	int t=1000;
	while(1)
	{
		string s; 
		if(DEBUG)
		{
			a=((rand()<<15)^rand())%int(10)+1; solve_case(); t--; 
			if(t==0) return 0;
			continue;
		}
		cin>>s;
		if(s!="start") return 0;
		solve_case();
	}
}