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

int n, a[N], b[N], timer, q;
set< pii > st, st2;
stack< pii > stt;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		st.insert({a[i], i});
	}
	scanf("%d", &q);
	while(q--){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int p, x;
			scanf("%d%d", &p, &x);
			st.erase({a[p], p});
			a[p] = x;
			st.insert({a[p], p});
		}else{
			int x;
			scanf("%d", &x);
			while(!st.empty() && st.begin()->f <= x){
				b[st.begin() -> s]  = timer;
				st.erase(st.begin());
			}
			while(!stt.empty() && stt.top().f <= x)
				stt.pop();
			stt.push({x, timer});
			timer++;
		}
	}
	while(!stt.empty()){
		st2.insert({stt.top().s, stt.top().f});
		stt.pop();
	}
	for(int i = 1; i <= n; i++)
		if(st.find({a[i], i}) == st.end())
			printf("%d ", st2.lower_bound({b[i], -1}) -> s);
		else        
			printf("%d ", a[i]);
	return 0;
}