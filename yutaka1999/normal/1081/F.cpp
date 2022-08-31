#include <bits/stdc++.h>
#define SIZE 305
#define MX 30

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,bef;
bool flip;
int ans[SIZE];

int get(int l,int r)
{
	printf("? %d %d\n",l+1,r+1);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	flip=!flip;
	if(flip) x=n-x;
	return x;
}
int main()
{
	int t;
	scanf("%d %d",&n,&t);
	bef=t;
	flip=false;
	if(n==1)
	{
		ans[0]=t;
	}
	else
	{
		while(1)
		{
			int g=get(0,n-2);
			if(g!=t)
			{
				if(g>t) ans[n-1]=0;
				else ans[n-1]=1;
				bef=g;
				break;
			}
		}
		int pr=0;
		for(int i=0;i<n-2;i++)
		{
			int l=i+1,r;
			if(i%2==0) r=n-1;
			else r=n-2;
			while(1)
			{
				int g=get(l,r);
				if((g+bef)%2==l%2)//left
				{
					ans[i]=(l+bef-g)/2-pr;
					pr=i-pr;
					pr+=1-ans[i];
					bef=g;
					break;
				}
				bef=g;
			}
		}
		ans[n-2]=t;
		for(int i=0;i<n;i++)
		{
			if(i!=n-2)
			{
				ans[n-2]-=ans[i];
			}
		}
	}
	printf("! ");
	for(int i=0;i<n;i++) printf("%d",ans[i]);
	puts("");
	return 0;
}