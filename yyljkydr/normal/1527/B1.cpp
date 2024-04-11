#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int zero=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
				zero++;
		if(zero%2==0||(zero==1))
			puts("BOB");
		else
			puts("ALICE");
	}
}