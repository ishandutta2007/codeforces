#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
const long long int x=1200;
int main() {
	int N;cin>>N;
	vector<int>anss;
	if (N >= 1000000) {
		long long int sum = N + x*(x + 2);
		long long int b = sum / (x + 2) + 800;
		long long int a = b*(x + 2) - sum;
		anss.resize(x + 2);

		anss[0] = a;
		anss[1] = -a - 1;
		for (int i = 2; i<x + 1; ++i)anss[i] = -1;
		anss[x + 1] = b;
	}
	else {
		anss.resize(3);
		if (N % 2) {
			anss[0]=1;
			anss[1]=-2;
			anss[2]=(N+3)/2;
		}
		else {
			anss[0]=1;
			anss[1]=-3;
			anss[2]=(N+6)/2;
		}
	}
	

	cout<<anss.size()<<endl;
	for(int i=0;i<anss.size();++i)cout<<anss[i]<<" ";
	cout<<endl;

	return 0;
}