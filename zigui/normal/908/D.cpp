#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<string>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MM = 1000000007;
const int MX = 1005;

ll pw(ll a, ll b = MM-2){
	ll r = 1;
	while(b){
		if(b&1) r = r*a % MM;
		a = a*a%MM; b /= 2;
	}
	return r;
}

int T[MX][MX];

int main()
{
	ll K, Pa, Pb;
	scanf("%lld%lld%lld", &K, &Pa, &Pb);
	ll Pc = Pa + Pb;
	Pa = Pa * pw(Pc) % MM;
	Pb = Pb * pw(Pc) % MM;
	T[1][0] = 1;
	for(int i = 1; i <= K; i++){
		for(int j = 0; j <= K; j++){
			if (i+j <= K) T[i][i+j] = (T[i][i+j] + T[i][j] * Pb % MM);
			if( i <= K ) T[i+1][j] = (T[i+1][j] + T[i][j] * Pa % MM);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= K; i++){
		for(int j = 0; j < K; j++){
			if( i != K && i+j >= K ) ans = (ans + T[i][j] * Pb % MM * (i+j)) % MM;
			if( i == K ){
				ll add = (Pb*K+Pa) % MM * pw(Pb) % MM;
				ans = (ans + T[i][j] * (add + j)) % MM;
			}
		}
	}
	printf("%lld\n", ans);
}