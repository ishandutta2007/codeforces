#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll a, b;
  while (scanf("%I64d%I64d", &a, &b) >= 1) {
    ll d = a * b / gcd(a, b);
    ll cnt1 = (d - 1) / a;
    ll cnt2 = (d - 1) / b;
    if (a > b) cnt1++;
    else cnt2++;

    if (cnt1 > cnt2) printf("Dasha\n");
    else if (cnt1 < cnt2) printf("Masha\n");
    else printf("Equal\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}