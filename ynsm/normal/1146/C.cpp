#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int t, ans, n, mx, cur;
bool cand[N];

int main()
{
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 2; i <= n; i++)
			cand[i] = 1;
		cout << 1 << " " << n - 1 << " " << 1 << " ";
		for(int i = 2; i <= n; i++)
			cout << i << " ";
		cout << endl;
		
		cout.flush();
		cin >> mx;
		
		while(true){
			vector< int > v;
			for(int i = 2; i <= n; i++)
		    	if(cand[i])
		    		v.pb(i);
			if(v.size() == 1)
				break;
			cout << 1 << " " << v.size() / 2 << " " << 1 << " ";
			for(int i = 0; i < v.size() / 2; i++)
				cout << v[i] << " ";
			cout << endl;
			
			cout.flush();
			cin >> cur;
			if(cur == mx)
				for(int i = v.size() / 2; i < v.size(); i++)
			    	cand[v[i]] = 0;
			else
				for(int i = 0; i < v.size() / 2; i++)
			    	cand[v[i]] = 0;
		}
		int v;
		for(int i = 2; i <= n; i++)
		    if(cand[i])
				v = i;
		cout << 1 << " " << n - 1 << " " << v << " ";
		for(int i = 1; i <= n; i++)
			if(v != i)
				cout << i << " ";
		cout << endl;
		
		cout.flush();
		cin >> ans;
		
		cout << -1 << " " << ans << endl;
	}
	return 0;
}