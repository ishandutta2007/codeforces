#include<cstdio>
#include<cstring>
using namespace std;
const int size=19;
bool flag[10];
long long dight[size],f[1<<size][101],i,j,p,m,k,n,t;
int main()
{
  //freopen("numbers.in","r",stdin);
  //freopen("numbers.out","w",stdout);
  scanf("%I64d%I64d",&p,&m);
  while (p)
  {
    dight[++n]=p%10;
    p/=10;
  }
  for (i=1;i<=n/2;i++) t=dight[i],dight[i]=dight[n-i+1],dight[n-i+1]=t;
  f[0][0]=1;
  for (i=0;i<(1<<n)-1;i++)
    for (j=0;j<m;j++)
    {
      memset(flag,0,sizeof(flag));
      if (f[i][j]==0) continue;
      for (k=1;k<=n;k++)
        if (!flag[dight[k]])
        {
          if (i&(1<<(k-1))) continue;
          if (i==0&&dight[k]==0) continue;
          flag[dight[k]]=true;
          f[i+(1<<(k-1))][(j*10+dight[k])%m]+=f[i][j];
        }
    }
  printf("%I64d",f[(1<<n)-1][0]);
  scanf("%I64d%I64d",&p,&m);
  return 0;
}