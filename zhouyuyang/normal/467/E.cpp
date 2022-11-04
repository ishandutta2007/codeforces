#include<cstdio>
#include<stack>
#include<map>
#define N 500005
using namespace std;
map<int,int>sum,belong;
int a[N],n,k,i,wri[N],t,ans;
int main()
{
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  k=1;
  while (k<=n)
  {
    map<int,int>belong,sum;stack<int>Q;
    for (i=k;i<=n;i++)
    {
      if (t=belong[a[i]]) {wri[++ans]=t;wri[++ans]=a[i];break;}
      while (Q.size()&&sum[a[i]]+(Q.top()!=a[i])>1)
        sum[Q.top()]--,belong[Q.top()]=a[i],Q.pop();
      Q.push(a[i]);sum[a[i]]++;
    }
    k=i+1;
  }
  printf("%d\n",ans*2);
  for (i=1;i<=ans/2;i++)
    printf("%d %d %d %d ",wri[i*2-1],wri[i*2],wri[i*2-1],wri[i*2]);
}