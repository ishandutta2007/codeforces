#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,a,b,c,d;
int main(){
    scanf("%d",&n);
    printf("YES\n");
    for (int i=1;i<=n;i++){
    	scanf("%d%d%d%d",&a,&b,&c,&d);
    	printf("%d\n",1+2*(abs(a)%2)+abs(b)%2);
	}
}