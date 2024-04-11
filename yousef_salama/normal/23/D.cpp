#include <bits/stdc++.h>
using namespace std;

int T, p[3];
double x[3], y[3];
complex <double> A[3];

double cross(complex <double> a, complex <double> b){
	return imag(a * conj(b));
}
bool solve(complex <double> a, complex <double> b, complex <double> c){
	complex <double> m1 = b - (a - b) / complex <double> (2, 0);
	complex <double> m1_ = m1 + (a - b) * complex <double> (0, 1);

	complex <double> m2 = (b + c) / complex <double> (2, 0);
	complex <double> m2_ = m2 + (b - c) * complex <double> (0, 1);

	double C = cross(m2 - m1, m2_ - m1);
	double dC = cross(m2 - m1_, m2_ - m1_);

	if(dC == C)return false;

	complex <double> v[4];

	v[1] = m1 + (m1_ - m1) * (C / (C - dC));
	v[2] = b - (v[1] - b);
	v[3] = a - (v[2] - a);
	v[0] = c - (v[1] - c);

	for(int i = 0; i < 4; i++)
		if(cross(v[(i + 1) % 4] - v[i], v[(i + 2) % 4] - v[i]) < 1e-7)return false;

	printf("YES\n");
	for(int i = 3; i >= 0; i--)
		printf(" %.9f %.9f", v[i].real(), v[i].imag());
	printf("\n");

	return true;
}
int main(){
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 3; i++)
			scanf("%lf %lf", &x[i], &y[i]);

		A[0] = {x[0], y[0]};
		A[1] = {x[1], y[1]};
		A[2] = {x[2], y[2]};

		for(int i = 0; i < 3; i++)p[i] = i;

		bool found = false;
		do{
			if(solve(A[p[0]], A[p[1]], A[p[2]])){
				found = true;
				break;
			}
		}while(next_permutation(p, p + 3));

		if(!found)printf("NO\n\n");
	}
	return 0;
}