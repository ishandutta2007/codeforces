# include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 44;
char in[MN];
int main() {
  scanf("%s", in);
  in[0] &=~32;
  printf("%s\n", in);
}