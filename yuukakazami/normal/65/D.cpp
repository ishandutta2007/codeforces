/*
 * D. Harry Potter and the Sorting Hat.cpp
 *
 *  Created on: 2011-3-6
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <set>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const int MAX_N=10000+10;

set<vector<int> > dp[MAX_N];
string names="GRSH";

int main(){
	vector<int> init(4,0);
	int n;string input;
	cin>>n;cin>>input;
	dp[0].insert(init);
	for (int cur = 0; cur < n; ++cur) {
		if(input[cur] != '?'){
			int id=names.find(input[cur]);
			foreach(e,dp[cur]){
				vector<int> am=*e;
				am[id]++;
				dp[cur+1].insert(am);
			}
		} else {
			foreach(e,dp[cur]){
				vector<int> am=*e;
				int mc=INT_MAX;
				foreach(e2,am)
					mc = min(mc,*e2);
				for (int ch = 0; ch < 4; ++ch) {
					if(am[ch] == mc){
						am[ch]++;
						dp[cur+1].insert(am);
						am[ch]--;
					}
				}
			}
		}
	}

	bool can[4]={};
	foreach(e,dp[n]){
		vector<int> am=*e;
		int mc=INT_MAX;
		foreach(e2,am)
			mc = min(mc,*e2);
		for (int which = 0; which < 4; ++which) {
			if(am[which] == mc)
				can[which]=true;
		}
	}

	string names[]={"Gryffindor","Ravenclaw","Slytherin","Hufflepuff"};
	vector<string> ans;
	for (int i = 0; i < 4; ++i) {
		if(can[i])
			ans.push_back(names[i]);
	}
	sort(ans.begin(),ans.end());
	foreach(e,ans)
		cout<<*e<<endl;
}