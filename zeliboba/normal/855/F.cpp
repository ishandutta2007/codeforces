#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

const int MAX = 1.1e9;
const int M = 300;
const int N = (100005 + M) / M * M;
ll SUM[N / M];
ll SUMPOS[N / M];
ll SUMNEG[N / M];
int POS[N / M];
int NEG[N / M];
int sum[N];
int pos[N];
int neg[N];
int spos[N];
int sneg[N];
ll sspos[N];
ll ssneg[N];
int sposall[N];
int snegall[N];
ll ssposall[N];
ll ssnegall[N];
int cntpos[N / M];
int cntneg[N / M];
int cnt[N / M];

void push(int x) {
  for (int i = x * M; i < (x + 1) * M; ++i) {
    pos[i] = min(pos[i], POS[x]);
    neg[i] = min(neg[i], NEG[x]);
    if (pos[i] < MAX && neg[i] < MAX) sum[i] = pos[i] + neg[i];
  }
}

void upd(int x, int y) {
  int ind = x / M;
  if (y > 0) {
    if (pos[x] < MAX) SUMPOS[ind] -= pos[x];
    pos[x] = min(pos[x], y);
    SUMPOS[ind] += pos[x];
  } else {
    if (neg[x] < MAX) SUMNEG[ind] -= neg[x];
    neg[x] = min(neg[x], -y);
    SUMNEG[ind] += neg[x];
  }
  SUM[ind] -= sum[x];
  if (pos[x] < MAX && neg[x] < MAX) sum[x] = pos[x] + neg[x];
  SUM[ind] += sum[x];
}

void build(int x) {
  int l = x * M, r = x * M + M;
  memcpy(sposall + l, pos + l, M * sizeof(pos[0]));
  memcpy(snegall + l, neg + l, M * sizeof(pos[0]));
  int it = 0;
  cntpos[x] = cntneg[x] = 0;
  for (int i = l; i < r; ++i) {
    if (pos[i] < MAX && neg[i] < MAX) {
      spos[l+it] = pos[i];
      sneg[l+it] = neg[i];
      ++it;
    }
    cntpos[x] += pos[i] < MAX;
    cntneg[x] += neg[i] < MAX;
  }
  cnt[x] = it;
  sort(spos + l, spos + l + cnt[x]);
  sort(sneg + l, sneg + l + cnt[x]);
  sort(sposall + l, sposall + r);
  sort(snegall + l, snegall + r);
  ssposall[l] = sposall[l];
  sspos[l] = spos[l];
  ssnegall[l] = snegall[l];
  ssneg[l] = sneg[l];
  for (int i = l + 1; i < l + cnt[x]; ++i) {
    sspos[i] = sspos[i-1] + spos[i];
    ssneg[i] = ssneg[i-1] + sneg[i];
  }
  for (int i = l + 1; i < r; ++i) {
    ssposall[i] = ssposall[i-1] + sposall[i];
    ssnegall[i] = ssnegall[i-1] + snegall[i];
  }
}

const int DEBUG = 0, S = 107, BAD = 41;
int stupidpos[N], stupidneg[N];

void calcs(int ind) {
  int l = ind * M, r = ind * M + M;
  if (POS[ind] < MAX && NEG[ind] < MAX) {
    int itpos = lower_bound(sposall + l, sposall + l + cntpos[ind], POS[ind]) - (sposall + l);
    int itneg = lower_bound(snegall + l, snegall + l + cntneg[ind], NEG[ind]) - (snegall + l);
    SUM[ind] = (M - itpos) * (ll)POS[ind] + (M - itneg) * (ll)NEG[ind] + (itpos ? ssposall[l+itpos-1] : 0) + (itneg ? ssnegall[l+itneg-1] : 0);
//    if (ind == 1) cerr << itpos << ' ' << itneg << ' ' << ssnegall[l] << endl;
    if (DEBUG && ind == BAD) cerr << "last1: " << (M - itpos) * (ll)POS[ind] << ' ' << (M - itneg) * (ll)NEG[ind] << ' ' << (itpos ? ssposall[l + itpos-1] : 0) << ' ' << (itneg ? ssnegall[l + itneg-1] : 0) << endl;
  } else if (POS[ind] < MAX) {
    int itpos = lower_bound(spos + l, spos + l + cnt[ind], POS[ind]) - (spos + l);
    assert(itpos <= cntneg[ind]);
    SUM[ind] = SUMNEG[ind] + (cntneg[ind] - itpos) * (ll)POS[ind] + (itpos ? sspos[l + itpos-1] : 0);
    if (DEBUG && ind == BAD) cerr << "last2: " << SUMNEG[ind] << ' ' << (cntneg[ind] - itpos) * (ll)POS[ind] << ' ' << (itpos ? ssposall[l + itpos-1] : 0) << endl;
  } else if (NEG[ind] < MAX) {
    int itneg = lower_bound(sneg + l, sneg + l + cnt[ind], NEG[ind]) - (sneg + l);
    assert(itneg <= cntpos[ind]);
    SUM[ind] = SUMPOS[ind] + (cntpos[ind] - itneg) * (ll)NEG[ind] + (itneg ? ssneg[l + itneg-1] : 0);
    if (DEBUG && ind == BAD) cerr << "last3: " << SUMPOS[ind] << ' ' << (cntpos[ind] - itneg) * (ll)NEG[ind] << ' ' << (itneg ? ssneg[l + itneg-1] : 0) << ' ' << cntpos[ind] << ' ' << itneg << ' ' << ssneg[l] << endl;
  }
}

