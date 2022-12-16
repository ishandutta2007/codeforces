#include<stdio.h>
#include<algorithm>
using namespace std;
long long s,s1,a[200005],n,i,ans,gt;
int main()
{
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    scanf("%I64d",&a[i]);
    long long last=0,last1=0;
    s=s1=0;
    for (i=1;i<=n;i++)
    {
        if (!last&&!last1)
        {
            if (a[i]!=-1)
            {
               last=a[i];
               ans++;
            }
            else
            s1++;
        }
        else
            if (!last1&&last)
            {
                if (a[i]!=-1)
                {
                    bool bbb=true;
                    if (s)
                    {
                        long long uu=abs(a[i]-last);
                        if (uu%(s+1))
                        bbb=false;
                    }
                   if (a[i]>last&&s1&&bbb)
                   {
                       long long yy=(a[i]-last)/(s+1);
                       long long xx=last-1;
                       if (xx/yy<s1)
                       bbb=false;
                   }
                   if (bbb==true)
                   {
                      gt=(a[i]-last)/(s+1);
                      last1=last;
                      last=a[i];
                      s1=0;
                      s=0;
                   }
                   else
                   {
                       last1=0;
                       last=a[i];
                       s1=s=0;
                       gt=0;
                       ans++;
                   }
                   }
                   else
                   s++;
               }
            else
            {
                if (a[i]==-1)
                a[i]=last+gt;
                if (a[i]>0&&a[i]-last==gt)
                {
                    last1=last;
                    last=a[i];
                }
                else
                {
                    if (a[i]<=0)
                    {
                       last=last1=0;
                       s1=1;
                       gt=0;
                       s=0;
                   }
                   else
                   {
                       last1=0;
                       s=s1=gt=0;
                       last=a[i];
                       ans++;
                   }
                }
            }
        }
        ans=ans+(s1>0&&last==0&&last1==0);
        printf("%I64d",ans);
    }