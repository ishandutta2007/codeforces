#include <stdio.h>
#include <stdlib.h>
#define ll long long 

ll n,i,c1,c2,ans,oo,c_now,tag[100005],num[100005],sum[100005];
ll f1[100005],f2[100005],s[100005],c[100005],c_temp[100005];
ll s1[100005],s2[100005],num_now[100005],s_now[100005];
ll Ans1[100005],Ans2[100005];
char hash[100005];

void work(ll num);
void sort(ll l,ll r);
void qs(ll l,ll r);
void print(ll c1,ll c2);

int main()
{
    oo=1;
    for(i=1;i<=60;i++)
       oo+=oo;
    s_now[0]=0-oo;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
       scanf("%I64d %I64d",&c[i],&s[i]),tag[i]=i;
    qs(1,n);
    c[0]=c[1]-1;
    for(i=1;i<=n;i++)
    {
       if (c[i]!=c[i-1]) c_now++;
       c_temp[i]=c_now;
    }
    for(i=1;i<=n;i++)
       c[i]=c_temp[i];
    for(i=1;i<=n;i++)
       num[c[i]]++,sum[c[i]]+=s[i];
    sort(1,n);
    ans=0-oo;
    for(i=1;i<=n;i++)
    {
       if (num[i]==0) continue;
       work(num[i]);
       if (f1[num[i]]!=i)
       {
          if (s1[num[i]]+sum[i]>ans)
          {
             ans=s1[num[i]]+sum[i];
             c1=f1[num[i]];
             c2=i;
          }
       }
       else
       {
           if (f2[num[i]]!=0)
           {
              if (s2[num[i]]+sum[i]>ans)
              {
                 ans=s2[num[i]]+sum[i];
                 c1=f2[num[i]];
                 c2=i;
              }
           }
       }
       work(num[i]+1);
       if (f1[num[i]+1]!=i)
       {
          if (s1[num[i]+1]+sum[i]>ans)
          {
             ans=s1[num[i]+1]+sum[i];
             c1=f1[num[i]+1];
             c2=i;
          }
       }
       else
       {
           if (f2[num[i]+1]!=0)
           {
              if (s2[num[i]+1]+sum[i]>ans)
              {
                 ans=s2[num[i]+1]+sum[i];
                 c1=f2[num[i]+1];
                 c2=i;
              }
           }
       }
    }
    printf("%I64d\n",ans);
    if (num[c1]>=num[c2]) print(c1,c2);
    else print(c2,c1);
    return 0;
}

void sort(ll l,ll r)
{
     ll i=l,j=r,k,mid;
     mid=s[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && s[i]>mid) i++;
           while (i<=j && s[j]<mid) j--;
           if (i<=j)
           {
              k=s[i],s[i]=s[j],s[j]=k;
              k=c[i],c[i]=c[j],c[j]=k;
              k=tag[i],tag[i]=tag[j],tag[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}

void qs(ll l,ll r)
{
     ll i=l,j=r,k,mid;
     mid=c[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && c[i]>mid) i++;
           while (i<=j && c[j]<mid) j--;
           if (i<=j)
           {
              k=s[i],s[i]=s[j],s[j]=k;
              k=c[i],c[i]=c[j],c[j]=k;
              k=tag[i],tag[i]=tag[j],tag[j]=k;
              i++,j--;
           }
     }
     if (l<j) qs(l,j);
     if (i<r) qs(i,r);
     return;
}

void work(ll num)
{
     ll i,temp;
     if (hash[num]==1) return;
     hash[num]=1;
     for(i=1;i<=n;i++)
        num_now[i]=s_now[i]=0;
     for(i=1;i<=n;i++)
     {
        if (num_now[c[i]]==num) continue;
        num_now[c[i]]++;
        s_now[c[i]]+=s[i];
     }
     f1[num]=f2[num]=0;
     for(i=1;i<=n;i++)
     {
        if (num_now[i]!=num) continue;
        if (s_now[i]>s_now[f2[num]]) 
        {
           f2[num]=i;
           if (s_now[f2[num]]>s_now[f1[num]])
              temp=f1[num],f1[num]=f2[num],f2[num]=temp;
        }
     }
     s1[num]=s_now[f1[num]];
     s2[num]=s_now[f2[num]];
     return;
}

void print(ll c1,ll c2)
{
     ll i;
     Ans1[0]=Ans2[0]=0;
     for(i=1;i<=n;i++)
     {
        if (c[i]==c1) Ans1[++Ans1[0]]=tag[i];
        if (c[i]==c2) Ans2[++Ans2[0]]=tag[i];
     }
     if (Ans1[0]==Ans2[0])
     {
        printf("%I64d\n",Ans1[0]+Ans2[0]);
        for(i=1;i<=Ans1[0];i++)
           printf("%I64d %I64d ",Ans1[i],Ans2[i]);
        printf("\n");
     }
     else
     {
         printf("%I64d\n",Ans2[0]+Ans2[0]+1);
         for(i=1;i<=Ans2[0];i++)
            printf("%I64d %I64d ",Ans1[i],Ans2[i]);
         printf("%I64d\n",Ans1[Ans2[0]+1]);
     }
     return;
}