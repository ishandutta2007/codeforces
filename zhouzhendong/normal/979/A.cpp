#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	scanf("%I64d",&n);
	if (n!=0) n++;
	printf("%I64d\n",n%2==0?n/2:n);
	return 0;
}