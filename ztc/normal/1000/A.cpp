#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cmath>
#define inf 1000000007
using namespace std;
int a[10][2],i,j=0,n,cnt=0;
void sr(int b)
{
	string s;
	cin>>s;
	if(s=="XXXS")a[1][b]+=1;
	if(s=="XXS")a[2][b]+=1;
	if(s=="XS")a[3][b]+=1;
	if(s=="S")a[4][b]+=1;
	if(s=="M")a[5][b]+=1;
	if(s=="L")a[6][b]+=1;
	if(s=="XL")a[7][b]+=1;
	if(s=="XXL")a[8][b]+=1;
	if(s=="XXXL")a[9][b]+=1;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)sr(j);
	j=1;
	for(i=1;i<=n;i++)sr(j);
	for(i=1;i<=9;i++)cnt+=abs(a[i][1]-a[i][0]);
	printf("%d",cnt/2);
}