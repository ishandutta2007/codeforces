#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	long long int N, M; cin >> N >> M;
	long long int ans = N;
	{
		long long int amin = M;
		long long int amax = M+2e9;
		while (amin + 1 != amax) {
			long long int amid = (amin + amax) / 2;
			long long int eat = (amid - M)*(amid - M - 1) / 2+amid;
			if (eat >= N)amax = amid;
			else amin = amid;
		}
		ans = min(ans, amax);
		cout << ans<< endl;
	}
	

	return 0;
}