void update(int ind, int y) {
  int val = abs(y);
  int l = ind * M, r = ind * M + M;
  if (y > 0) {
    if (val >= POS[ind]) return;
    POS[ind] = val;
    int itpos = lower_bound(sposall + l, sposall + l + cntpos[ind], POS[ind]) - (sposall + l);
    SUMPOS[ind] = (M - itpos) * (ll)POS[ind] + (itpos ? ssposall[l+itpos-1] : 0);
    calcs(ind);
  } else {
    if (val >= NEG[ind]) return;
    NEG[ind] = val;
    int itneg = lower_bound(snegall + l, snegall + l + cntneg[ind], NEG[ind]) - (snegall + l);
    SUMNEG[ind] = (M - itneg) * (ll)NEG[ind] + (itneg ? ssnegall[l+itneg-1] : 0);
    calcs(ind);
  }
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 10000;
  if (!DEBUG) scanf("%d", &T);
  for (int i = 0; i < N / M; ++i) POS[i] = NEG[i] = MAX;
  for (int i = 0; i < N; ++i) stupidpos[i] = stupidneg[i] = pos[i] = neg[i] = MAX;
  for (int i = 0; i < N / M; ++i) {
    build(i);
  }
  const int LIM = 2 * M;
  for (int q = 0; q < T; ++q) {
    int type, l, r;
    if (!DEBUG) scanf("%d%d%d", &type, &l, &r);
    else {
      type = rand() % 2 + 1;
      r = rand() % S + 1;
      l = rand() % r;
    }
    --l; --r;
    int L = l / M * M, R = r / M * M;
    if (DEBUG) cerr << "test: " << q << endl;
    if (type == 1) {
      int y;
      if (!DEBUG) scanf("%d", &y);
      else y = (rand() % 1000 + 1) * (rand() % 2 * 2 - 1);
      if (DEBUG) for (int i = l; i < r; ++i) {
        if (y > 0) stupidpos[i] = min(stupidpos[i], y);
        else stupidneg[i] = min(stupidneg[i], -y);
      }
      if (r - l < LIM) {
        for (int i = l / M; i <= (r-1) / M; ++i) push(i);
        for (int i = l; i < r; ++i) upd(i, y);
        for (int i = l / M; i <= (r-1) / M; ++i) build(i);
      } else {
        push(l / M);
        push(r / M);
        for (int i = l; i < L + M; ++i) upd(i, y);
        for (int i = R; i < r; ++i) upd(i, y);
        build(l / M);
        build(r / M);
        for (int i = L / M + 1; i < R / M; ++i) {
          update(i, y);
        }
      }
    } else {
      ll res = 0;
      //if (r - l < N) {
      if (r - l < LIM) {
        for (int i = l / M; i <= (r-1) / M; ++i) {
          push(i);
//          cerr << i << ' ' << POS[i] << ' ' << NEG[i] << ' ' << SUM[i] << endl;
        }
        for (int i = l; i < r; ++i) {
          res += sum[i];
//          cerr << i << ' ' << pos[i] << ' ' << neg[i] << ' ' << sum[i] << endl;
        }
      } else {
        push(l / M);
        push(r / M);
        for (int i = l; i < L + M; ++i) res += sum[i];
        for (int i = R; i < r; ++i) res += sum[i];
//        build(l / M);
//        build(r / M);
        for (int i = L / M + 1; i < R / M; ++i) {
          res += SUM[i];
          if (DEBUG) {
            cerr << "SUM: " << i << ' ' << SUMPOS[i] << ' ' << SUMNEG[i] << ' ' << SUM[i] << endl;
            for (int j = i * M; j < i * M + M; ++j) cerr << stupidpos[j] << ' ' << stupidneg[j] << ','; cerr << endl;
          }
        }
      }
//      for (int i = 0; i < 10; i += M) cerr << SUM[i / M] << ' ' << SUMPOS[i/M] << ' ' << SUMNEG[i/M]<< endl;
      printf("%lld\n", res);
      if (DEBUG) {
        ll stupid = 0;
        for (int i = l; i < r; ++i) if (max(stupidpos[i], stupidneg[i]) < MAX) stupid += stupidpos[i] + stupidneg[i];
        cerr << l << ' ' << r << ' ' << res << ' ' << stupid << endl;
        assert(res == stupid);
      }
    }
  }
  return 0;
}