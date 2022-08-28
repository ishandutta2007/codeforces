#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&k,&m);
    
    bool up=false;
    for(int i=0;i<=m;i+=k)
    {
        if(i<=n) continue;
        else
        {
            if(!up)
            {
                up=true;
                printf("%d",i-n);
            }
            else
            {
                printf(" %d",i-n);
            }
        }
    }
    if(!up) printf("%d\n",-1);
    else printf("\n");
    
    return 0;
}