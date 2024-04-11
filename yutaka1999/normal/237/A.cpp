#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int ret=1,sum=0;
    int nh=-1,nm=-1;
    for(int i=0;i<n;i++)
    {
        int h,m;
        scanf("%d %d",&h,&m);
        if(h==nh&&m==nm) sum++;
        else
        {
            ret=max(ret,sum);
            sum=1;
            nh=h;nm=m;
        }
    }ret=max(ret,sum);
    printf("%d\n",ret);
    return 0;
}