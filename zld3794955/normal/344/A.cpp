#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,t=1;
char ch[10]={},c=0;
int main()
{	
	scanf("%d\n",&n);
	while(n--)
	{	
		gets(ch);
		if(ch[0]==c)
			++t;
		c=ch[1];
	}
	printf("%d\n",t);
	return 0;
}