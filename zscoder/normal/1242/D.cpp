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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void genNormal(ll n, ll k)
{
	vector<ll> vec;
	set<ll> S;
	ll cur=1;
	while(vec.size()<n)
	{
		ll sum=0;
		for(int i=0;i<k;i++)
		{
			while(S.find(cur)!=S.end()) cur++;
			vec.pb(cur); S.insert(cur); sum+=cur;
		}
		vec.pb(sum); S.insert(sum);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(i%(k+1)==0)
		{
			cout<<"GROUP "<<setw(3)<<i/(k+1)+1<<": ";
		}
		cout<<setw(6)<<vec[i]-(i/(k+1))*(k*k+1)<<' ';
		if(i%(k+1)==k) 
		{
			cout<<"|"<<setw(6)<<vec[i]-(k*(k+1))/2;//(vec[i]+k-1-cnt)/k;
			cnt++;
			if(i>k) cout<<"|"<<setw(7)<<(vec[i]+k-1-(cnt-1))/k-(vec[i-(k+1)]+k-1-(cnt-2))/k;
			cout<<'\n';
		}
	}
}
const ll INF=ll(6e18);
ll mult(ll a, ll b)
{
	if(b==0||a==0) return 0;
	if(a>INF/b) return INF;
	return a*b;
}
/*
ll getmaxL(ll r, ll k)
{
	if(k%2==0)
	{
		return mult(r,k)+(r-(k/2+1))/k+1;
	}
	else
	{
		ll R = r-(k/2+1);
		ll extra = (R/(k*k))*k+1;
		ll rem = R%(k*k);
		if(rem<=k*(k/2))
		{
			extra+=rem/k;
		}
		else
		{
			extra+=k/2;
			rem-=k*(k/2);
			if(rem>=k*(k/2+1))
			{
				extra+=k/2+1;
			}
			else if(rem>=k+1)
			{
				rem--;
				extra+=rem/k;
			}
		}
		return mult(r,k)+extra;
	}
}

ll f(ll r, ll k)
{
	if(k%2==0)
	{
		ll sum = (k*(k+1))/2;
		ll ext = 0;
		if(r>=(k/2+2)) ext=((r-(k/2+2))/k+1)*k;
		if(r%k==(k/2+1))
		{
			sum+=k*k*r+ext+//sth;
		}
		else
		{
			sum+=k*k*r+ext;
		}
		return sum;
	}
	else
	{
		
	}
}
*/

ll missing(ll r, ll k) //which index is missing on set r
{
	if(r==0)
	{
		return (k*(k+1))/2;
	}
	ll las = missing(r/k,k);
	ll t = r%k;
	ll offset = 0;
	las--;
	if(las<=t*k)
	{
		offset=k;
	}
	else
	{
		if(las<=(t+1)*k)
		{
			offset=(t+1)*k-las;
		}
	}
	//cerr<<"R: "<<r<<' '<<offset<<' '<<las<<'\n';
	return (k*(k+1))/2-t+offset;	
}

ll getmissingno(ll r, ll k)
{
	 return r*(k*k+1)+missing(r,k);
}

ll solve(ll n, ll k)
{
	ll group = (n-1)/(k*k+1);
	if(getmissingno(group,k)==n)
	{
		return (group+1)*(k+1);
	}
	else
	{
		//cerr<<"HERE\n";
		ll missingval = missing(group,k);
		ll rem = (n-1)%(k*k+1)+1;
		assert(rem!=missingval);
		if(rem>=missingval) rem--;
		ll pos = ((rem-1)/k)*(k+1)+(rem-1)%k+1;
		//cerr<<group<<' '<<pos<<'\n';
		return k*(k+1)*group+pos;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ll n; ll k; cin>>n>>k;
	//genNormal(n,k);
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<' '<<missing(i,k)<<'\n';
	}
	*/
	//return 0;
	int t; cin>>t;
	while(t--)
	{
		ll n; ll k; cin>>n>>k;
		//genNormal(n,k);
		cout<<solve(n,k)<<'\n';
	}
}