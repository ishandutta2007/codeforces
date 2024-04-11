#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

using ld = long double;
int main()
{
	int N;
	ld sum;cin>>N>>sum;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int num = count_if(edges.begin(), edges.end(), [](const vector<int>&v) {return v.size() == 1; });
	ld answer=0;
	cout<<setprecision(10)<<fixed;
	cout<<sum/num*2<<endl;
	return 0;
}