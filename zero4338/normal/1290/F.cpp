#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int mod=998244353;
int n,m;
int x[10],y[10];
int val[30][30][30][30][30][2][2];
int dfs(int pos,int px,int nx,int py,int ny,bool cx,bool cy)
{
	if(pos==30)return !px&&!nx&&!py&&!ny&&!cx&&!cy;
	int &ret=val[pos][px][nx][py][ny][cx][cy];
	if(~ret)return ret;
	int now=(m>>pos)&1;
	ret=0;
	for(int i=0;i<(1<<n);i++)
	{
		int npx=px,nnx=nx,npy=py,nny=ny;
		for(int j=0;j<n;j++)
			if((i>>j)&1)
			{
				if(x[j]<0)nnx-=x[j];else npx+=x[j];
				if(y[j]<0)nny-=y[j];else npy+=y[j];
			}
		if((npx&1)==(nnx&1)&&(npy&1)==(nny&1))
		{
			bool ncx,ncy;
			if((npx&1)^now)ncx=(now<(npx&1))?1:0;
			else ncx=cx;
			if((npy&1)^now)ncy=(now<(npy&1))?1:0;
			else ncy=cy;
			(ret+=dfs(pos+1,npx>>1,nnx>>1,npy>>1,nny>>1,ncx,ncy))%=mod;
		}
	}
	return ret;
}
int main()
{
	n=read();m=read();
	for(int i=0;i<n;i++)x[i]=read(),y[i]=read();
	memset(val,-1,sizeof val);
	printf("%d\n",(dfs(0,0,0,0,0,0,0)-1+mod)%mod);
	return 0;
}