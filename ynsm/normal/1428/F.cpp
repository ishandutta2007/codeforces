#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n;
ll a[N], b[N], ans, cur;
vector< int > v[N];
set< int > st;
char s[N];
int main()
{
	scanf("%d", &n);
	scanf("%s", &s);
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			if(i)
            	a[i] = a[i - 1];
            a[i]++;
		}
		b[i] = n - i;
		if(i)
			cur += b[i];
		v[a[i]].pb(i);
		st.insert(i);
	}
	for(int i = 1; i <= n; i++){
		for(auto x : v[i - 1]){
			auto it = st.find(x);
			if(it == st.begin()){
				auto nxt = it;
				nxt++;
				if(nxt != st.end())
					cur -= (*nxt - *it) * b[*nxt];
			}else{
				auto prev = it;
				prev--;
				cur -= (*it - *prev) * b[*it];
				auto nxt = it;
				nxt++;
				if(nxt != st.end()){
					cur -= (*nxt - *it) * b[*nxt];
					cur += (*nxt - *prev) * b[*nxt];
				}
			}
			st.erase(it);
		}
		ans += cur;
		if(!st.empty())
			ans += (*st.begin() - i + 2) * b[*st.begin()];
	}
	printf("%lld", ans);
}