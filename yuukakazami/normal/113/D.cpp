/*
 * d.cpp
 *
 *  Created on: 2011-9-11
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 22;
const int MAX_N_ID = MAX_N * (MAX_N + 1) / 2;
double stay[MAX_N];
int nV, nId;
vector<int> E[MAX_N];
int id[MAX_N][MAX_N];
double mat[MAX_N_ID][MAX_N_ID];
double neg[MAX_N_ID][MAX_N_ID];
double orig[MAX_N_ID][MAX_N_ID];

void multiply(double a[MAX_N_ID][MAX_N_ID], double b[MAX_N_ID][MAX_N_ID], double c[MAX_N_ID][MAX_N_ID]) {
	for (int i = 0; i < nId; ++i) {
		for (int j = 0; j < nId; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < nId; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main() {
	cin >> nV;
	int nE;
	cin >> nE;
	int a, b;
	cin >> a >> b;
	--a, --b;
	for (int i = 0; i < nE; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (int i = 0; i < nV; ++i) {
		cin >> stay[i];
	}
	nId = 0;
	memset(id, -1, sizeof id);
	for (int i = 0; i < nV; ++i) {
		for (int j = 0; j < nV; ++j) {
			if (id[j][i] != -1) {
				id[i][j] = id[j][i];
			} else {
				id[i][j] = nId++;
			}
		}
	}
	memset(mat, 0, sizeof mat);
	for (int i = 0; i < nV; ++i) {
		for (int j = 0; j < nV; ++j) {
			int me = id[i][j];
			if (i >= j) {
//				mat[me][me] = 1;
			} else {
				for (int a = 0; a <= E[i].size(); ++a) {
					for (int b = 0; b <= E[j].size(); ++b) {
						double p = 1;
						if (a == E[i].size())
							p *= stay[i];
						else
							p *= (1 - stay[i]) / E[i].size();
						if (b == E[j].size())
							p *= stay[j];
						else
							p *= (1 - stay[j]) / E[j].size();
						int ni = a == E[i].size() ? i : E[i][a];
						int nj = b == E[j].size() ? j : E[j][b];
						mat[me][id[ni][nj]] += p;
					}
				}
			}
		}
	}
	// 1/(1-mat)
	for (int i = 0; i < nId; ++i) {
		for (int j = 0; j < nId; ++j) {
			mat[i][j] = -mat[i][j];
			if (i == j)
				mat[i][j] += 1;
		}
	}
	memcpy(orig, mat, sizeof mat);
	memset(neg, 0, sizeof neg);
	for (int i = 0; i < nId; ++i) {
		neg[i][i] = 1;
	}
	for (int r = 0; r < nId; ++r) {
		int mxId = 0;
		for (int c = 0; c < nId; ++c) {
			if (fabs(mat[r][c]) > fabs(mat[r][mxId]))
				mxId = c;
		}
		if (mxId != r) {
			for (int nr = 0; nr < nId; ++nr) {
				swap(mat[nr][r], mat[nr][mxId]);
				swap(neg[nr][r], neg[nr][mxId]);
			}
		}
		double by = mat[r][r];
		for (int c = 0; c < nId; ++c) {
			mat[r][c] /= by;
			neg[r][c] /= by;
		}
		for (int nr = 0; nr < nId; ++nr) {
			if (r != nr) {
				double by = mat[nr][r];
				for (int c = 0; c < nId; ++c) {
					mat[nr][c] -= by * mat[r][c];
					neg[nr][c] -= by * neg[r][c];
				}
			}
		}
	}
	for (int i = 0; i < nV; ++i) {
		printf("%0.10lf ", neg[id[a][b]][id[i][i]]);
	}
	cout << endl;
	double c[MAX_N_ID][MAX_N_ID];
	return 0;
}