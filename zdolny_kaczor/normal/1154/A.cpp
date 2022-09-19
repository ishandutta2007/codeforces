#include <bits/stdc++.h>
using namespace std;
int in[4];
int main() {
  for (int i = 0; i < 4; ++i)
    scanf("%d", in + i);
  sort(in, in + 4);
  for (int i = 0; i < 3; ++i)
    printf("%d ", in[3] - in[i]);
}