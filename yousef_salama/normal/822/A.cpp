#include <bits/stdc++.h>
using namespace std;

int A, B;
int main(){
	scanf("%d %d", &A, &B);
	if(B < A)swap(A, B);

	long long x = 1;
	for(int i = 1; i <= A; i++)
		x *= i;
	printf("%I64d\n", x);

	return 0;
}