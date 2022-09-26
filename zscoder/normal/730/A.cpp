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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[101];
vector<string> vec;
int n;

void move(int a, int b)
{
	string s;
	for(int i = 0; i < n; i++)
	{
		if(i!=a&&i!=b)
		{
			s += '0';
		}
		else
		{
			s += '1';
		}
	}
	vec.pb(s);
}

void move3(int a, int b, int c)
{
	string s;
	for(int i = 0; i < n; i++)
	{
		if(i!=a&&i!=b&&i!=c)
		{
			s += '0';
		}
		else
		{
			s += '1';
		}
	}
	vec.pb(s);
}

bool done()
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] != a[0])
		{
			return false;
		}
	}
	return true;
}

bool isgood()
{
	int mi = 1000; int ma = 0;
	for(int i = 0; i < n; i++)
	{
		mi = min(a[i], mi);
		ma = max(a[i], ma);
	}
	if(ma == mi) return 0;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i]==ma) cnt++;
		else if(a[i]!=mi) return 0;
	}
	if(cnt==3) return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	priority_queue<ii> pq;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		pq.push(mp(a[i],i));
	}
	while(!done())
	{
		if(isgood())
		{
			int x = pq.top().se;
			pq.pop();
			int y = pq.top().se;
			pq.pop();
			int z = pq.top().se;
			pq.pop();
			if(a[x]>0) a[x]--;
			if(a[y]>0) a[y]--;
			if(a[z]>0) a[z]--;
			pq.push(mp(a[x],x));
			pq.push(mp(a[y],y));
			pq.push(mp(a[z],z));
			move3(x,y,z);
		}
		else
		{
			int x = pq.top().se;
			pq.pop();
			int y = pq.top().se;
			pq.pop();
			if(a[x]>0) a[x]--;
			if(a[y]>0) a[y]--;
			pq.push(mp(a[x],x));
			pq.push(mp(a[y],y));
			move(x,y);
		}
	}
	cout << a[0] << '\n';
	cout << vec.size() << '\n';
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
}