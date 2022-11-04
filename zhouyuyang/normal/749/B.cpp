#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d,e,f;
int main(){
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("3\n%d %d\n%d %d\n%d %d",a+c-e,b+d-f,a-c+e,b-d+f,c+e-a,d+f-b);
}