#include <bits/stdc++.h>
using namespace std;

int n;
bool isprime(int x){
	for(int y = 2; y * y <= x; y++)
		if(x % y == 0)return false;
	return true;
}
int main(){
	scanf("%d", &n);

	vector <int> v;
	for(int i = 2; i <= n; i++)if(isprime(i))
	for(int k = i; k <= n; k *= i)v.push_back(k);

	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++){
		if(i > 0)printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");

	return 0;
}