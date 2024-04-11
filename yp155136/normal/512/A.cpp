#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 144;
string s[MAX_N];

vector<int> edg[MAX_N];
int deg[MAX_N];

int main () {
	int n;
	while (cin >> n) {
		for (int i=0;MAX_N>i;i++) {
			edg[i].clear();
			deg[i]=0;
		}
		for (int i=0;n>i;i++) {
			cin >> s[i];
		}
		bool check=true;
		for (int i=1;n>i;i++) {
			if(i) {
				string _=s[i-1],__=s[i];
				bool dangerous = false;
				if (__.size() < _.size()) dangerous=true;  //__ --> last
				bool _get = false;
				int id=0;
				while (id < min(_.size(),__.size())) {
					if (_[id] == __[id]) {
						id++;
						continue;
					}
					edg[_[id]].push_back(__[id]);
					deg[__[id]]++;
					_get=true;
					break;
				}
				if (!_get && dangerous) {
					check=false;
				}
			}
		}
		if (!check) {
			cout<<"Impossible"<<endl;
			continue;
		}
		queue<int> que;
		vector<int> ans;
		for (int i='a';'z'>=i;i++) {
			if (deg[i] == 0) que.push(i);
		}
		while (!que.empty()) {
			int t=que.front();
			ans.push_back(t);
			que.pop();
			for (auto i:edg[t]) {
				deg[i]--;
				if (!deg[i]) que.push(i);
			}
		}
		if (ans.size() != 26) cout<<"Impossible"<<endl;
		else {
			for (auto i:ans) {
				cout<<char(i);
			}
			cout<<endl;
		}
	}
}