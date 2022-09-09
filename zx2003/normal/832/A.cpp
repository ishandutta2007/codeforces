#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
int main(){
	cin>>n>>k;
	if((n/k)&1)puts("YES");
		else puts("NO");
}