#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	int a=t1+s*v1+t1,b=t2+s*v2+t2;
	if(a>b)puts("Second");
	else if(a==b)puts("Friendship");
	else puts("First");
}