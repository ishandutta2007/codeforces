#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL a,b;
	cin >>a >> b;
	if ((a/b)%2==0) puts("NO");
	else puts("YES");
}