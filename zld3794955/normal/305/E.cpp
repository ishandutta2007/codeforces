#include<bits/stdc++.h>
using namespace std;
const int L=5050;
char ch[L]={};
int n,sg[L]={};
int main()
{
	gets(ch+1);
	n=strlen(ch+1);
	sg[1]=sg[2]=0;
	for(int i=3;i<=n;++i)
	{
		bool b[L]={};
		for(int j=1;j<i-1;++j)
			b[sg[j]^sg[i-1-j]]=true;
		for(int j=0;j<=n;++j)
			if(!b[j])
			{
				sg[i]=j;
				break;
			}
	}
	int l=1,sum=0;
	while(l<n)
	{
		int p=l+2;
		while(p<=n && (p-l)%2 ? ch[p]==ch[l+1] : ch[p]==ch[l])
			++p;
		sum^=sg[p-l];
		l=p-1;
	}
	puts(sum ? "First" : "Second");
	cerr<<"sum="<<sum<<endl;
	if(sum)
	{
		l=1;
		while(l<n)
		{
			int p=l+2;
			while(p<=n && (p-l)%2 ? ch[p]==ch[l+1] : ch[p]==ch[l])
				++p;
			for(int i=l+1;i<p;++i)
				if(sum==(sg[p-l]^sg[i-l]^sg[p-i-1]))
				{
					printf("%d\n",i);
					return 0;
				}
			l=p-1;
		}
	}
	return 0;
}