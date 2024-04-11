#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> P;
int main(){
	int n;
	scanf("%d",&n);
	
	int p = 1;
	for(int i = 2 ; i*i <= n ; i ++){
		if(n%i == 0){
			while(n%i == 0){
				n /= i;
				p *= i;
			}
			break;
		}
	}
	if(p == 1 || n == 1){
		puts("NO");
		return 0;
	}
	int q = n;
	n = p*q;
	
	int x = 1;
	while((x*q+1)%p != 0){
		x ++;
	}
	int y = (n-1-q*x)/p;
	
	puts("YES\n2");
	printf("%d %d\n%d %d\n",x,p,y,q);
}