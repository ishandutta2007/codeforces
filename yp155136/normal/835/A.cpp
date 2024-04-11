#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int s,v1,v2,t1,t2;
	cin >>s >>v1>>v2>>t1>>t2;
	int x=v1*s+2*t1,y=v2*s+2*t2;
	if (x>y) puts("Second");
	else if (x<y) puts("First");
	else puts("Friendship");
}