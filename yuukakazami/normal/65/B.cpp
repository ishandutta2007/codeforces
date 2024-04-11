/*
 * b.cpp
 *
 *  Created on: 2011-3-6
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const int pow10[]={1,10,100,1000,10000};

int get(int prev,int cur){
	int best=INT_MAX;
	for (int which = 0; which < 4; ++which) {
		int digit=cur/pow10[which]%10;
		for (int toWhat = 0; toWhat < 10; ++toWhat) {
			int nCur=cur+(toWhat-digit)*pow10[which];
			if(nCur >= prev && nCur < best)
				best=nCur;
		}
	}
	return best;
}

int main(){
	int n;vector<int> a;
	cin>>n;
	for (int i = 0; i < n; ++i) {
		int x;cin>>x;
		a.push_back(x);
	}
	a[0]=get(1000,a[0]);
	if(a[0] == INT_MAX){
		puts("No solution");
		return 0;
	}
	for (int at = 1; at < n; ++at) {
		a[at]=get(a[at-1],a[at]);
		if(a[at] == INT_MAX){
			puts("No solution");
			return 0;
		}
	}
	if(a[n-1] > 2011){
		puts("No solution");
		return 0;
	}
	foreach(e,a)
		cout<<*e<<endl;
}