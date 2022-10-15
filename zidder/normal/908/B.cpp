#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define SS ;
typedef long long ll;
using namespace std;
vector<string> gr;
int w, h;
string S;
int sx=0, sy=0;
bool solve(int n, int e, int we, int s) {
	vector<int> dir;
	dir.push_back(n);
	dir.push_back(e);
	dir.push_back(we);
	dir.push_back(s);
	int x = sx, y = sy;
	for (int i = 0;i < S.size();i++) {
		int q = dir[S[i] - 48];
		if (q == 0)
			y--;
		if (q == 1)
			x++;
		if (q == 2)
			x--;
		if (q == 3)
			y++;
		if (x < 0 || x >= w || y < 0 || y >= h)
			return false;
		if (gr[y][x] == '#')
			return false;
		if (gr[y][x] == 'E')
			return true;
	}
	return false;
}
int main() {
	cin >> h >> w;
	gr = vector<string>(h);
	for (size_t i = 0; i < h; i++) {
		cin >> gr[i];
		for (size_t j = 0; j < w; j++){
			if (gr[i][j] == 'S'){
				sx = j;
				sy = i;
			}
		}
	}
	cin >> S;
	int c = 0;

	c += solve(0, 1, 3, 2);
	c += solve(0, 1, 2, 3);
	c += solve(0, 2, 1, 3);
	c += solve(0, 2, 3, 1);
	c += solve(0, 3, 1, 2);
	c += solve(0, 3, 2, 1);
	c += solve(1, 0, 3, 2);
	c += solve(1, 0, 2, 3);
	c += solve(1, 2, 0, 3);
	c += solve(1, 2, 3, 0);
	c += solve(1, 3, 0, 2);
	c += solve(1, 3, 2, 0);
	c += solve(2, 1, 3, 0);
	c += solve(2, 1, 0, 3);
	c += solve(2, 0, 1, 3);
	c += solve(2, 0, 3, 1);
	c += solve(2, 3, 1, 0);
	c += solve(2, 3, 0, 1);
	c += solve(3, 1, 0, 2);
	c += solve(3, 1, 2, 0);
	c += solve(3, 2, 1, 0);
	c += solve(3, 2, 0, 1);
	c += solve(3, 0, 1, 2);
	c += solve(3, 0, 2, 1);
	cout << c;
	SS;
	return 0;
}