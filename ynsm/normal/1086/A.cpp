#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int x, y;
pii a[3];
vector< pii > ans;
bool was[1100][1100];
int f(int i, int x, int y){
	return abs(x - a[i].f) + abs(y - a[i].s) + 1;
}
int get(int x, int y){
	return f(0, x, y) + f(1, x, y) + f(2, x, y) - 2;
}
void solve(int x, int y, int i){
	was[x][y] = 1;
	if(x > a[i].f)
		solve(x - 1, y, i);
	else if(x < a[i].f)
		solve(x + 1, y, i);
	else if(y > a[i].s)
		solve(x, y - 1, i);
	else if(y < a[i].s)
		solve(x, y + 1, i);
}

int main(){
	for(int i = 0; i < 3; i++)
		cin >> a[i].f >> a[i].s;
	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(get(i, j) < get(x, y))
				x = i, y = j;
	solve(x, y, 0);
    solve(x, y, 1);
	solve(x, y, 2);
    for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(was[i][j])
				ans.pb({i, j});
    cout << ans.size() << endl;
    for(auto it : ans)
    	cout << it.f << " " << it.s << endl;
    return 0;
}