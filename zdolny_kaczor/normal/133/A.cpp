# include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 44;
char in[MN];
int main() {
  scanf("%s", in);
  for (int i = 0; in[i]; ++i) {
    if (in[i] == 'H' || in[i] == 'Q' || in[i] == '9') {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}