# include <bits/stdc++.h>
bool a[128];
char in[1000001];
int main() {
  scanf("%s", in);
  for (int i =0; in[i]; ++i)
    a[in[i]] = true;
  bool odd = true;
  for (int i = 0; i < 128; ++i)
    odd ^= a[i];
  if (odd)
    puts("CHAT WITH HER!");
  else puts("IGNORE HIM!");
}