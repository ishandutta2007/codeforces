#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	map<int,int>mp;
	vector<vector<vector<int>>>bunchs(N);
	for (int i = 0; i < N; ++i) {
		int k=v[i];
		if (bunchs[k].empty() || bunchs[k].back().size() == N - k) {
			bunchs[k].push_back(vector<int>());
		}
		bunchs[k].back().push_back(i);
	}
	bool ok=true;
	for (int i = 0; i < N; ++i) {
		if (any_of(bunchs[i].begin(), bunchs[i].end(), [&](const vector<int>&v) {return v.size() != N - i; })) {
			ok=false;
		}
	}
	if (ok) {
		cout<<"Possible"<<endl;
		vector<int>anss(N);
		int id=1;
		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < bunchs[i].size(); ++j) {
				for (auto k : bunchs[i][j]) {
					anss[k]=id;
				}
				id++;
			}
		}
		for (int i = 0; i < N; ++i) {
			cout<<anss[i];
			if(i==N-1)cout<<endl;
			else cout<<" ";
		}
	}
	else {
		cout<<"Impossible"<<endl;
	}
	
	return 0;
}