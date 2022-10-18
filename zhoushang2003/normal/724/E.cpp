#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
long long n,c,a[N],b,p,A;
priority_queue<long long>q;
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>a[i],p+=a[i];
	for(int i=1;i<=n;i++)
		cin>>b,q.push(a[i]-b-(n-i)*c);
	A=p;
	for(int i=0;i<n;i++)
		p-=q.top()+i*c,q.pop(),A=min(A,p);
	cout<<A;
	return 0;
}