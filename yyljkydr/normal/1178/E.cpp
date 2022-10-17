#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

char s[N];

int n,ok[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while(r>=l)
	{
		if(s[l]==s[r])
			ok[l]=ok[r]=1,l++,r--;
		else if(s[l]==s[r-1])
			r--;
		else if(s[l+1]==s[r])
			l++;
		else
			l++,r--;
	}
	for(int i=1;i<=n;i++)
		if(ok[i])
			printf("%c",s[i]);
}