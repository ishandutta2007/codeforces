#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void dfs(vector<int>&depths,const  vector<vector<int>>&revedges,int dep,int now) {
	depths[now]=dep;
	for (auto re : revedges[now]) {
		dfs(depths,revedges,dep+1,re);
	}
}

int main() {
	string st;cin>>st;
	int N=st.size();

	// fst letter , plus n , 
	vector<vector<vector<int>>>memo(26,vector<vector<int>>(N,vector<int>(26)));

	for (int i = 0; i < N; ++i) {
		int ch_one=st[i]-'a';
		for (int plus = 0; plus < N; ++plus) {
			int ch_two=st[(i+plus)%N]-'a';
			
			memo[ch_one][plus][ch_two]++;
		}
	}
	vector<ld>oks(N);
	int ans=0;
	for (int i=0;i<26;++i) {
		int num = count(st.begin(), st.end(), 'a' + i);
		auto mem(memo[i]);
		double per = 0;
		for (auto& me : mem) {
			double aper=0;
			for (auto& m : me) {
				if (m == 1) {
					aper++;
				}
			}
			per=max(aper,per);
		}
		ans+=per;
	}

	ld aans=ans/double(N);
	cout<<setprecision(10)<<fixed<<aans<<endl;
	return 0;
}