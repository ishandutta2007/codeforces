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

int main()
{
	string D;
	cin >> D;
	int cnt = 0;
	for(int i = 0; i < D.size(); i++){
		if( D[i] != D[D.size()-i-1] ) cnt++;
	}
	if( cnt == 2 || cnt == 0 && D.size()%2 == 1 ) printf("YES");
	else printf("NO");
}