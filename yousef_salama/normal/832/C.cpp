#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXT = 1000005;

int n, s, x[MAXN], ox[MAXN], v[MAXN], t[MAXN];

int ev1[MAXT + 5], ev2[MAXT + 5];
bool check(double f){
	memset(ev1, 0, sizeof ev1);
	memset(ev2, 0, sizeof ev2);

	for(int i = 0; i < n; i++){
		if(t[i] == 1){
			if(1.0 * x[i] <= f * v[i])ev1[0]++;
			else{
				if(1.0 * x[i] <= f * (s + v[i])){
					long long q = 1.0 * (x[i] - f * (v[i] + s)) * (s - v[i]);
					q = -q / s;
                    
					ev1[x[i]]++;
					if(x[i] + q + 1 < MAXT)ev1[x[i] + q + 1]--;
				}
			}
		}else{
			if(1.0 * x[i]<= f * v[i])ev2[0]++;
			else{
				if(1.0 * x[i] <= f * (s + v[i])){
					long long q = 1.0 * (x[i] - f * (v[i] + s)) * (s - v[i]);
					q = -q / s;

					ev2[max(0LL, ox[i] - q)]++;
					ev2[ox[i] + 1]--;
				}
			}

		}
	}

	int x1 = 0, x2 = 0;
	for(int i = 0; i < MAXT; i++){
		x1 += ev1[i];
		x2 += ev2[i];

		if(x1 > 0 && x2 > 0)return true;
	}
	return false;
}
int main(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &ox[i], &v[i], &t[i]);

		if(t[i] == 1)x[i] = ox[i];
		else x[i] = 1000000 - ox[i];
	}
	double L = 0, R = 10000000;
    
	int itr = 100;
	while(itr--){
		double mid = (L + R) / 2;

		if(check(mid))R = mid;
		else L = mid;
	}
	
	printf("%.15f\n", L);

	return 0;
}