#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  const int s = 1e6;
  const int MAXS = 1e6 + 123;

  int n; scanf("%d", &n);
  
  static int bio[MAXS]; memset(bio, 0, sizeof bio);
  REP(i, n) { int x; scanf("%d", &x); bio[x] = true; }

  vector<int> output;
  vector<int> praznih;
  int parova = 0;

  for (int i = 1; i <= s; ++i) {
    if (bio[i] && !bio[s-i+1]) output.push_back(s-i+1);
    if (bio[i] && bio[s-i+1] && i < s-i+1) {
      ++parova;
    }
    if (!bio[i] && !bio[s-i+1] && i < s-i+1) praznih.push_back(i);
  }

  assert((int)praznih.size() >= parova);
  REP(i, parova) {
    int top = praznih.back(); praznih.pop_back();
    output.push_back(top);
    output.push_back(s - top + 1);
  }

  int sz = output.size();
  sort(output.begin(), output.end());
  printf("%d\n", sz);
  REP(i, sz) printf("%d%c", output[i], i+1 == sz ? '\n' : ' ');

  return 0;
}