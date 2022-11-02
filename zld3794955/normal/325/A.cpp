#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=10,Inf=1<<30;
int n;
int main()
{	
	cin>>n;
	int lx=Inf,rx=-Inf,ly=Inf,ry=-Inf;
	long long S=0;
	for(int i=1;i<=n;++i)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		lx=min(lx,x1);
		rx=max(rx,x2);
		ly=min(ly,y1);
		ry=max(ry,y2);
		S+=(long long)(y2-y1)*(x2-x1);
	}
	//cout<<"lx="<<lx<<" ly="<<ly<<" rx="<<rx<<" ry="<<ry<<endl;
	if(ry-ly!=rx-lx || S!=(long long)(ry-ly)*(rx-lx))
		puts("NO");
	else
		puts("YES");
	return 0;
}