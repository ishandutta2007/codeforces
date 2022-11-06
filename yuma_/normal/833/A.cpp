#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
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

vector<int>anss1,anss2;
int get_nums(int n,int k) {
	
	for (int i = 0; i < primes.size(); ++i) {
		while (n%primes[i] == 0) {
			n/=primes[i];
			if (k) {
				anss1[i]++;
			}
			else {
				anss2[i]++;
			}
		}
	}
	return n;
}

int main() {
	int N;cin>>N;

	hurui(1000);
	while (N--) {
		int a,b;
		scanf("%d %d",&a,&b);

		anss1.clear();
		anss1.resize(primes.size());
		anss2.clear();
		anss2.resize(primes.size());
		a=get_nums(a,1);


		b=(get_nums(b,0));

		bool ok=true;
		for (int i = 0; i < primes.size(); ++i) {
			int x=anss1[i];
			int y=anss2[i];

			if((x+y)%3!=0)ok=false;
			else {
				if(2*x<y||2*y<x)ok=false;
			}
		}
		if (a == 1 && b == 1) {

		}
		else if (a == 1) {
			ok=false;
		}
		else if (b == 1) {
			ok=false;
		}
		else {
			if (a*a == b || b*b == a) {

			}
			else {
				ok=false;
			}
		}
		if(ok)printf("Yes");
		else printf("No");
		printf("\n");
	}
	return 0;
}