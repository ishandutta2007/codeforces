#include <stdio.h>
#include <stdlib.h>

int n,i,j,tot,min,s,k,a[1005],t[1005],tag[1005];
int ans[1005][1005];
double Ans;

void sort(int l,int r);

int main()
{
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
       scanf("%d %d",&a[i],&t[i]);
       Ans+=(double)(a[i]);
       tag[i]=i;
       if (t[i]==1) s++;
    }  
    sort(1,n);
    if (s<k)
    {
       tot=0;
       for(i=1;i<=n;i++)
          if (t[i]==1) tot++,ans[tot][++ans[tot][0]]=i;
       for(i=1;i<=n;i++)
       {
          if (t[i]==1) continue;
          if (ans[k][0]==n-k+1) tot++,ans[tot][++ans[tot][0]]=i;
          else ans[k][++ans[k][0]]=i;
       }
       for(i=1;i<=s;i++)
          Ans-=((double)(a[ans[i][1]])*0.5);
    }
    else
    {
        tot=k;
        for(i=n;i>=1;i--)
        {
           if (t[i]==2) continue;
           ans[tot][++ans[tot][0]]=i;
           if (tot>1) Ans-=((double)(a[i])*0.5),tot--;
        }
        for(i=1;i<=n;i++)
           if (t[i]==2) ans[1][++ans[1][0]]=i;
        min=a[ans[1][1]];
        for(i=1;i<=ans[1][0];i++)
           if (a[ans[1][i]]<min) min=a[ans[1][i]];
        Ans-=((double)(min)*0.5);
    }
    printf("%.1lf\n",Ans);
    for(i=1;i<=k;i++)
    {
       printf("%d",ans[i][0]);
       for(j=1;j<=ans[i][0];j++)
          printf(" %d",tag[ans[i][j]]);
       printf("\n");
    }
    return 0;
}

void sort(int l,int r)
{
     int i=l,j=r,k,mid;
     mid=a[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && a[i]<mid) i++;
           while (i<=j && a[j]>mid) j--;
           if (i<=j)
           {
              k=a[i],a[i]=a[j],a[j]=k;
              k=t[i],t[i]=t[j],t[j]=k;
              k=tag[i],tag[i]=tag[j],tag[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}