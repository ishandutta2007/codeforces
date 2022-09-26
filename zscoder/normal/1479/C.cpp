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

vector<pair<ii,int> > vec;

void add(int u, int v, int c)
{
	vec.pb({{u,v},c});
}

int digits[20];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int L,R; cin>>L>>R;
	if(L==R)
	{
		cout<<"YES\n";
		cout<<2<<' '<<1<<'\n';
		cout<<1<<' '<<2<<' '<<L<<'\n'; return 0;
	}
	if(L==1&&R==2)
	{
		cout<<"YES\n";
		cout<<3<<' '<<3<<'\n';
		cout<<1<<' '<<2<<' '<<1<<'\n'; 
		cout<<2<<' '<<3<<' '<<1<<'\n';
		cout<<1<<' '<<3<<' '<<1<<'\n';
		return 0;
	}
	int n=0;
	int X = max(L-1,1);
	//i add edges in reverse order
	for(int i=1;i<=20;i++)
	{
		add(i,0,X);
		for(int j=1;j<i;j++)
		{
			add(i,j,(1<<(j-1)));
		}
	}
	int oriL = L;
	//ok, now process the remainder
	if(L==1)
	{
		L=2;
	}
	int remainder = R-L;
	assert(remainder>0);
	for(int i=19;i>=0;i--)
	{
		if(remainder&(1<<i)) digits[i]=1;
	}
	int cur=0;
	n=22; //auto add 2 new vertices
	add(n-1,1,1);
	while(cur<=19)
	{
		if(!digits[cur]) {cur++; continue;}
		int l = cur;
		int r = cur;
		int cost=0;
		for(int i=cur;i<=19;i++)
		{
			if(!digits[i]) break;
			r=i;
			cost^=(1<<i);
		}
		//l to r
		//node n-2 and n-1 connects
		n++;
		add(n-1,n-2,cost);
		int sum=0;
		for(int i=r;i>=l;i--)
		{
			add(n-1,i+1,sum+1); 
			sum+=(1<<i);
		}
		cur=r+1;
	}
	if(oriL==1)
	{
		add(n-1,0,1); //add an extra shortcut
	}
	cout<<"YES\n";
	cout<<n<<' '<<vec.size()<<'\n';
	assert(n<=32);
	for(auto X:vec)
	{
		//cerr<<X.fi.fi<<' '<<X.fi.se<<' '<<X.se<<'\n';
		cout<<n-X.fi.fi<<' '<<n-X.fi.se<<' '<<X.se<<'\n';
	}
}