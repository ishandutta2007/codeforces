#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
int n, m, a[N], mx, mn;
set<pii> st;
int main(){    
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i] + m);
		mn = max(mn, a[i]);
		st.insert({a[i], i});
	}
	while(m--){
		pii x = *st.begin();
		st.erase(st.begin());
		x.f++;
		st.insert(x);
		mn = max(mn, x.f);
	}
	cout << mn << " " << mx;
	return 0;
}