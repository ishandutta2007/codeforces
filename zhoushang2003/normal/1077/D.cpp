#include<iostream>
using namespace std;
const int M=2e5+1;
int n,k,x,c[M],l,r=M,s[M],t,A[M];
bool C(int p)
{
	for(int i=1;i<M;i++)
		s[i]=c[i];
	t=0;
	for(int i=1;i<M;i++)
		while(s[i]>=p)
			s[i]-=p,t++;
	return t>=k;
}
int main()
{
	cin>>n>>k;
	while(n--&&cin>>x)
		c[x]++;
	while(l<r)
		if(C((l+r+1)/2))
			l=(l+r+1)/2;
		else
			r=(l+r-1)/2;
	t=0; 
	for(int i=1;i<M;i++)
		while(c[i]>=l)
			A[t++]=i,c[i]-=l;
	for(int i=0;i<k;i++)
		cout<<A[i]<<" ";
	return 0;
}