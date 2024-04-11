#include<bits/stdc++.h>
using namespace std;
 
const int N=1e3+1e2+7;
 
int T,k,n;
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1,j=0;i<=n;i++,j=(j+1)%3)
			putchar(j+'a');
		puts("");
	}
}