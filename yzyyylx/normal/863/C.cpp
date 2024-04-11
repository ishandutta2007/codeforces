#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll A[140][140],B[140][140],a,b,da,db,len,bs[140][140],df1[1000],df2[1000],m1,m2,n;

void cmp(int u,int v)
{
	if(u-v==1||v-u==2) da++;
	if(v-u==1||u-v==2) db++;
}

int main()
{
	ll i,j,k;
	cin>>n>>a>>b;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	j=n;
	for(i=1;i<=j;i++)
	{
		if(bs[a][b]!=0)
		{
			len=i-bs[a][b];
			m1=da-df1[bs[a][b]];
			m2=db-df2[bs[a][b]];
			break;
		}
		df1[i]=da;
		df2[i]=db;
		cmp(a,b);
		bs[a][b]=i;
		k=a;
		a=A[a][b];
		b=B[k][b];
		n--;
	}
//	cout<<len<<" "<<m1<<" "<<m2<<" ";
	if(n==0)
	{
		cout<<da<<" "<<db;
		return 0;
	}
	k=n/len;
	da+=k*m1;
	db+=k*m2;
	k=n%len;
	for(i=1;i<=k;i++)
	{
		cmp(a,b);
		j=a;
		a=A[a][b];
		b=B[j][b];
	}
	cout<<da<<" "<<db;
}