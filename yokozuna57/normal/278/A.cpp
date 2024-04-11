#include<iostream>
using namespace std;

int main(){
	int n,t[100+2],a,b,c=0,d=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&t[i]);
	scanf("%d%d",&a,&b);
	int k=(a+n-1)%n;
	while(1){
		c+=t[k];
		k++;
		k%=n;
		if(k==(b+n-1)%n)break;
	}
	while(1){
		d+=t[k];
		k++;
		k%=n;
		if(k==(a+n-1)%n)break;
	}
	if(a==b)c=0;
	printf("%d\n",min(c,d));
}