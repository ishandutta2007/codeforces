#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int in[101];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    
    int ans=in[0];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int a=0;
            for(int k=i;k<=j;k++)
            {
                a^=in[k];
            }
            if(ans<a) ans=a;
        }
    }
    printf("%d\n",ans);
    return 0;
}