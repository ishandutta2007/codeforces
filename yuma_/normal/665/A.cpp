#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	int a, ta, b, tb; cin >> a >> ta >> b >> tb;
	int m, s; scanf("%d:%d", &m, &s);
	s = s + m * 60;
	vector<pair<int, int>>bbuss;
	{
		int stime = 300;
		while (stime < 1440) {
			bbuss.push_back(make_pair(stime, stime + tb));
			stime += b;
		}
	}
	{
		int mystime = s;
		int mygtime = s + ta;
		int ans = 0;
		for (auto b : bbuss) {
			if (b.first < mystime&&mystime < b.second) {
				ans++;
			}
			else if (b.first < mygtime&&mygtime < b.second) {
				ans++;
			}
			else if (mystime <= b.first&&b.first < mygtime) {
				ans++;
			}
			else if (mystime < b.second&&b.second <= mygtime) {
				ans++;
			}
			
		}
		cout << ans << endl;
	}
	
	return 0;
}