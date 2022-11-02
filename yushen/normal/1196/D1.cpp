#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
string str;
int n,k,q,ans,mini;
bool val[Maxn];
int main()
{
	string t="RGB";
	scanf("%d",&q);
	while(q--)
	{
		mini=0x3f3f3f3f;
		scanf("%d%d",&n,&k);
		cin>>str;
		for(int i=0;i<3;i++)
		{
			ans=0;
			memset(val,0,sizeof(bool[n]));
			for(int j=0;j<n;j++)
				if(str[j]!=t[(j+i)%3]) val[j]=true;
			for(int j=0;j<n;j++)
			{ 
				ans+=val[j];
				if(j>=k) ans-=val[j-k];
				if(j>=k-1)
					mini=min(mini,ans);
			}
		}
		printf("%d\n",mini);
	}
	return 0;
}