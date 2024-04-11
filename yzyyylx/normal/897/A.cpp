#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
char ch[110],tmp1,tmp2;

int main()
{
	int i,j,p,q;
	cin>>n>>m;
	scanf("%s",ch+1);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d %c %c",&p,&q,&tmp1,&tmp2);
		for(j=p;j<=q;j++)
		{
			if(ch[j]==tmp1) ch[j]=tmp2;
		}
	}
	cout<<ch+1;
}