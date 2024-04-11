# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 2e3 + 44;
pair <int, int> in[MN];
int ans[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        in[i] = make_pair(-x, i);
    }
    sort(in, in + n);
    int before = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i && in[i].first != in[i - 1].first)
            before = i;
        ans[in[i].second] = before + 1;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
}