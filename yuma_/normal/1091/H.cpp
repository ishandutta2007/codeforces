#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
const int MAX_N=200001;
bitset< MAX_N>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	for (int i = 2; i < MAX_N; ++i) {
		primes[i]=true;
	}
	for (int i = 2; i < amax; ++i) {
		if (primes[i]) {
			for (int j = 2 * i; j < amax; j += i)primes[j]=false;
		}
	}
	flag = true;
}

int main()
{
	hurui(MAX_N);
	vector<bitset< MAX_N>>dps(100);
	vector<int>anss(MAX_N);

	bitset<MAX_N>prime_doubles;
	{
		vector<long long int>prime_vs;
		for (int i = 0; i < MAX_N; ++i) {
			if (primes[i]) {
				prime_vs.push_back(i);
			}
		}
		for (int i = 0; i < prime_vs.size(); ++i) {
			prime_doubles[prime_vs[i]]=true;
			for (int j = i; j < prime_vs.size(); ++j) {
				long long int val=prime_vs[i]*prime_vs[j];
				if(val>=MAX_N)break;
				else {
					prime_doubles[val]=true;
				}
			}
		}
	}

	int N,M;scanf("%d %d",&N,&M);
	prime_doubles[M]=false;
	anss[0]=0;
	for (int i = 0; i < MAX_N; ++i) {
		while(dps[anss[i]][i])anss[i]++;
		dps[anss[i]]|=prime_doubles<<i;
	}
	int axor=0;
	for (int i = 0; i < N; ++i) {
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		int ab=b-a-1;
		axor^=anss[ab];
		int bc=c-b-1;
		axor^=anss[bc];
	}
	if (axor == 0) {
		cout<<"Bob"<<endl;
		cout<<"Alice"<<endl;
	}
	else {
		cout<<"Alice"<<endl;
		cout<<"Bob"<<endl;
	}
	return 0;
}