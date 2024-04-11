#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
#define ll long long 
using namespace std;
int n,x;
int main(){
	scanf("%d",&n);
	for (int i=0;i<=9;i++){
		x=1;
		for (int j=1;j<=i;j++) x*=10;
		for (int j=1;j<=9;j++)
			if (x*j>n){
				printf("%d",x*j-n);
				return 0;
			}
	}
}