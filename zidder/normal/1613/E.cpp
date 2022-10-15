// https://codeforces.com/problemset/problem/1613/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    cin.tie(0);
	int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<vector<vector<pair<int, int> > > > neigbours(n, vector<vector<pair<int, int> > >(m));
    vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (a[i][j] == '#') continue;
            for (auto [di, dj]: dirs){
                if (i + di < 0 || i + di >=n || j + dj < 0 || j + dj >= m){
                    continue;
                }
                if (a[i+di][j+dj] == '#') continue;
                neigbours[i][j].emplace_back(i+di, j+dj);
            }
        }
    }

    int li = -1, lj;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (a[i][j] == 'L'){
                li = i;
                lj = j;
                break;
            }
        }
        if (li > -1) break;
    }

    vector<pair<int, int> > q;
    int ind = 0;
    q.emplace_back(li, lj);
    while (ind < q.size()){
        auto [i, j] = q[ind++];
        for (auto [ni, nj]: neigbours[i][j]){
            if (a[ni][nj] != '.') continue;
            int c = 0;
            for (auto [n1i, n1j]: neigbours[ni][nj]){
                if (a[n1i][n1j] == '.') c++;
            }
            if (c < 2){
                a[ni][nj] = '+';
                q.emplace_back(ni, nj);
            }
        }
    }

    for (int i=0;i<n;++i){
        printf("%s\n", a[i].c_str());
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}

/*
####......
####.####.
####.####.
####.####.
........#.
.###.##.#.
.###.##.#.
....L...#.
####.####.
####......
*/