#include<iostream>
using namespace std;
const int N=1e5+1;
int n,m,x,y,c[N],A;
double s;
int main()
{
	cin>>n>>s;
	m=n-1;
	while(m--&&cin>>x>>y)
		c[x]++,c[y]++;
	for(int i=1;i<=n;i++)
		if(c[i]==1)
			A++;
	printf("%.7lf",s/A*2);
	return 0;
}