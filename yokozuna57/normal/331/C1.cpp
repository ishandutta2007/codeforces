#include<iostream>
using namespace std;

int solver(int n){
	if(n<=0)return 0;
	else {
		int m=0;
		int N=n;
		while(n>0){ m=max(m,n%10); n/=10; }
		return solver(N-m)+1;
	}
}

int main(){
	int n;
	scanf("%d",&n);

	printf("%d\n",solver(n));
}