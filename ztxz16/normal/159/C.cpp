#include <stdio.h>
#include <stdlib.h>

int i,j,k,n,p,len,now;
char str[105],a[200005],hash[200005],key[27][200005],c;
int left[27][550000],right[27][550000],sum[27][550000];

void make(int x,int l,int r,int i);
int ask(int x,int l,int r,int k,int i);
void del(int x,int l,int r,int i);

int main()
{
    scanf("%d\n",&k);
    gets(str+1);
    for(i=1;str[i]!=0;i++);
    len=i-1;
    for(i=0;i<k;i++)
       for(j=1;j<=len;j++)
          a[i*len+j]=str[j]-96;
    len*=k;
    for(i=1;i<=len;i++)
       key[a[i]][i]=1;
    for(i=1;i<=26;i++)
       make(i,1,len,1);
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d %c",&p,&c);
       c-=96;
       now=ask(c,1,len,p,1);
       hash[now]=1;
       del(c,now,now,1);
    }
    for(i=1;i<=len;i++)
       if (hash[i]==0) printf("%c",a[i]+96);
    printf("\n");
    return 0;
}

void make(int x,int l,int r,int i)
{
     int mid=(l+r)>>1,lc,rc;
     left[x][i]=l,right[x][i]=r;
     if (l==r)
     {
        sum[x][i]=key[x][l];
        return;
     }
     lc=(i<<1),rc=(lc|1);
     make(x,l,mid,lc);
     make(x,mid+1,r,rc);
     sum[x][i]=sum[x][lc]+sum[x][rc];
     return;
}

int ask(int x,int l,int r,int k,int i)
{
    int lc,rc,mid=((l+r)>>1);
    if (l==r)
       return l;
    lc=(i<<1),rc=(lc|1);
    if (sum[x][lc]>=k) return ask(x,l,mid,k,lc);
    else return ask(x,mid+1,r,k-sum[x][lc],rc);
}

void del(int x,int l,int r,int i)
{
     if (l>right[x][i] || r<left[x][i]) return;
     if (l<=left[x][i] && r>=right[x][i])
     {
        sum[x][i]--;
        return;
     }
     sum[x][i]--;
     del(x,l,r,(i<<1));
     del(x,l,r,((i<<1)|1));
     return;
}