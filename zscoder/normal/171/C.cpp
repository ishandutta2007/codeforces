#include<cstdio>
using namespace std;
int main()
{
    int a,res=0,i=0;
    while (scanf("%d ",&a)==1)
    {
        res+=i*a;i++;
    }
    printf("%d\n",res);
    return 0;
}