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

string D[55];
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) cin >> D[i];
	int ans = 1e7;
	for(int i = 0; i < D[1].size(); i++){
		string E[55];
		for(int j = 2; j <= N; j++) E[j] = D[j];
		int cnt = 0;
		for(int j = 2; j <= N; j++){
			int cur = 1e7;
			for(int k = 0; k < E[j].size(); k++){
				if( E[j] == D[1] ){
					cur = k;
					break;
				}
				E[j] = E[j].substr(1, -1) + E[j][0];
			}
			cnt += cur;
		}
		ans = min(ans, cnt+i);
		D[1] = D[1].substr(1, -1) + D[1][0];
	}
	if( ans != 1e7 ) printf("%d\n", ans);
	else printf("-1\n");
}