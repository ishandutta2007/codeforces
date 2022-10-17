#include<iostream>
using namespace std;

int main(){
	long long int n,a[100000+2],sum=0,max=0;
	scanf("%I64d",&n);
	for(int i=0;i<n;i++){scanf("%I64d",&a[i]); sum+=a[i]; if(max<a[i])max=a[i];}
	sum=(sum-1)/(n-1)+1;
	if(max<sum)max=sum;
	printf("%I64d\n",max);
}