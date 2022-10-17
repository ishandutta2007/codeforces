#include<iostream>
using namespace std;

int main(){
	int n;
	int d[102];
	int a,b;

	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d",&d[i]);
	}
	scanf("%d%d",&a,&b);

	int ret=0;
	for(int i=a;i<b;i++){
		ret+=d[i];
	}

	printf("%d\n",ret);
}