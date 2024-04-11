#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A[]={0,13439,106064,189279,106064,330095,388944,106064,106064,189279,560720,486464,388944,263744,106064,670095,106064};
int n,m,x;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if((i+j)&1)
				cout<<720720<<' ';
			else
				cout<<A[x]<<' ';
		}
	return 0;
}