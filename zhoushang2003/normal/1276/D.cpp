#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5,D=998244353;
int n,x,y,f[N][4];
vector<int>e[N];
void S(int x,int z)
{
	int v=0,b,c,d;
	f[x][1]=f[x][3]=1;
	for(int y:e[x])
		if(y!=z)
		{
			S(y,x),b=f[y][0]+f[y][2]+f[y][3],c=f[y][2]+f[y][3],d=f[y][0]+f[y][1],(f[x][0]*=b)%=D,(f[x][2]*=b)%=D;
			if(!v)
				(f[x][0]+=f[x][3]*c)%=D,(f[x][1]*=d)%=D;
			else
				(f[x][2]+=f[x][3]*c)%=D,(f[x][1]*=b)%=D;
			(f[x][3]*=d)%=D;
		}
		else
			v=1;
}
main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	S(1,0);
	cout<<(f[1][0]+f[1][3])%D;
}