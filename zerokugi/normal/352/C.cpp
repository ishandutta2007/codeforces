#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const double INF=9999.0;
const double EPS=1e-4;
#define MAX_V 2000*2+2
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)


vector<double> P;

main(){
	int n,i,j;
	cin >> n;
	double sum = 0;
	for(i=0;i<n*2;i++){
		double x;
		cin >> x;
		if(fmod(x, 1) < EPS) continue;
		P.push_back(fmod(x, 1));
		sum += fmod(x, 1);
	}
	sort(P.begin(), P.end());
	double Max=0, Min=0;
	
	for(i=0;i<P.size();i++){
		if(i<n) Max += 1;
		else Max += 0;
		if(i < (int)P.size()-n) Min += 1;
	}
	double ans;
	if(sum < Min) ans = Min - sum;
	else if(Max < sum) ans = sum - Max;
	else ans = min(fmod(sum, 1), 1-fmod(sum, 1));
	printf("%.3f\n", ans);

	return 0;
}