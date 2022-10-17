#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long int n,a;
	long long int sum=0;
	long long int ret=0;

	scanf("%I64d",&n);
	for(long long int i=0;i<n;i++){
		scanf("%I64d",&a);
		if(a==1)sum++;
		if(a==0)ret+=sum;
	}
	
	printf("%I64d\n",ret);
}