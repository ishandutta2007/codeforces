#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",m&(1<<min(n,30))-1);
}