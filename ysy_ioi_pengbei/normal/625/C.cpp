//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
int n,k,mat[504][504];
int main()
{
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<k;j++) mat[i][j]=++cnt;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j<=n;j++) mat[i][j]=++cnt;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=mat[i][k];
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
}