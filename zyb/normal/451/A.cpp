#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int n,m;
scanf("%d%d",&n,&m);
n=min(n,m);
if (n%2)
printf("Akshat");
else
printf("Malvika");
}