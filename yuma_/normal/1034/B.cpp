#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
const int MAX_A=151000;
int main()
{
	/*int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);
	if (all_of(v.begin(), v.end(), [&](const int a) {return a == v[0]; })) {
		cout<<-1<<endl;
		return 0;
	}
	hurui(MAX_A);
	int prime_cnt=primes.size();
	vector<map<int,int>>mps;
	for (int i = 0; i < N; ++i) {
		mps.push_back(map<int,int>());
		int rest=v[i];
		for (auto p : primes) {
			while (rest%p == 0) {
				rest/=p;
				mps[i][p]++;
			}
		}
	}
	map<int,int>all_gcd(mps[0]);
	for (int i = 1; i < N; ++i) {
		for (auto m : all_gcd) {
			auto it=mps[i].find(m.first);
			if (it == mps[i].end()) {
				all_gcd[m.first]
			}
			else {
				all_gcd[m.first]=min(all_gcd[m.first],mps[i][m.first]);
			}
		}
	}
	int answer=1e9;
	for (auto prime : primes) {
		int nans=0;
		int gcd_expo=(all_gcd.find(prime)==all_gcd.end()?0:all_gcd[prime]);
		for (int i = 0; i < N; ++i) {
			int cnt=0;
			if (mps[i].find(prime) != mps[i].end()) {
				cnt=mps[i][prime];
			}
			if (cnt == gcd_expo) {
				nans++;
			}
		}
		answer=min(answer,nans);
	}
	cout<<answer<<endl;*/
	long long int N,M;cin>>N>>M;
	if(N>M)swap(N,M);
	long long int answer=N*M/2*2;
	if (N == 1) {
		answer=(M/6)*6;
		if (M % 6 <= 3) {

		}else if(M%6==4)answer+=2;
		else if(M%6==5)answer+=4;
	}
	else if (N == 2) {
		if(M==2)answer=0;
		else if(M==3)answer=4;
		else if(M==7)answer=12;
	}
	cout<<answer<<endl;
	return 0;
}