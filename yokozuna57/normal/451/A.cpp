#include<iostream>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	if(min(n,m)%2==0)printf("Malvika\n");
	else printf("Akshat\n");
}