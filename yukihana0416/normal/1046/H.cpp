#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = (int) 2e5+20;

int n;
map<int, int> mp;
char str[1000005];
int cnt[26];

void work()
{
    scanf("%d", &n);
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        int m = strlen(str);
        memset(cnt, 0, sizeof(cnt));

        int sta = 0;
        for(int j = 0; j < m; j++)
        {
            int x = str[j] - 'a';
            sta ^= 1 << x;
        }
        ans += mp[sta];
        mp[sta]++;

        for(int j = 0; j < 26; j++)
        {
            sta ^= 1 << j;
            ans += mp[sta];
            sta ^= 1 << j;
        }
    }

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}