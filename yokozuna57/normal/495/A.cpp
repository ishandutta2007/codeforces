#include<iostream>
using namespace std;

int main(){
	int a[10] = {2,7,2,3,3,4,2,5,1,2};

	int n;
	scanf("%d",&n);

	printf("%d\n",a[n/10] * a[n%10]);
}