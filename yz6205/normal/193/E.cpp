#include <stdio.h>

#define MOD 10000000000000
#define LOG_N 50

long long imuladdmodq(long long bx, long long by, long long ax, long long ay, long long mod)
/* { */
/*     long long a_lb, a_hb; */
/*     __asm__ ("imulq   %3" : "=a"(a_lb), "=d"(a_hb) : "a"(ax), "X"(ay)); */
/*     long long b_lb, b_hb; */
/*     __asm__ ("imulq   %3" : "=a"(b_lb), "=d"(b_hb) : "a"(bx), "X"(by)); */
/*     __asm__ ("addq    %2, %0\n\t" */
/*              "adcq    %3, %1"  */
/*              : "+a"(b_lb), "+d"(b_hb)  */
/*              : "r"(a_lb), "r"(a_hb) ); */
/*     long long quotient, remain; */
/*     __asm__ ("idivq    %4" : "=a"(quotient), "=d"(remain) : "a"(b_lb), "d"(b_hb), "X"(mod)); */
/*     return remain; */
/* } */
{
  return (long long)(((__int128_t)(ax) * ay + (__int128_t)(bx) * by) % mod);
}

struct matrix_t
{
  long long a[2][2];
};

struct matrix_t mmulmod(struct matrix_t a, struct matrix_t b)
{
  struct matrix_t res;
  res.a[0][0] = imuladdmodq(a.a[0][0], b.a[0][0], a.a[0][1], b.a[1][0], MOD);
  res.a[0][1] = imuladdmodq(a.a[0][0], b.a[0][1], a.a[0][1], b.a[1][1], MOD);
  res.a[1][0] = imuladdmodq(a.a[1][0], b.a[0][0], a.a[1][1], b.a[1][0], MOD);
  res.a[1][1] = imuladdmodq(a.a[1][0], b.a[0][1], a.a[1][1], b.a[1][1], MOD);
  return res;
}

struct matrix_t mpow[LOG_N];
void init_mpow()
{
  mpow[0].a[0][0] = 1;
  mpow[0].a[0][1] = 1;
  mpow[0].a[1][0] = 1;
  for (int i = 0; i + 1 < LOG_N; i++)
    mpow[i + 1] = mmulmod(mpow[i], mpow[i]);
}
long long fib_nth(long long nth)
{
  struct matrix_t res;
  res.a[0][0] = res.a[1][1] = 1;
  res.a[0][1] = res.a[1][0] = 0;
  for (int i = 0; i < LOG_N; i++)
    if (nth & (1ll << i))
      res = mmulmod(res, mpow[i]);
  return res.a[1][0];
}

// i think the size should be enough
long long ans_pool[20 * 1000];
long long *ans[20];

int main()
{
  init_mpow();  

  long long n;
  scanf("%lld", &n);
  
  ans[0] = ans_pool;
  ans[1] = ans[0];
  for (int i = 0; i < 60; i++)
    if (fib_nth(i) % 10 == n % 10)
      *ans[1]++ = i;

  long long round = 60, mod = 100;
  for (int i = 1; i < 13; i++)
  {
    ans[i + 1] = ans[i];
    for (long long *j = ans[i - 1]; j < ans[i]; j++)
    {
      /* printf("round %d, value = %lld\n", i, *j); */
      for (long long k = 0; k < 10; k++)
        if (fib_nth(round * k + *j) % mod == n % mod)
          *ans[i + 1]++ = round * k + *j;
    }
    round *= 10; 
    mod *= 10;
  }

  long long res = __INT64_MAX__;
  for (long long *i = ans[12]; i < ans[13]; i++)
    if (*i < res) res = *i;

  if (res == __INT64_MAX__) puts("-1");
  else printf("%lld\n", res);

  return 0;
}