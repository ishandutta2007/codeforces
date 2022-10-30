#include<bits/stdc++.h>
#define maxn 10000050
using namespace std;

bool noprime[maxn];
int p[maxn],pnum;

int mnp[maxn];

void predo()    {
    for (int i=2;i<maxn;++i)    {
        if (!noprime[i])    {
            p[pnum++]=i;
            mnp[i]=i;
        }

        for (int j=0;j<pnum&&i*p[j]<maxn;++j)   {
            noprime[i*p[j]]=1;
            if (i%p[j])
                mnp[i*p[j]]=p[j];
            else    {
                mnp[i*p[j]]=mnp[i]*p[j];
                break;
            }
        }
    }

}

int n,x[maxn],a[maxn],b[maxn];


int main()  {
    predo();
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  {
        scanf("%d",x+i);
        if (x[i]==mnp[x[i]])
            a[i]=b[i]=-1;
        else
            a[i]=mnp[x[i]],b[i]=x[i]/a[i];
    }
    for (int i=1;i<=n;++i) printf("%d%c",a[i]," \n"[i==n]);
    for (int i=1;i<=n;++i) printf("%d%c",b[i]," \n"[i==n]);
    return 0;
}