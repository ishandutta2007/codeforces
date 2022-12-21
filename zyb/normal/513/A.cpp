#include<stdio.h>
using namespace std;
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	if (n<=m) puts("Second");
	else puts("First");
}