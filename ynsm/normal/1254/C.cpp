#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
         
int n;
int t1(int i, int j, int k){
	cout << 1 << " " << i << " " << j << " " << k << endl;
	int res;
	cin >> res;
	return res;
}
int t2(int i, int j, int k){
	cout << 2 << " " << i << " " << j << " " << k << endl;
	int res;
	cin >> res;
	return res;
}
vector< int > sa(vector< int > v){
	if(v.empty()){
		vector< int > res;
		return res;
	}

vector< pii > vs;
	for(auto i : v)
		vs.pb({t1(1, 2, i), i});
	sort(vs.begin(), vs.end());
	int mx = vs.back().s;
	vector< int > res, vl, vr;
	for(auto it : vs){
		int i = it.s;
		if(i == mx)
			continue;
		int res = t2(1, mx, i);
		if(res == 1)
			vl.pb(i);
		else
			vr.pb(i);
	}
	reverse(vr.begin(), vr.end());

	for(auto i : vl)
		res.pb(i);
	res.pb(mx);
	for(auto i : vr)
		res.pb(i);
	return res;
}
vector< int > sb(vector< int > v){
	if(v.empty()){
		vector< int > res;
		return res;
	}

	vector< pii > vs;
	for(auto i : v)
		vs.pb({t1(1, 2, i), i});
	sort(vs.begin(), vs.end());
	int mx = vs.back().s;
	vector< int > res, vl, vr;
	for(auto it : vs){
		int i = it.s;
		if(i == mx)
			continue;
		int res = t2(2, mx, i);
		if(res == 1)
			vl.pb(i);
		else
			vr.pb(i);
	}
	reverse(vr.begin(), vr.end());

	for(auto i : vl)
		res.pb(i);
	res.pb(mx);
	for(auto i : vr)
		res.pb(i);
	return res;
}

main()
{
	cin >> n;
	vector< int > a, b;
	for(int i = 3; i <= n; i++){
		int res = t2(1, 2, i);
		if(res == 1)
			a.pb(i);		
		else
			b.pb(i);
	}
	vector< int > ans, tmp;
	tmp = sa(a);
	for(auto it : tmp)
		ans.pb(it);
	ans.pb(2);
	tmp = sb(b);
	for(auto it : tmp)
		ans.pb(it);
	ans.pb(1);
	
	reverse(ans.begin(), ans.end());
	cout << 0 << " ";
	for(auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}