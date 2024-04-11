#include<bits/stdc++.h>
using namespace std;
const int N=220;
char ch[N]={},c[3]={'B','G','R'};
int n,a[3]={};
int main()
{	
	cin>>n>>ch;
	for(int i=0;i<n;++i)
		for(int j=0;j<3;++j)
			if(ch[i]==c[j])
				++a[j];
	int sum=!a[0]+!a[1]+!a[2];
	if(sum==2)
	{
		for(int j=0;j<3;++j)
			if(a[j]==n)
			{
				cout<<c[j]<<endl;
				return 0;
			}
	}
	if(n==1)
	{
		cout<<ch[0]<<endl;
		return 0;
	}
	if(n==2)
	{
		for(int j=0;j<3;++j)
			if(a[j]==0)
			{
				cout<<c[j]<<endl;
				return 0;
			}
	}
	if(sum==1)
	{
		bool flag=true;
		for(int j=0;j<3;++j)
			if(a[j]==1)
				flag=false;
		if(!flag)
		{
			for(int j=0;j<3;++j)
				if(a[j]<n-1)
					cout<<c[j];
			cout<<endl;
		}
		else
			puts("BGR");
	}
	else
		puts("BGR");
	return 0;
}