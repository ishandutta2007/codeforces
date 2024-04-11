#include <bits/stdc++.h>
using namespace std;

int m, n;
int main(){
	scanf("%d %d", &m, &n);

	double r = 0.0;
	for(int i = 1; i <= m; i++)
		r += i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
	printf("%.15f\n", r);

    return 0;
}