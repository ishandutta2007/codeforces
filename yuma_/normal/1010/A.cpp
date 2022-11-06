#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

#include<unordered_map>

bool check(ld t, const vector<int>&as, const vector<int>&bs, ld fuel) {
	for (int i = 0; i < as.size(); ++i) {
		ld k=as[i];
		{

			ld weight = t + fuel;
			ld need = weight / k;
			fuel-=need;
			if (fuel<0)return false;
		}
		k=bs[(i+1)%as.size()];
		{

			ld weight = t + fuel;
			ld need = weight / k;
			fuel -= need;
			if (fuel<0)return false;
		}
	}
	return true;
}

int main() {
	int N;cin>>N;
	ld t;cin>>t;

	vector<int>as(N),bs(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d",&as[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d",&bs[i]);
	}
	ld amin=0;
	ld amax=1e10;

	int rest=60;
	while (rest--) {
		ld amid=(amin+amax)/2;
		if (check(t, as, bs, amid)) {
			amax=amid;
		}
		else {
			amin=amid;
		}
	}
	if (amin> 2e9) {
		cout<<-1<<endl;
	}
	else {

		cout << setprecision(10) << fixed << amin << endl;
	}

	return 0;
}