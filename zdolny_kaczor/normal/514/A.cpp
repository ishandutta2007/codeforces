# include <cstdio>
char num[21];
int main()
{
  scanf("%s", num);
  for (int i=0; num[i]; ++i)
  {
    if (num[i]>='5' && (i || num[i]!='9'))
      num[i]='9'+'0'-num[i];
  }
  printf("%s\n", num);
}