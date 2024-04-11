#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


void add(set<pair<int, int>>&answer, pair<int, int>a, pair<int, int>b) {
	if(a>b)swap(a,b);
	for (int x = a.first; x <= b.first; ++x) {
		answer.emplace(x,a.second);
	}
	if (a.second <= b.second) {
		for (int y = a.second; y <= b.second; ++y) {
			answer.emplace(b.first,y);
		}
	}
	else {
		for (int y = a.second; y >= b.second; --y) {
			answer.emplace(b.first, y);
		}
	}
}

int main()
{
	vector<pair<int,int>>ps;
	for (int i = 0; i < 3; ++i) {
		int x,y;cin>>x>>y;
		ps.push_back(make_pair(x,y));
	}
	sort(ps.begin(),ps.end());
	set<pair<int,int>>answer;
	vector<int>xs,ys;
	for (int i = 0; i < 3; ++i) {
		xs.push_back(ps[i].first);
		ys.push_back(ps[i].second);
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());

	pair<int,int>center=make_pair(xs[1],ys[1]);
	for(int i=0;i<3;++i)add(answer,center,ps[i]);
	cout<<answer.size()<<endl;
	for (auto aa : answer) {
		cout<<aa.first<<" "<<aa.second<<endl;
	}

	return 0;
}