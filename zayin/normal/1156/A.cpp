#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,a[maxn];
int main()	{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
	int cnt=0;
	for (int i=2;i<=n;++i)	{
		if (!((a[i]==1)^(a[i-1]==1)))
			return puts("Infinite");
		if ((a[i]^a[i-1]^1)==2)	{
			if (i>=3&&a[i-2]==3)
				cnt+=2;
			else
				cnt+=3;
		} else	
		if ((a[i]^a[i-1]^1)==3)	{
			cnt+=4;
		}
	}
	puts("Finite");
	cout<<cnt<<endl;
	return 0;
}