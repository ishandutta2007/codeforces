#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"


int main() {
	long  long int D, K, A, B, T; cin >> D >> K >> A >> B >> T;
	long long int ans = 1e18;
	long long int dis = min(K, D);
		long long int rest = D - dis;
		long long int ntime = A*dis;
		//x
		//(x+1)*K car
		//D-((x+1)*K) walk
		//t=T*x+(x+1)*K*A+(D-((x+1)*K))*B
		//t=(T+KA-KB)*x+KA+DB-KB;
		ans = min(ans, D*B);
		ans = min(ans, rest*B + ntime);
		long long int atime = D / K;
		if (atime) {
			ans = min(ans, atime*K*A + (D - atime*K)*B + T*(atime - 1));
		}
		ans = min(ans, D*A + T*atime);
		cout << ans << endl;
	
	
	return 0;
}