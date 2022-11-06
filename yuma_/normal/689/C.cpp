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

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src_, int dst_, Weight weight_) :
		src(src_), dst(dst_), weight(weight_) { }
	Edge(int src_, int dst_) :
		src(src_), dst(dst_) {

	}
};
vector<long long int >tris;
long long int getway(const long long int n) {
	long long int way = 0;
	for (auto tri : tris) {
		way += (n / tri);
	}
	
	return way;
}



int main() {
	{
		for (long long int i = 2; i <= 1e6; ++i) {
			tris.emplace_back(i*i*i);
		}
	}
	long long int N; cin >> N;
	long long int amin = 0;
	long long int amax = 1e18;
	while (amin + 1 != amax) {
		long long int amid = (amin + amax) / 2;
		long long int way = getway(amid);
		if (way >= N) {
			amax = amid;
		}
		else {
			amin = amid;
		}
		
	}
	long long int finway = getway(amax);
	if (finway == N) {
		cout << amax << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
	
}