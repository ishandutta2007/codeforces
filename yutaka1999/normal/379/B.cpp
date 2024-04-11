#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=0;j<a;j++)
        {
            if(j==0) printf("P");
            else
            {
                if(i!=n-1) printf("RLP");
                else printf("LRP");
            }
        }
        if(i!=n-1) printf("R");
    }
    puts("");
    return 0;
}