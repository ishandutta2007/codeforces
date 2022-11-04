#include<bits/stdc++.h>
using namespace std;
double F[10001], P[10001], C, X[10001], Y[10001], fc[10001];
int N;
void Read(){
	int X;
	scanf("%d%d", &N, &X);
	C = X / 1000000.0;
	for (int i = 0; i <= N; i++){
		scanf("%d", &X);
		P[i] = (X ? X * 1e20 : 1);
	}
}
int main(){
	Read();
	fc[0] = 1;
	for (int i = 1; i <= N; i++)
		fc[i] = fc[i - 1] * i;
	for (int i = 0; i <= N; i++)
		F[i] = i;
	for (int i = 0; i < N; i++)
		Y[i] = P[i + 1] / P[i] * (i + 1) / (N - i);
	for (int i = N - 1; ~i; i--)
		for (int j = 0; j <= i; j++){
			X[j] = (X[j] + X[j + 1] * Y[j] + Y[j]) / (1 + Y[j]);
			Y[j] = Y[j] * (1 + Y[j + 1]) / (1 + Y[j]);
			F[j] = std::max < long double > (j, (F[j + 1] - F[j]) * (X[j] / (N - i)) + F[j] - C);
		}
	printf("%.15lf\n", F[0]);
}