#include<bits/stdc++.h>
using namespace std;
const int N=3001;
int n,m,k,A[N],c;
string S[N];
int main()
{
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m)
	{
		cout<<"NO"<<'\n';
		return 0;
	}
	cout<<"YES"<<'\n';
	if(k<n)
	{
		cout<<1<<'\n'<<k<<' '<<'D';
		return 0;
	}
	if(n>1)
		A[++c]=n-1,S[c]="D",k-=n-1;
	while(true)
	{
		if(k<=2*(m-1))
		{
			for(int i=1;i<m;i++)
				if(k)
					A[++c]=1,S[c]="R",k--;
			for(int i=1;i<m;i++)
				if(k)
					A[++c]=1,S[c]="L",k--;
			break;
		}
		if(k<=3*(m-1))
		{
			while(k)
			{
				if(k)
					A[++c]=1,S[c]="R",k--;
				if(k)
					A[++c]=1,S[c]="U",k--;
				if(k)
					A[++c]=1,S[c]="D",k--;
			}
			break;
		}
		if(m>1)
			A[++c]=m-1,S[c]="RUD",k-=3*(m-1);
		if(k<=m-1)
		{
			A[++c]=k,S[c]="L";
			break;
		}
		if(m>1)
			A[++c]=m-1,S[c]="L";
		A[++c]=1,S[c]="U",k-=m;
	}
	cout<<c<<'\n';
	for(int i=1;i<=c;i++)
		cout<<A[i]<<' '<<S[i]<<'\n';
	return 0;
}