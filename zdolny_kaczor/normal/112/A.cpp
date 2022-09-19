# include <bits/stdc++.h>
using namespace std;
const int MN = 1010;
char a[MN], b[MN];
int main() {
  scanf("%s%s", a, b);
  for (int i = 0; a[i]; ++i)
    a[i] = tolower(a[i]);
  for (int i = 0; b[i]; ++i)
    b[i] = tolower(b[i]);
  printf("%d\n", strcmp(a, b));
}