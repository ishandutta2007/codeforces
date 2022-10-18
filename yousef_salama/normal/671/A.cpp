#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, xi[MAXN], yi[MAXN], ax, ay, bx, by, tx, ty;
double dist(long long dx, long long dy){
	return sqrt(dx * dx + dy * dy);
}

double da[MAXN], db[MAXN], dt[MAXN];
int main(){
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);

	scanf("%d", &n);

	double rt = 0.0;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &xi[i], &yi[i]);

		da[i] = dist(xi[i] - ax, yi[i] - ay);
		db[i] = dist(xi[i] - bx, yi[i] - by);
		dt[i] = dist(xi[i] - tx, yi[i] - ty);

		rt += dt[i];
	}

	double r = 1e18;
	for(int i = 0; i < n; i++){
		r = min(r, 2 * rt - dt[i] + da[i]);
		r = min(r, 2 * rt - dt[i] + db[i]);
	}

	int j = 0;
	for(int i = 0; i < n; i++)
		if(da[i] - dt[i] < da[j] - dt[j])j = i;

	for(int i = 0; i < n; i++)if(i != j)
		r = min(r, 2 * rt - dt[j] + da[j] - dt[i] + db[i]);

	int k = -1;
	for(int i = 0; i < n; i++)if(i != j)
		if(k == -1 || da[i] - dt[i] < da[k] - dt[k])k = i;

	for(int i = 0; i < n; i++)if(i != k)
		r = min(r, 2 * rt - dt[k] + da[k] - dt[i] + db[i]);

	printf("%.15f\n", r);

	return 0;
}