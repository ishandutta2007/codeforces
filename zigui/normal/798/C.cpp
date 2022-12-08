#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

double sq(double x){ return x*x; }
ll sq(ll x){ return x*x; }

const int MX = 100005;

int A[MX];
int N;

int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	int g = 0;
	for(int i = 1; i <= N; i++) g = gcd(g, A[i]);
	if( g != 1 ) return !printf("YES\n0\n");
	
	int ans = 0, cnt = 0;
	for(int i = 1; i <= N; i++){
		if( A[i]%2 == 1 ) cnt++;
		else ans += cnt%2 == 1 ? cnt/2 + 2 : cnt/2, cnt = 0;
	}
	ans += cnt%2 == 1 ? cnt/2 + 2 : cnt/2;
	printf("YES\n%d", ans);
}