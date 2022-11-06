#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N, K; cin >> N >> K;
	vector<int>oks(N,true);
	int a, b, c, d; cin >> a >> b >> c >> d;
	a--; b--; c--; d--;
	oks[a] = false;
	oks[b] = false;
	oks[c] = false;
	oks[d] = false;
	vector<int>rests;
	for (int i = 0; i < N; ++i) {
		if (oks[i])rests.push_back(i);
	}
	bool absw = false;
	bool cdsw = false;
	bool acsw = false;
	if (a > b) {
		swap(a, b);
		absw = true;
	}
	if (c > d) {
		swap(c, d);
		cdsw = true;
	}
	if (a > c) {
		swap(a, c);
		swap(b, d);
		acsw = true;
	}
	bool ok = true;
	vector<int>abr, cdr;
	{
		abr.push_back(a);
		cdr.push_back(c);
		
		if (N == 4)ok = false;
		else {
			abr.push_back(c);
			cdr.push_back(a);
			if (K >= N + 1) {
				assert(rests.size() == N - 4);
				for (int i = 0; i < N - 4; ++i) {
					abr.push_back(rests[i]);
					cdr.push_back(rests[i]);
				}
			}
			else {
				ok = false;
			}
			abr.push_back(d);
			cdr.push_back(b);
		}
			
		
		abr.push_back(b);
		cdr.push_back(d);
	}
	if (ok) {
		if (acsw)swap(abr, cdr);
		if (absw)reverse(abr.begin(), abr.end());
		if (cdsw)reverse(cdr.begin(), cdr.end());
		for (int i = 0; i < N; ++i) {
			cout << abr[i]+1;
			if (i == N - 1)cout << endl;
			else cout << " ";
		}
		for (int i = 0; i < N; ++i) {
			cout << cdr[i]+1;
			if (i == N - 1)cout << endl;
			else cout << " ";
		}
	}
	else {
		cout << -1 << endl;
	}
	
	return 0;
}