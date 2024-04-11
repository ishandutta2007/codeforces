#include<bits/stdc++.h>
using namespace std;
const int D=1e9+7;
int T,x,y,X,Y,K,f[32][2][2][2],g[32][2][2][2];
int S(int x,int y)
{
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g)); 
	for(int i=0;i<32;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					if(!i)
						f[i][j][k][l]=!j&&!k&&!l;
					else
						for(int X=0;X<2;X++)
							for(int Y=0;Y<2;Y++)
							{
								if(j&&X>(x>>i-1&1)||k&&Y>(y>>i-1&1)||(l&&(X^Y)>(K>>i-1&1)))
									continue;
								int U=j&&X==(x>>i-1&1),V=k&&Y==(y>>i-1&1),W=l&&(X^Y)==(K>>i-1&1);
								(f[i][j][k][l]+=f[i-1][U][V][W])%=D,(g[i][j][k][l]+=g[i-1][U][V][W])%=D;
								if(X^Y)
									(g[i][j][k][l]+=(1ll<<i-1)*f[i-1][U][V][W]%D)%=D;
							}
	return (f[31][1][1][1]+g[31][1][1][1])%D;
}
int main()
{
	cin>>T;
	while(T--&&cin>>x>>y>>X>>Y>>K)
		cout<<((S(X,Y)-S(x-1,Y)-S(X,y-1)+S(x-1,y-1))%D+D)%D<<'\n';
	return 0;
}