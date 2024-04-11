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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[300001];
int l[300001];
int r[300001];
vi ans;

bool work(int i, int j)
{
	if(a[i] == -1) return false;
	if(a[i]%a[j]==0) return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i+1];
	}
	a[0] = -1;
	stack<int> s; s.push(0);
	for(int i = 1; i <= n; i++)
	{
		while(!s.empty() && work(s.top(), i)) s.pop();
		l[i] = s.top() + 1;
		s.push(i);
	}
	while(!s.empty()) s.pop();
	s.push(n+1); a[n+1] = -1;
	for(int i = n; i >= 1; i--)
	{
		while(!s.empty() && work(s.top(), i)) s.pop();
		r[i] = s.top() - 1;
		s.push(i);
	}
	int maxval = 0;
	for(int i = 1; i <= n; i++)
	{
		if(r[i]-l[i]>maxval)
		{
			maxval = r[i]-l[i];
			ans.clear(); ans.pb(l[i]);
		}
		else if(r[i]-l[i]==maxval) ans.pb(l[i]);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << ' ' << maxval << '\n';
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}