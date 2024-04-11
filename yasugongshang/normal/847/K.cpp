#include<bits/stdc++.h>
using namespace std;

const int maxn = 3009;
int n, a, b, K, f, x[maxn], y[maxn], need[maxn], m, cnt, ans;
map<string, int> order;
map<pair<int, int>, int> cost;
string s, t;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d%d%d%d%d", &n, &a, &b, &K, &f);
	for (int i=1; i<=n; i++){
		cin >> s >> t;
		if (!order[s]) x[i] = order[s] = ++m;
		else x[i] = order[s];
		if (!order[t]) y[i] = order[t] = ++m;
		else y[i] = order[t];
		if (x[i] == y[i-1]) cost[make_pair(min(x[i], y[i]), max(x[i], y[i]))] += b;
		else cost[make_pair(min(x[i], y[i]), max(x[i], y[i]))] += a;
	}
	for (map<pair<int,int>, int>::iterator i=cost.begin(); i!=cost.end(); i++)
		need[++cnt] = i->second;
	sort(need+1, need+cnt+1, cmp);
	for (int i=1; i<=cnt&&i<=K; i++) need[i] = min(need[i], f);
	for (int i=1; i<=cnt; i++) ans += need[i];
	printf("%d\n", ans);
	return 0;
}