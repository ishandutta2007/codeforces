#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}

vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
int solve(int a) {
	if(a==1)return 1;
	auto divs=divisor(a);
	int x=divs[1];
	return a/x;
	
}
int MAX_N=28;

bool check() {
	int N;cin>>N;
	vector<int>lv(N),rv(N);
	for(int i=0;i<N;++i)scanf("%d",&lv[i]);
	for(int i=0;i<N;++i)scanf("%d",&rv[i]);


	return true;
}
int main() {
	int N,M;cin>>N>>M;
	vector<int>cnts(M);
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		a--;cnts[a]++;
	}
	vector<vector<int>>dps(2,vector<int>(9,-1e9));
	dps[0][0]=0;
	for (int i = 0; i < M; ++i) {
		int cur=i%2;
		int tar=1-cur;
		for (int status = 0; status < 9; ++status) {
			int p_num=status%3;
			int pp_num=status/3;

			for (int now_num = 0; now_num < 3; ++now_num) {
				int left = cnts[i] - p_num - pp_num-now_num;

				if(left<0)continue;
				else {
					int plus=left/3+now_num;

					int next_status=p_num*3+now_num;
					dps[tar][next_status]=max(dps[tar][next_status],dps[cur][status]+plus);
				}

			}
		}
		for (int status = 0; status < 9; ++status) {
			dps[cur][status]=-1e9;
		}
	}
	int answer=dps[M%2][0];
	cout<<answer<<endl;
	return 0;
}