#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int main () {
	stack<int> sta;
	long long s,t,a;
	while (scanf("%I64d %I64d %I64d",&t,&s,&a) != EOF) {
		if ((a-t) % s==0 && a>=t) puts("YES");
		else if ((a-t)%s==1 && a>t+1) puts("YES");
		else puts("NO");
	}
}