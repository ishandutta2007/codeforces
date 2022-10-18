#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,a[N],p[N],C,M; 
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		C+=a[i],p[i%k]+=a[i];
	for(int i=0;i<k;i++)
		M=max(M,abs(C-p[i]));
	cout<<M;
	return 0;
}