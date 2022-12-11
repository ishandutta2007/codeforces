#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[200];
int main()
{
	a['v']=1;
	a['<']=2;
	a['^']=3;
	a['>']=4;
	char c1,c2;
	cin>>c1>>c2;
	int x=a[c1];
	int y=a[c2];
	int n;
	scanf("%d",&n);
	n%=4;
	int s1=0,s2=0;
	if((x+n-1)%4+1==y)
		s1=1;
	if((x-n+3)%4+1==y)
		s2=1;
	if(s1&&!s2)
		printf("cw\n");
	else if(s2&&!s1)
		printf("ccw\n");
	else
		printf("undefined\n");
	return 0;
}