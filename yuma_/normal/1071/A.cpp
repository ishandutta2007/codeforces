#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int main()
{
	int A,B;cin>>A>>B;
	long long int sum=A+B;
	long long int max_x=0;
	while (true) {
		long long int asum=(max_x)*(max_x+1)/2;
		if (asum > sum) {
			break;
		}
		else {
			max_x++;
		}
	}
	max_x--;
	vector<vector<int>>anss(2);
	vector<int>rests{ A,B };
	for (int x = max_x; x >= 1; --x) {
		if (rests[0] > rests[1]) {
			rests[0]-=x;
			anss[0].push_back(x);
		}
		else {
			rests[1]-=x;
			anss[1].push_back(x);
		}
	}
	cout<<anss[0].size()<<endl;
	for (int i = 0; i < anss[0].size(); ++i) {
		printf("%d ",anss[0][i]);
	}
	cout<<endl<<anss[1].size()<<endl;
	for (int i = 0; i < anss[1].size(); ++i) {
		printf("%d ",anss[1][i]);
	}
	return 0;
}