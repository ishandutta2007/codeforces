#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int n,r;

const int maxn = 1005;
int x[maxn];
double y[maxn];
int main(){
	cin >> n >> r;
	for(int i = 1;i <= n;i++){
		scanf("%d",&x[i]);
	}
	for(int i = 1;i <= n;i++){
		double tmp = r;
		for(int j = 1;j < i;j++){
			if(abs(x[i] - x[j]) > 2 * r) continue;
			int dx = abs(x[i] - x[j]);
			double dy = sqrt(4.0 * r * r - 1.0 * dx * dx);
			tmp = max(tmp,dy + y[j]);
		}
		y[i] = tmp;
	}	
	for(int i = 1;i <= n;i++){
		printf("%.10lf ",y[i]);
	}
	return 0;
}