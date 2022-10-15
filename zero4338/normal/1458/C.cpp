#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e3+5;
int n,m,a[maxn][maxn],ans[maxn][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=read()-1;
		static int ori[3],del[3];
		for(int i=0;i<3;i++)ori[i]=i,del[i]=0;
		string s;cin>>s;
		for(char &c:s)
			switch(c)
			{
				case 'R':del[1]++;break;
				case 'L':del[1]--;break;
				case 'D':del[0]++;break;
				case 'U':del[0]--;break;
				case 'I':swap(del[1],del[2]);swap(ori[1],ori[2]);break;
				case 'C':swap(del[0],del[2]);swap(ori[0],ori[2]);break;
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int nx,ny,nv;
				switch(ori[0])
				{
					case 0:nx=i+del[0];break;
					case 1:nx=j+del[0];break;
					case 2:nx=a[i][j]+del[0];break;
				}
				switch(ori[1])
				{
					case 0:ny=i+del[1];break;
					case 1:ny=j+del[1];break;
					case 2:ny=a[i][j]+del[1];break;
				}
				switch(ori[2])
				{
					case 0:nv=i+del[2];break;
					case 1:nv=j+del[2];break;
					case 2:nv=a[i][j]+del[2];break;
				}
				nx=(nx%n+n)%n;ny=(ny%n+n)%n;nv=(nv%n+n)%n;
				ans[nx][ny]=nv;
			}
		}
		for(int i=0;i<n;i++,putchar('\n'))
			for(int j=0;j<n;j++)printf("%d ",ans[i][j]+1);
		putchar('\n');
	}
	return 0;
}