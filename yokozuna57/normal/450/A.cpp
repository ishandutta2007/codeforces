#include<iostream>
using namespace std;

int main(){
	int n,m;
	int a[102];

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}

	int ret=0;

	for(int i=1;i<n;i++){
		if(a[i]/m>=a[ret]/m)ret=i;
	}

	printf("%d\n",ret+1);
}