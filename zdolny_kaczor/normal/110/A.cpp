# include <stdio.h>
char in[19];
int main() {
  scanf("%s", in);
  int c = 0;
  for (int i = 0; in[i]; ++i)
    if (in[i] == '4' || in[i] == '7')
      c++;
  if (c == 4 || c == 7)
    printf("YES\n");
  else
    printf("NO\n");
}