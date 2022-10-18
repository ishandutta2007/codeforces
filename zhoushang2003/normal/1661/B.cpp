#import<bits/stdc++.h>
using namespace std;
const int N=32768;
int f[N],n,x;
main()
{
	cin>>n,memset(f,0x3f,sizeof(f)),f[0]=0;
	for(int i=0;i<99;i++)
		for(int j=0;j<N;j++)
		{
			f[(j-1+N)%N]=min(f[(j-1+N)%N],f[j]+1);
			if(j%2==0)
				f[j/2]=min(f[j/2],f[j]+1),f[(j+N)/2]=min(f[(j+N)/2],f[j]+1);
		}
	while(n--&&cin>>x)
		cout<<f[x]<<' ';
}