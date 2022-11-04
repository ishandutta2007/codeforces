#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	printf("%d %d %c",(k-1)/m/2+1,(k-1)/2%m+1,(k%2)?'L':'R');
}