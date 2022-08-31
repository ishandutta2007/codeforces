#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        
        if(a>b)
        {
            int w=a;
            a=b;
            b=w;
        }
        if(c>b)
        {
            int w=c;
            c=b;
            b=w;
        }
        if(a<c)
        {
            int w=a;
            a=c;
            c=w;
        }
        if(a==1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}