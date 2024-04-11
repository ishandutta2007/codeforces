#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const long double eps = 1e-12;

int n, x[MAXN], y[MAXN], z[MAXN], px, py, pz, vp, vs;

long double dist(long double dx, long double dy, long double dz){
	return sqrtl(dx * dx + dy * dy + dz * dz);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
	scanf("%d %d", &vp, &vs);
	scanf("%d %d %d", &px, &py, &pz);
	
	if(x[0] == px && y[0] == py && z[0] == pz){
		printf("YES\n0\n%d %d %d\n", x[0], y[0], z[0]);
		return 0;
	}
	
	long double st = 0.0;
	for(int i = 0; i < n; i++){
		long double en = st + dist(x[i + 1] - x[i], y[i + 1] - y[i], z[i + 1] - z[i]) / vs;
		long double pen = dist(x[i + 1] - px, y[i + 1] - py, z[i + 1] - pz) / vp;
			
		if(pen < en + eps){
			long double L = 0, R = 1.0;
			while(fabs(R - L) > eps){
				long double mid = (L + R) / 2;
				
				long double cs = st * (1.0 - mid) + en * mid;
				long double cp = dist(x[i] * (1.0 - mid) + x[i + 1] * mid - px,
								 y[i] * (1.0 - mid) + y[i + 1] * mid - py,
								 z[i] * (1.0 - mid) + z[i + 1] * mid - pz) / vp;
								 
				if(cp < cs)R = mid;
				else L = mid;
			}
			
			printf("YES\n%.10Lf\n%.10Lf %.10Lf %.10Lf\n", st * (1.0 - L) + en * L,
													  x[i] * (1.0 - L) + x[i + 1] * L,
													  y[i] * (1.0 - L) + y[i + 1] * L,
													  z[i] * (1.0 - L) + z[i + 1] * L);
			return 0;
		}else{
			st = en;
		}
	}
	printf("NO\n");
	
    return 0;
}