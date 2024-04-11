#include<cstdio>
#include<cstring>
using namespace std;
int f[510][510],g[510][510],z[510][510],a[510],b[510];
int ans[510];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
    for(int j=1;j<=m;j++)
    {
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[j])f[i][j]=f[k][j-1]+1,g[i][j]=k,z[i][j]=j;
            else f[i][j]=f[i][j-1],g[i][j]=g[i][j-1],z[i][j]=z[i][j-1];
            if(a[i]<b[j]&&f[i][j-1]>f[k][j-1])k=i;
        }
    }
	int ss=0,p=0;
	for(int i=1;i<=n;i++)if(ss<f[i][m])ss=f[i][m],p=i;
    printf("%d\n",ss);
	int s=ss;
	while(p!=0)
	{
		ans[s--]=a[p];
		int pp=g[p][m];
		m=z[p][m]-1;
		p=pp;
	}
	for(int i=1;i<ss;i++)printf("%d ",ans[i]);
	if(ss!=0)printf("%d\n",ans[ss]);
    return 0;
}