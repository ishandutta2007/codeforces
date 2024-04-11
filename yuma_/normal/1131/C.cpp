#include "bits/stdc++.h"

#pragma warning(disable:4996)

//

using namespace std;
vector<int>ls,rs;
void  check( const vector<int>&v) {
	ls.clear();
	ls.push_back(v[0]);
	rs.push_back(v[0]);

	bool ok=false;
	for (int i = 1; i < v.size() - 1; ++i) {
		if (ls.back() < rs.back()) {
			ls.push_back(v[i]);
		}
		else {
			rs.push_back(v[i]);
		}
	}
}

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	sort(v.begin(),v.end());
	check(v);
	vector<int>anss;
	for (int i = 0; i < ls.size(); ++i) {
		anss.push_back(ls[i]);
	}
	anss.push_back(v.back());
	for (int i = rs.size() - 1; i >= 1; --i) {
		anss.push_back(rs[i]);
		
	}
	for (int i = 0; i < N; ++i) {
		cout<<anss[i]<<" ";
	}
	cout<<endl;

	return 0;
}