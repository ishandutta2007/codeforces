#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second
#define N 110 
#define M 
using namespace std;

int m,n,cb;
char str[N];

int main()
{
	int i,j;
	cin>>n;
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(str[i]=='8') cb++;
	}
	cout<<min(cb,n/11);
}