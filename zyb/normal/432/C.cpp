#include<stdio.h>
#include<iostream>
using namespace std;
int f[100005],dd[500005],da[500005],a[100005],ff[100005];
    int i,j,k,l,s,m,n;
    bool bb;
inline void shaishu(int o)
{
    int p,nn;
    for (p=2;p<=o;p++)
    {
        if (f[p]==0)
        {
            f[p]=1;
            for (nn=2;nn*p<=o;nn++)
            f[nn*p]=2;
        }
    }
}
inline void change(int o,int p)
{
    int ll,kk;
    if (o==p)
    {
        bb=true;
    return ;
}
    if (o>p)
    swap(o,p);
    kk=p-o;
    for (;kk>=1;kk--)
    {
        if (f[kk+1]==1)
        {
            s++;
            dd[s]=p-kk;
            da[s]=p;
            swap(ff[a[p]],ff[a[p-kk]]);
            swap(a[p],a[p-kk]);
            change(o,p-kk);
            if (bb)
            return;
            s--;
            swap(a[p-kk],a[p]);
            swap(ff[a[p]],ff[a[p-kk]]);
        }
    }
}       
            
int main()
{

    scanf("%d",&n);
    shaishu(n);
    for (i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    ff[a[i]]=i;
    }
    s=0;
    for (i=1;i<=n;i++)
    {
        bb=false;
        if (a[i]!=i)
        change(ff[i],ff[a[i]]);
    }
    printf("%d\n",s);
    for(i=1;i<=s;i++)
    printf("%d %d\n",dd[i],da[i]);
}