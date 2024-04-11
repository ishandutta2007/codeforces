#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll f[12][2][2];//iii+1 
int a[104],tt;
int main(){
	int T=read();
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		int n=read();tt=0;
		while(n)a[++tt]=n%10,n/=10;
		f[1][0][0]=1;
		for(int i=1;i<=tt+1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				for(int k=0;k<=1;k++)
				{
					if(!f[i][j][k])continue;
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
					if(i==tt+1)continue;
					int o=a[i];
					o-=j;
					if(o<0)//0-1 
					{
						f[i+1][k][1]+=f[i][j][k]*10;//9 ()
					}
					else 
					{
						f[i+1][k][0]+=f[i][j][k]*(o+1);
						if(o!=9)
						{
							o+=10,o-=9;
							o=(9-o+1);
							f[i+1][k][1]+=f[i][j][k]*(o);
						}
					}
				}
			}
		}
		cout<<f[tt+1][0][0]-2<<"\n";
	}
	return 0;
}