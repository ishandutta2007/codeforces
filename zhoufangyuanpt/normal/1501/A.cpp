#include<cstdio>
#include<cstring>
using namespace std;
int a[110],b[110],tm[110];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int ss=0;
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=n;i++)scanf("%d",&tm[i]);
        b[0]=0;
        for(int i=1;i<=n;i++)
        {
            int out;
            if(i==1)out=0;
            else
            {
                if(ss+(b[i-1]-a[i-1]+1)/2<b[i-1])out=b[i-1];
                else out=ss+(b[i-1]-a[i-1]+1)/2;
            }
            ss=out+a[i]-b[i-1]+tm[i];
        }
        printf("%d\n",ss);
    }
    return 0;
}