#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  const string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
  const string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  const string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  int n; scanf("%d", &n);
  if (n <= 10) puts(ones[n].c_str());
  else if (n < 20) puts(teens[n-10].c_str());
  else if (n%10 == 0) printf("%s\n", tens[n/10-2].c_str());
  else printf("%s-%s\n", tens[n/10-2].c_str(), ones[n%10].c_str());

  return 0;
}