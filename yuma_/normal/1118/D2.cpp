#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int N;


long long int M;
vector<long long int>v;

bool check(int amid) {
	long long int sum=0;
	int now=0;
	int minus=0;
	while (true) {
		for (int i = 0; i < amid; ++i) {
			if(now==v.size())break;
			sum+=max(0ll,v[now++]-minus);
		}
		if(now==v.size())break;
		minus++;

	}
	return sum>=M;
}

int main() {
	cin>>N>>M;
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end(),greater<long long int>());
	int ok=1e9;
	int ng=0;
	while (abs(ok - ng) != 1) {
		int amid=((ok+ng)/2);
		if (check(amid)) {
			ok=amid;
		}
		else {
			ng=amid;
		}
	}
	if(ok>1e8)ok=-1;
	cout<<ok<<endl;
	return 0;
}