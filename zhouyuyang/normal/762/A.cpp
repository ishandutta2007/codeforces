#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
long long n,d,sum,s;
int main(){
	scanf("%I64d%I64d",&n,&d);
	for (ll i=1;i*i<=n;i++)
		if (n%i==0){
			s++;
			if (i*i!=n) s++;
		}
	sum=0;
	for (ll i=1;i*i<=n;i++)
		if (n%i==0){
			sum++;
			if (sum==d){
				printf("%I64d",i);
				return 0;
			}
			if (sum+d-1==s){
				printf("%I64d",n/i);
				return 0;
			}
		}
	printf("-1");
}