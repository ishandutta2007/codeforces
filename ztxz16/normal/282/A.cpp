#include <stdio.h>

int n,Ans,i;
char str[100];

int main()
{
scanf("%d\n", &n);
for(i = 1; i<=n;i++)
{
gets(str);
if (str[1] == '+')
Ans++;
else Ans--;
}
printf("%d\n",Ans);
return 0;
}