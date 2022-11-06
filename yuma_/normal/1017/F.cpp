#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;
ld eps=1e-9;


unsigned long long int N;
unsigned long long int A, B, C, D;

const signed long long int Mod=1ll<<32;

unsigned long long int fun(const unsigned long long int a) {
	unsigned long long int ans=0;
	ans+=(a*a*a)%Mod*A;
	ans%=Mod;
	ans+=(a*a)%Mod*B;
	ans%=Mod;
	ans+=(a)%Mod*C;
	ans%=Mod;
	ans+=D;
	ans%=Mod;
	return ans;
}

unsigned long long int plu(
	const unsigned long long int a) {
	unsigned long long int rest(N);
	rest/=a;
	unsigned long long int ans=0;
	while (rest) {
		ans+=fun(a)*rest;
		rest/=a;
		ans%=Mod;
	}
	return ans;
}

const long long int X=50000001;

bitset<X>bs1;
bitset<X>bs5;
int main() {cin>>N>>A>>B>>C>>D;


	bs1[0]=true;

	unsigned long long int ans=0;
	ans+=plu(3);
	ans+=plu(2);
	for (int i = 0; i <X; ++i) {
		if(!bs1[i]){
			ans+=plu(i*6+1);
			for (int k = i * 7+1; k < X; k += 6*i + 1) {
				bs1[k]=true;
			}
			for (int k = i * 5  ; k < X; k += 6 * i + 1) {
				bs5[k]=true;
			}
		}
		if (!bs5[i]) {
			ans+=plu(i*6+5);
			for (int k = i * 5 + 4; k < X; k += 6 * i + 5) {
				bs1[k] = true;
			}
			for (int k = i * 7 + 5; k < X; k += 6 * i + 5) {
				bs5[k]=true;
			}
			
		}
		ans%=Mod;
	}
	cout<<ans<<endl;
	return 0;
}