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

int output(int k) {
	cout<<k<<endl;
	fflush(stdout);
	int a;cin>>a;
	
	return a;
}

int main() {
	int M,N;cin>>M>>N;
	vector<int>valids(N);

	for (int i = 0; i < N; ++i) {
		int in = output(1);
		if (in == 0) {
			return 0;
		}
		valids[i]=(in==1);
	}

	int amin=1;
	int amax=M+1;

	int k=0;
	while (true) {
		int amid=(amin+amax)/2;
		int in=output(amid);
		if (in == 0) {
			return 0;
		}
		else {
			int ans=in;
			if (!valids[k%N]) {
				ans=-ans;
			}
			if (ans == 1) {
				amin=amid;
			}
			else {
				amax=amid;
			}
		}
		k++;
	}



	return 0;
}