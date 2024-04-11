#include<stdio.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
#include<functional>
#include<list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 200005;
const int MM = 1000000007;

int N;
struct data{
	ll t[MX];
	data operator+(const data &l)const{
		data r;
		for(int i = 1; i <= N; i++) r.t[i] = t[i] + l.t[i];
		return r;
	}
	data operator-(const data &l)const{
		data r;
		for(int i = 1; i <= N; i++) r.t[i] = t[i] - l.t[i];
		return r;
	}
};

ll rv[MX];

int main()
{
	scanf("%d", &N);
	rv[1] = 1;
	for(int i = 2; i <= N; i++) rv[i] = (MM - MM/i) * rv[MM%i] % MM;
	data r[4] = {};
	int V = N/4*4;
	ll m = 1;
	for(int i = 1; i <= V; i++){
		if( i%2 == 1 ){
			r[0].t[i] = m;
		}
		else{
			r[0].t[i] = (MM-m)% MM;
			m = m*(V/2-i/2)%MM * rv[i/2] % MM;
		}
	}
	if( V == 0 ){
		V++;
		r[0].t[1] = 1;
	}
	for(int j = V; j < N; j++){
		for(int i = 1; i <= N; i++){
			if( i%2 == 1 ) r[j-V+1].t[i] = (r[j-V].t[i] - r[j-V].t[i-1] + MM) % MM;
			else r[j-V+1].t[i] = (r[j-V].t[i] + r[j-V].t[i-1]) % MM;
		}
	}
	ll ans = 0, a;
	for(int i = 1; i <= N; i++){
		scanf("%lld", &a);
		ans = (ans + a*r[N-V].t[i])% MM;
	}
	printf("%lld\n", ans);
	return 0;
}