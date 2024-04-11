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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ll> naive(vi p)
{
	int n=p.size();
	vi pos(n);
	for(int i=0;i<n;i++)
	{
		pos[p[i]]=i;
	}
	vector<ll> res;
	ll invs=0;
	ll tmpsum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(pos[i]<pos[j]) invs++;
		}
		vi tmp;
		for(int j=0;j<=i;j++)
		{
			tmp.pb(pos[j]);
		}
		sort(tmp.begin(),tmp.end());
		tmpsum=0;
		vi coeff(int(tmp.size())-1);
		int m=tmp.size()-1;
		int l=0; int r=m-1;
		int cnt=1;
		while(l<=r)
		{
			coeff[l]=cnt;
			coeff[r]=cnt;
			l++; r--; cnt++;
		}
		for(int j=0;j+1<tmp.size();j++)
		{
			int siz=tmp[j+1]-tmp[j]-1;
			tmpsum+=siz*ll(coeff[j]);
		}
		res.pb(invs+tmpsum);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi pos(n); vi p;
	//for(int i=0;i<n;i++) p.pb(i);
	//random_shuffle(p.begin(),p.end());
	for(int i=0;i<n;i++)
	{
		int x; 
		cin>>x; x--; p.pb(x);
		//x=p[i];
		pos[x]=i;
	}
	pbds T;
	ll ans = 0;
	ll tmpsum = 0;
	vector<ll> R;
	for(int i=0;i<n;i++)
	{
		T.insert(pos[i]);
		int id = T.order_of_key(pos[i]);
		ans += i-id; //# of inversions
		if(i%2==0) //there are odd number of splitters now
		{
			int midpt = (*T.find_by_order(i/2));
			if(id<i/2)
			{
				tmpsum+=midpt-pos[i]-(i/2-id);
				tmpsum-=id;
			}
			else if(id==i/2)
			{
				tmpsum-=(i/2);
			}
			else
			{
				tmpsum+=pos[i]-midpt-(id-i/2);
				tmpsum-=(i-id);
			}
		}
		else
		{
			int midl = (*T.find_by_order(i/2));
			int midr = (*T.find_by_order(i/2+1));
			if(id<=i/2)
			{
				tmpsum+=midr-pos[i]-((i/2+1)-id);
				tmpsum-=id;
			}
			else
			{
				tmpsum+=pos[i]-midl-(id-i/2);
				tmpsum-=(i-id);
			}
		}
		//cerr<<"ANS: "<<ans<<' '<<tmpsum<<'\n';
		R.pb(ans+tmpsum);
		cout<<ans+tmpsum<<' ';
	}
	/*
	vector<ll> tmp=naive(p);
	cerr<<"\n"<<"NAIVE\n";
	for(ll x:tmp)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	assert(R==naive(p));
	*/
}