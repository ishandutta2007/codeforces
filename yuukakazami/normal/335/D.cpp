#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
const int MAX_VALUE = 3000 + 3;
typedef int Data[MAX_VALUE][MAX_VALUE];

int n;

void add(Data data, int r1, int c1, int r2, int c2) {
	//[r1,r2) [c1,c2)
	data[r1][c1]++;
	data[r1][c2]--;
	data[r2][c1]--;
	data[r2][c2]++;
}

void prepareSum(Data data) {
	static Data tmp;
	for (int r = 1; r < MAX_VALUE; ++r) {
		for (int c = 1; c < MAX_VALUE; ++c) {
			tmp[r][c] = data[r - 1][c - 1] + tmp[r - 1][c] + tmp[r][c - 1]
					- tmp[r - 1][c - 1];
		}
	}
	memcpy(data, tmp, sizeof tmp);
	//r),c)
}

void prepareValue(Data data) {
	for (int r = 0; r < MAX_VALUE; ++r) {
		for (int c = 0; c < MAX_VALUE; ++c) {
			if (r > 0)
				data[r][c] += data[r - 1][c];
			if (c > 0)
				data[r][c] += data[r][c - 1];
			if (r > 0 && c > 0)
				data[r][c] -= data[r - 1][c - 1];
		}
	}
	//r),c)
}

int get(Data data, int r1, int c1, int r2, int c2) {
	//[r1,r2) [c1,c2)
	return data[r2][c2] - data[r1][c2] - data[r2][c1] + data[r1][c1];
}

Data area, inner, L, R, U, D;

int cx[MAX_N], cy[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		add(area, x1, y1, x2, y2);
		//LR
		if (x1 + 1 < x2) {
			add(L, x1 + 1, y1 + 1, x2, y2 + 1);
			add(R, x1 + 1, y1, x2, y2);
		}
		//UD
		if (y1 + 1 < y2) {
			add(U, x1 + 1, y1 + 1, x2 + 1, y2);
			add(D, x1, y1 + 1, x2, y2);
		}
		cx[i] = x1, cy[i] = y1;
	}
	prepareValue(D), prepareValue(U), prepareValue(L), prepareValue(R);
//	prepareSum(area);
	prepareValue(area);
	prepareSum(area);
//	cout << get(area, 0, 0, 2, 2) << endl;

//U,L
	for (int i = 0; i < MAX_VALUE; ++i) {
		for (int j = 0; j < MAX_VALUE; ++j) {
			if (U[i][j])
				U[i][j] = i;
			else {
				if (i > 0)
					U[i][j] = U[i - 1][j];
				else
					U[i][j] = -1;
			}

			if (L[i][j])
				L[i][j] = j;
			else {
				if (j > 0)
					L[i][j] = L[i][j - 1];
				else
					L[i][j] = -1;
			}
		}
	}

//D,R
	for (int i = MAX_VALUE - 1; i >= 0; --i) {
		for (int j = MAX_VALUE - 1; j >= 0; --j) {
			if (D[i][j]) {
				D[i][j] = i;
			} else {
				if (i + 1 < MAX_VALUE)
					D[i][j] = D[i + 1][j];
				else
					D[i][j] = MAX_VALUE;
			}
			if (R[i][j]) {
				R[i][j] = j;
			} else {
				if (j + 1 < MAX_VALUE)
					R[i][j] = R[i][j + 1];
				else
					R[i][j] = MAX_VALUE;
			}
		}
	}

	int who = -1;
	int ansL;

	for (int i = 0; i < n; ++i) {
		int x = cx[i], y = cy[i]; //corner
		int maxL = min(R[x][y] - y, D[x][y] - x);

		for (int L = 1; L <= maxL; ++L) {
			int xx = x + L, yy = y + L;
			//[x,xx] [y,yy]
			if (get(area, x, y, xx, yy) < L * L)
				break;
			//check U and L
			if (yy - ::L[xx][yy] >= L && xx - U[xx][yy] >= L) {
				who = i, ansL = L;
				goto outside;
			}
		}
	}

	outside: {
	}

	if (who == -1) {
		puts("NO");
	} else {
		vector<int> lst;
		int x = cx[who], y = cy[who];
		int xx = x + ansL, yy = y + ansL;

		for (int i = 0; i < n; ++i) {
			if (cx[i] >= x && cx[i] < xx && cy[i] >= y && cy[i] < yy) {
				lst.push_back(i);
			}
		}

		cout << "YES" << " " << lst.size() << endl;
		for (int i = 0; i < lst.size(); ++i) {
			printf("%d ", lst[i] + 1);
		}
		puts("");
	}
}