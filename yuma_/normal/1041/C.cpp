#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld =long double;


int main() {
	int N,M,K;cin>>N>>M>>K;
	vector<pair<int,int>>ps;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		ps.push_back(make_pair(a,i));
	}
	sort(ps.begin(),ps.end());

	stack<int>sta;
	for (int i = 0; i < N; ++i) {
		sta.push(N-i-1);
	}
	vector<int>anss(N);
	queue<pair<int,int>>que;
	for (auto p : ps) {
		while (!que.empty()) {
			auto atop(que.front());
			if (atop.first<=p.first) {
				sta.push(atop.second);
				que.pop();
			}
			else {
				break;
			}
		}
		anss[p.second] = sta.top();
		sta.pop();
		que.push(make_pair(p.first+K+1,anss[p.second]));
	}
	int day=*max_element(anss.begin(),anss.end())+1;
	cout<<day<<endl;
	for (int i = 0; i < anss.size(); ++i) {
		cout<<1+anss[i];
		if(i==anss.size()-1)cout<<endl;
		else cout<<" ";
	}

 	return 0;
}