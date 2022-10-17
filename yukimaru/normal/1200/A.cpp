/*********************************************************************
    > File Name: 1200_A.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		bool f[10]={0};
		char s[100005]={0};
		scanf("%s", s);
		for(int i=0; i<n; i++)
		{
			if(s[i] == 'L')
				for(int j=0; j<=9; j++)
					if(f[j] == 0)
					{
						f[j]=1;
						break;
					}
			if(s[i] == 'R')
				for(int j=9; j>=0; j--)
					if(f[j] == 0)
					{
						f[j]=1;
						break;
					}
			if(s[i]>='0' && s[i]<='9') f[s[i]-'0']=0;
		}
		for(int i=0; i<=9; i++) printf("%d", f[i]);
		printf("\n");
	}
	return 0;
}