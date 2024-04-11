#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int n,i,j,flag;
	char s[10],names[8][10]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	scanf("%d%s",&n,s);
	for(i=0;i<8;i++)
	{
		if(strlen(names[i])==n)
		{
			flag=0;
			for(j=0;j<n;j++)
			{
				if(s[j]!='.'&&s[j]!=names[i][j])
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				printf("%s\n",names[i]);
				break;
			}
		}
	}
	return 0;
}