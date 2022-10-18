#include<bits/stdc++.h>
using namespace std;
const int N=101,I=1e9;
int n,x,a[N],s,A;
int main()
{
	cin>>n;
	while(n--&&cin>>x)
		a[x]++,s+=x;
	for(int i=1;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(min(a[i],a[j]))
			{
				x=I;
				for(int k=1;k<=j;k++)
					if(j%k==0)
						x=min(x,j/k+i*k);
				A=max(A,i+j-x);
			}
	cout<<s-A;
	return 0;
}