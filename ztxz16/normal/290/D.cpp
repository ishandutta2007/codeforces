#include <stdio.h>
#include <string.h>

char s1[1000005], s2[1000005];
int tag1, tag2, i, l1, l2;

int main()
{
gets(s1), scanf("%d", &tag1);
l1 = strlen(s1);
for(i = 0; i < l1; i++)
{
if (s1[i] >= 'a' && s1[i] < 'a' + tag1)
s1[i] -= 32;
if (s1[i] >= 'A' + tag1 && s1[i] <= 'Z') s1[i] += 32;
}
puts(s1);
return 0;
}