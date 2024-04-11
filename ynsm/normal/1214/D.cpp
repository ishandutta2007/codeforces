#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
                        
int X[] = {0, 1, -1};
int Y[] = {1, 0, 0, -1};

int n, m, a[N], cnt[N];
char s[N];
bool was[N], used[N];

bool good(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m && a[x * m + y]; 
}
void dfs(int x, int y, int p){
    int v = x * m + y;
	if(was[v])
    	return;
    was[v] = 1;
	for(int i = 0; i < 2; i++){
		if(!good(x + X[i], y + Y[i]))
			continue;
		int to = v + X[i] * m + Y[i];
		dfs(x + X[i], y + Y[i], v);
		used[v] |= used[to];
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", &s);
		for(int j = 0; j < m; j++)
			a[i * m + j] = (s[j] == '.');
	}
	used[n * m - 1] = 1;
	dfs(0, 0, -1);
	int ans = 2;
	if(used[0] == 0){
		ans = 0;
	}else{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cnt[i + j] += used[i * m + j];
		for(int i = 1; i < n + m - 2; i++)
			if(cnt[i] == 1)
				ans = 1;
	}
	printf("%d", ans);
	return 0;
}