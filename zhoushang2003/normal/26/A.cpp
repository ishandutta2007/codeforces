#include<iostream>
using namespace std;
const int N=3001;
bool v[N];
int p[N],c,n,s,A;
int main()
{
	for(int i=2;i<N;i++)
	{
		if(!v[i])
			p[++c]=i;
		for(int j=1;j<=c&&i*p[j]<N;j++)
		{
			v[i*p[j]]=true;
			if(i%p[j]==0)
				break;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s=0;
		for(int j=1;j<=c;j++)
			if(i%p[j]==0)
				s++;
		if(s==2)
			A++;
	}
	cout<<A;
	return 0;
}