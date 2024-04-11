#include <stdio.h>
#include <string.h>

char s1[1000005], s2[1000005];
int tag1, tag2, i, l1, l2;

int main()
{
gets(s1), gets(s2);
l1 = strlen(s1), l2 = strlen(s2);
for(i = 0; i < l1; i++)
{
if (s1[i] == '4' && s2[i] == '7')
tag1++;
if (s1[i] == '7' && s2[i] == '4')
tag2++;
}
if (tag1 < tag2)
tag1 = tag2;
printf("%d", tag1);
return 0;
}