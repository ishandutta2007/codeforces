#include<iostream>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){printf("%d ",n); n--;}
	for(int i=1;i<n;i++)printf("%d ",i);
	printf("%d\n",n);
}