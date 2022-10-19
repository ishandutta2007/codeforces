//https://codeforces.com/problemset/problem/1598/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<vector<bool> > blocked(n, vector<bool>(m, false));
    vector<vector<pair<int, int> > > a(n, vector<pair<int, int> >(m)); // num right, down
    long long sum = 0;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (i) a[i][j].first += a[i-1][j].second + 1;
            if (j) a[i][j].second += a[i][j-1].first + 1;
            sum += a[i][j].first + a[i][j].second + 1;
        }
    }
    int q;
    cin >> q;
    for (int i=0;i<q;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        x--;y--;
        blocked[x][y] = !blocked[x][y];
        int p1, p2;
        if (!blocked[x][y]) {
            if (x) a[x][y].first = a[x-1][y].second + !blocked[x-1][y];
            if (y) a[x][y].second = a[x][y-1].first + !blocked[x][y-1];
            p1 = -a[x][y].first - 1;
            p2 = -a[x][y].second - 1;
            sum -= p1 + p2 + 1;
        } else {
            p1 = a[x][y].first + 1;
            p2 = a[x][y].second + 1;
            sum -= p1 + p2 - 1;
            a[x][y].first = 0;
            a[x][y].second = 0;
        }
        bool first = true, second = true;
        while (x < n && y < m){
            if (x + 1 < n){
                if (blocked[x+1][y]) second=false;
                else if (second) {a[x+1][y].first -= p2;sum-=p2;}

                if (y+1<m){
                    if (!blocked[x+1][y+1] && second) {a[x+1][y+1].second -= p2;sum-=p2;}
                }
            }
            if (y + 1 < m){
                if (blocked[x][y+1]) first=false;
                else if (first) {a[x][y+1].second -= p1;sum-=p1;}

                if (x+1<n){
                    if (!blocked[x+1][y+1] && first) {a[x+1][y+1].first -= p1;sum-=p1;}
                }
            }
            x++;y++;
            if (x < n && y < m && blocked[x][y]) break;
        }
        printf("%lld\n", sum);
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}