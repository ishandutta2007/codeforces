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

int n, x, y, o, ans[N], nn;
vector< int > v[N]; 
void solve(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 0; i <= n; i++)
		v[i].clear();
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v[x - 1].pb(i);
	}
	priority_queue< pii > q;
	for(int i = 0; i <= n; i++){
		q.push({v[i].size(), i});
		if(v[i].size() == 0)
			o = i;
	}				
	for(int i = 0; i < n; i++)
		ans[i] = o;

	for(int i = 0; i < x; i++){
		pii a = q.top();
		q.pop();
		ans[v[a.s].back()] = a.s;
		v[a.s].pop_back();
		q.push({a.f - 1,a.s});
	}
	y -= x;
	nn = n - x;
	while(true){
		pii a = q.top();
		q.pop();
        pii b = q.top();
		q.pop();
		if(b.f == 0)
			break;                         
		if(nn == 3 && a.f == 1){
			pii c = q.top();
			q.pop();
			if(y)
				ans[v[a.s].back()] = b.s, y--;
			if(y)
				ans[v[b.s].back()] = c.s, y--;
			if(y)
				ans[v[c.s].back()] = a.s, y--;
			break;
		}
		if(y)
			ans[v[a.s].back()] = b.s, y--;
		if(y)
			ans[v[b.s].back()] = a.s, y--;
		nn -= 2;
		v[a.s].pop_back();
		q.push({a.f - 1,a.s});
		v[b.s].pop_back();
		q.push({b.f - 1,b.s});
	}
	if(y)
		puts("NO");
	else{
		puts("YES");
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i] + 1);
		printf("\n");	
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}