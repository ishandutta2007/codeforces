#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int ret=0;
    int a,b;
    scanf("%d %d",&a,&b);
    int zan=0;
    while(a>0)
    {
        ret+=a;
        zan+=a;
        a=zan/b;
        zan%=b;
    }
    printf("%d\n",ret);
    return 0;
}