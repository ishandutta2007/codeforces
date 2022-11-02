#include<bits/stdc++.h>
using namespace std;
int main()
{	
	puts("401\n1 1000000");
	for(int i=1;i<=399;++i)
		printf("%d %d\n",i*400+500000,400-i);
	puts("1000000 1000000");
	return 0;
}