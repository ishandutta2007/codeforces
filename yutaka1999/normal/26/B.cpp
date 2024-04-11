#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>
#define SIZE 1000005

using namespace std;

stack <int> st;
char str[SIZE];

int main()
{
	scanf("%s",&str);
	int s=0,sum=0;
	int sz=strlen(str);
	int ret=sz;
	for(int i=0;i<sz;i++)
	{
		if(str[i]=='(') sum++;
		else
		{
			if(sum!=0) sum--;
			else ret--;
		}
	}
	printf("%d\n",ret-sum);
	return 0;
}