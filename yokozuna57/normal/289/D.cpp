#include<iostream>
using namespace std;

long long int f(long long int x,long long int y){
	if(y==0)return 1;
	return (f(x,y-1)*x)%1000000007;
}

int main(){
	long long int n,k;
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",(f(k,k-1)*f(n-k,n-k))%1000000007);
}