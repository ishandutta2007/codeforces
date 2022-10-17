#include<bits/stdc++.h>
#define N 
using namespace std;

int n,cnt[10];
string str;

inline void fj(int u)
{
	int i;
	for(i=2;u>1;i++)
	{
		for(;u%i==0;)
		{
			u/=i;
			cnt[i]++;
		}
	}
}

inline void ffj(int u)
{
	int i;
	for(i=2;u>1;i++)
	{
		for(;u%i==0;)
		{
			u/=i;
			cnt[i]--;
		}
	}
}

int main()
{
	int i,j,k,p;
	cin>>n;
	cin>>str;
	for(i=0;i<n;i++)
	{
		p=str[i]-'0';
		for(j=2;j<=p;j++)
			fj(j);
	}
//	return 0;
	for(i=9;i>=2;i--)
	{
		for(j=1;j<=cnt[i];j++)
		{
			printf("%d",i);
			for(k=2;k<i;k++) ffj(k);
		}
	}
}