# include <bits/stdc++.h>
using namespace std;
int read() {
  int a, b;
  scanf("%d%d",&a, &b);
  if (a != b) {
    printf("rated\n");
    exit(0);
  }
  return a;
}
int main() {
  bool found = false;
  int n;
  scanf("%d", &n);
  int l = read();
  for (int i = 1; i < n; ++i) {
    int x = read();
    if (x > l) {
      found = true;
    }
    l = x;
  }
  if (found)
    printf("unrated\n");
  else
    printf("maybe\n");
}