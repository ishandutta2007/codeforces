#include<cstring>
#include<stdio.h>
using namespace std;
int a[100005];
int main()
{
char c;
int s=0;
c=getchar();
c=getchar();
while (c!='}')
{
    if (c!=','&&c!=' ')
{   
if (!a[int(c)])
{
s++;
a[int(c)]=1;
}
}
c=getchar();
}
printf("%d",s);
}