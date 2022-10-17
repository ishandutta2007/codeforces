#include<iostream>
using namespace std;

int x,y;
int n,m,k;

void get_next(){
	if(x%2==0){
		y--;
		if(y==0){
			x++; y=1;
		}
	}
	else {
		y++;
		if(y>m){
			x++; y=m;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);

	x=1; y=1;

	for(int i=1;i<k;i++){
		printf("2");
		printf(" %d %d",x,y); get_next();
		printf(" %d %d\n",x,y); get_next();
	}

	printf("%d",n*m-2*(k-1));
	for(int i=0;i<n*m-2*(k-1);i++){
		printf(" %d %d",x,y); get_next();
	}
	printf("\n");
}