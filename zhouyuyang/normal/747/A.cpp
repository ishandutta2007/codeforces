#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream> 
#define N 50005
#define eps 1e-9
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for (int i=int(sqrt(n));i;i--)
		if (n%i==0){
			printf("%d %d",i,n/i);
			return 0;
		}
}