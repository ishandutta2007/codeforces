#include<bits/stdc++.h>
#define ll long long
#define N 
using namespace std;

string a;
int n,wz=1000,cnt;

int main()
{
	int i,j;
	cin>>a;
	for(i=0;i<a.size();i++)
	{
		if(a[i]=='1') break;
	}
	for(j=i+1;j<a.size();j++)
	{
		if(a[j]=='0')
		{
			cnt++;
		}
	}
	if(cnt>=6)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}