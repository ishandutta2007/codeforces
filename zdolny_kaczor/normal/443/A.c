int seen[26];
int main() {
  int ans = 0;
  int c;
  while ((c = getchar()) != '\n') {
    if (c >= 'a' && c <= 'z' && !seen[c - 'a']) {
      ans++;
      seen[c - 'a'] = 1;
    }
  }
  printf("%d\n", ans);
}