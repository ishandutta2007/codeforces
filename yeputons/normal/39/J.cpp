#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
  #ifdef DEBUG
  freopen("stdin", "r", stdin);
  freopen("stdout", "w", stdout);
  #endif

  char s01[1000002];
  char s02[1000002];
  scanf("%s", &s01);
  scanf("%s", &s02);

  long long te = clock();
  int n = strlen(s02);
  int l = n - 1;
  for (int i = 0; i < n; i++) {
    if (s01[i] != s02[i]) {
      l = i - 1;
      break;
    }
  }
  int r = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s01[i + 1] != s02[i]) {
      r = i + 1;
      break;
    }
  }
  int ans = l + 2 - r;
  if (ans <= 0) {
    printf("0\n");
    return 0;
  }
  printf("%d\n", ans);
  for (int i = r; i <= l + 1; i++) {
    printf("%d%c", i + 1, i == l + 1 ? '\n' : ' ');
  }
  //printf("%.9lf\n", ((clock() - te) + 0.0) / CLOCKS_PER_SEC);
  //printf("%d\n", n);

  return 0;
}