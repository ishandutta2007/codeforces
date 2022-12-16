#include<cstdio>
#include<cstdlib>
#define N 1005
using namespace std;
long long f[N][N];double ans;char a[N][N];
int X[N],Y[N],flag[N][N],x[N],y[N],n,m,cnt,i,j,k,t,L,R,P;
const int dx[4]={0,0,1,-1};
const int dy[4]={-1,1,0,0};
int main()
{
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      f[1][1]+=(j-1)+(i-1);
  ans=f[1][1];
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      if (i==1&&j==1) continue;
      if (i!=1) f[i][j]=f[i-1][j]+(i-1)*m-(n-i+1)*m;
      else f[i][j]=f[i][j-1]+(j-1)*n-(m-j+1)*n;ans+=f[i][j];
    }
  for (i=1;i<=n;i++)
  {
    scanf("%s",a[i]+1);
    for (j=1;j<=m;j++) if (a[i][j]=='X') X[i]=j,Y[j]=i;
  }
  cnt=n*m;
  for (i=1;i<=n;i++)
    if (j=X[i])
    {
      for (k=1;k<=t;k++)
        f[i][j]-=abs(x[k]-i)+abs(y[k]-j);
      ans=ans-f[i][j]*2ll;
      ans=ans+(i-1)*(n-i)*4+(j-1)*(m-j)*4;
      t++;x[t]=i;y[t]=j;cnt--;
    }
  //row
  if (X[1]) L=X[1]-1,R=m-X[1],P=X[1];
  for (i=2;i<=n;i++)
  {
    if (X[i]==0) {L=R=0;P=0;continue;}
    if (P==0) {P=X[i];L=X[i]-1;R=m-X[i];continue;}
    if (X[i]>=P) ans+=L*(m-X[i])*2*2,L+=X[i]-1,R=(m-X[i]);
    else ans+=R*(X[i]-1)*2*2,R+=(m-X[i]),L=X[i]-1;P=X[i];
  }
  //column
  if (Y[1]) L=Y[1]-1,R=n-Y[1],P=Y[1];else L=R=P=0;
  for (j=2;j<=m;j++)
  {
    if (Y[j]==0) {L=R=0;P=0;continue;}
    if (P==0) {P=Y[j];L=Y[j]-1;R=n-Y[j];continue;}
    if (Y[j]>=P) ans+=L*(n-Y[j])*2*2,L+=Y[j]-1,R=n-Y[j];
    else ans+=R*(Y[j]-1)*2*2,R+=n-Y[j],L=Y[j]-1;P=Y[j];
  }
  printf("%.6lf",ans*1./cnt/cnt);
}