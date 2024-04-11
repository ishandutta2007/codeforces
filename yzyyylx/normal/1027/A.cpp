#include<bits/stdc++.h>
#define ll long long
#define db doble
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

int T,n,m;
char str[N];

int main()
{
	int i,j;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		for(i=1;i<=n/2;i++)
		{
//			cout<<str[i]<<" "<<str[n-i]<<endl;
			if(abs(str[i]-str[n-i+1])!=2&&abs(str[i]-str[n-i+1]))
			{
				puts("NO");
				break;
			}
		}
		if(i>n/2)
		{
			puts("YES");
		}
	}
}