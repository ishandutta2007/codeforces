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

int n, a[N], ans, ok;
set< int > st;
void add(int x){
	if(st.find(x) == st.end())
		st.insert(x);
	else
		ok = 0;
}
int main()
{
	cin >> n;
	ans = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st.insert(a[i]);
	}
	if(st.size() == n){
		cout << 0;
		return 0;
	}

	for(int i = 1; i <= n; i++){
		st.clear();
		ok = 1;
		for(int j = 1; j < i; j++)
			add(a[j]);
		for(int j = n; j >= i; j--){
			if(ok)
				ans = min(ans, j - i + 1);			
			add(a[j]);
		}
	}
	cout << ans;
	return 0;
}