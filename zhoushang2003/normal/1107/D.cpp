#include<bits/stdc++.h>
using namespace std;
const int N=5200;
bool v[N][N],f;
int n,t,A=1;
string s[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n/4;j++)
		{
			if(s[i][j]>='A')
				s[i][j]-='A'-'0'-10;
			t=s[i][j]-'0';
			for(int k=0;k<4;k++)
				v[i][j*4+k]=1&t>>(3-k);
		}
	for(int p=2;p<=n;p++)
		while(n%p==0)
		{
			f=true;
			for(int j=0;j<n/p;j++)
				for(int k=0;k<n/p;k++)
					for(int l=0;l<p;l++)
						for(int m=0;m<p;m++)
							if(v[j*p+l][k*p+m]!=v[j*p][k*p])
								f=false;
			if(!f)
				break;
			A*=p;
			for(int j=0;j<n/p;j++)
				for(int k=0;k<n/p;k++)
					v[j][k]=v[j*p][k*p];
			n/=p;
		}
	cout<<A;
	return 0;
}