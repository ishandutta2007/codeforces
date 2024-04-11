#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;

const int A = 128;
int cou[A];
const int MN = 1e6 + 44;
char in[MN];
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", in);
    REP(i, n)
        cou[in[i]]++;
    int odd = 0;
    REP(i, A)
        if (cou[i] % 2)
            odd++;
    if (odd == 0) {
        printf("1\n");
        string left;
        REP(i, A)
            REP(_, cou[i] / 2)
                left.push_back(i);
        printf("%s", left.begin());
        reverse(ALL(left));
        printf("%s", left.begin());
        return 0;
    }
    int len = 1;
    for (int i = 1; i <= n; i += 2) {
        if (n % i == 0 && n / i >= odd)
           len = i;
           }
   vector <char> odds;
   REP(i, A) if (cou[i] % 2) {odds.PB(i); cou[i]--;}
   REP(i, A)
    while (cou[i] && odds.size() < n / len) {
        odds.PB(i);
        odds.PB(i);
        cou[i]-=2;
    }
    printf("%d\n", n / len);
   REP(_, n / len) {
       int half = len / 2;
       string left;
       REP(i, A) {
         while (left.size() < half && cou[i]) {
            cou[i] -= 2;
            left.push_back(i);
            }
       }
       printf("%s", left.begin());
       printf("%c", odds[_]);
       reverse(left.begin(), left.end());
       printf("%s ", left.begin());
   }
   printf("\n");
}