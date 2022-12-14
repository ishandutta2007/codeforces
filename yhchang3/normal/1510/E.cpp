#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> table[324 * 2 + 1][18 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	double cx, cy;
	cin >> n >> cx >> cy;
	const int N = n >> 1;
	for(int mask=0;mask<(1<<N);mask++) {
		int h = 0, sm = 0, sx = 0, sy = 0;
		bool ok = true;
		for(int i=0;i<N;i++) {
			if((mask >> i) & 1) {
				h++;
				sm += h + (h - 1);
				sx += (h * 2 - 2) * (6 * i + 3) + (6 * i + 4);
				sy += (h * 2 - 2) * (3 * h - 3) + (6 * h - 4);
			}
			else {
				if(h == 0) {
					ok = false;
					break;
				}
				sm += h + (h - 1);
				sx += (h * 2 - 2) * (6 * i + 3) + (6 * i + 2);
				sy += (h * 2 - 2) * (3 * h - 3) + (6 * h - 4);
				h--;
			}
		}
		if(!ok)	continue;
		table[sm][h].emplace_back(sx, sy, mask);
	}
	for(int i=1;i<=2*N*N;i++)
		for(int j=0;j<=N;j++)
			sort(table[i][j].begin(), table[i][j].end());
	for(int mask=0;mask<(1<<N);mask++) {
		int h = 0, sm = 0, sx = 0, sy = 0;
		bool ok = true;
		for(int i=0;i<N;i++) {
			if((mask >> i) & 1) {
				h++;
				sm += h + (h - 1);
				sx += (h * 2 - 2) * (6 * i + 3) + (6 * i + 4);
				sy += (h * 2 - 2) * (3 * h - 3) + (6 * h - 4);
			}
			else {
				if(h == 0) {
					ok = false;
					break;
				}
				sm += h + (h - 1);
				sx += (h * 2 - 2) * (6 * i + 3) + (6 * i + 2);
				sy += (h * 2 - 2) * (3 * h - 3) + (6 * h - 4);
				h--;
			}
		}
		if(!ok)	continue;
		sx = 6 * sm * n - sx;
		for(int tm=1;tm<=2*N*N;tm++) {
			auto &tar = table[tm][h];
			if(tar.empty())	continue;
			int tx = cx * 6 * (sm + tm) + 0.5 - sx;
			int ty = cy * 6 * (sm + tm) + 0.5 - sy;
			auto it = lower_bound(tar.begin(), tar.end(), make_tuple(tx, ty, 0));
			if(it == tar.end())	continue;
			auto [fx, fy, fmask] = *it;
			double dx = (fx + sx) / 6.0 / (sm + tm);
			double dy = (fy + sy) / 6.0 / (sm + tm);
			if(abs(cx - dx) + abs(cy - dy) <= 1e-8) {
				for(int i=0;i<N;i++) {
					if((fmask >> i) & 1)
						cout << '(';
					else
						cout << ')';
				}
				for(int i=N-1;i>=0;i--) {
					if((mask >> i) & 1)
						cout << ')';
					else	
						cout << '(';
				}
				cout << endl;
				return 0;
			}
		}
	}
}