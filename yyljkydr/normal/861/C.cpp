#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int n,now,cnt;

char s[N];

bool vis[27];

bool chk(char ch)
{
	return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(chk(s[i]))
		{
			cout<<s[i];
			now=i+1;
			continue;
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=now;j<=i;j++)
			vis[s[j]-'a']=1;
		for(int j=0;j<26;j++)
			if(vis[j])
				cnt++;
		if(cnt>1&&i-now+1>=3) 
		{
			cout<<" ";
			now=i;
		}
		cout<<s[i];
	}
}