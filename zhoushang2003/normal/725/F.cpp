#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,x,y,X,Y,q[N],t,A;
int main()
{
	cin>>n;
	while(n--&&cin>>x>>y>>X>>Y)
		if(x+y>=X+Y)
			q[++t]=x+y,q[++t]=X+Y,A+=x+X;
		else if(x>Y)
			A+=x-Y;
		else if(y>X)
			A+=X-y;
	sort(q+1,q+t+1);
	for(int i=1;i<t;i+=2)
		A-=q[i];
	cout<<A;
	return 0;
}