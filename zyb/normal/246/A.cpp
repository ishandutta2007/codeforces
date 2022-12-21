#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if (n<=2)
    puts("-1");
    else
    for (int i=n;i;i--)
    printf("%d ",i);
}