#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct operation {
	int type;
	int i;
	int x;
};

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d",&v[i]);
	}
	long long int sum=0;
	const long long int mod=N;
	vector<operation>ops;
	for (int i = N - 1; i >= 0; --i) {
		long long int x=mod*1000000-v[i]-(N-i)-sum;
		x%=mod;
		ops.push_back(operation{
			1,i+1,int(x)
		});
		sum+=x;
	}
	ops.push_back(operation{
		2,N,N });

	cout<<ops.size()<<endl;
	for (int i = 0; i < ops.size(); ++i) {
		printf("%d %d %d\n",
			ops[i].type,
			ops[i].i,
			ops[i].x);
	}
	return 0;
}