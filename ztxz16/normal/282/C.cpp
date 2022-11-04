
#include <stdio.h>
#include <string.h>

char s1[1000005], s2[1000005];
int tag1, tag2, i, l1, l2;

int main()
{
gets(s1);
gets(s2);
l1 = strlen(s1);
l2 = strlen(s2);
if (l1 != l2)
printf("NO\n");
else if (l1 == 1)
{
if (s1[0] == s2[0])
printf("YES\n");
else printf("NO\n");
}
else
{
for(i = 0; i < l1; i++)
{
if (s1[i] == '1')
tag1 = 1;
if (s2[i] == '1')
tag2 = 1;
}
if (tag1 + tag2 == 1)
printf("NO\n");
else printf("YES\n");
}
}