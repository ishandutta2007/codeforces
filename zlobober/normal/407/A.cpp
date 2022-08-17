#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mysqrt(int x)
{
    int t = 0;
    while ((t + 1) * (t + 1) <= x)
        ++t;
    if (t * t == x)
        return t;
    else
        return -1;
}

vector<pair<int, int> > go(int x)
{
    x = x * x;
    vector<pair<int, int> > ans;
    for (int i = 0; i * i <= x; i++)
    {
        int p = i;
        int q = mysqrt(x - i * i);
        if (q == -1)
            continue;
        if (p != 0 && q != 0)
        {
            ans.push_back(make_pair(p, q));
            ans.push_back(make_pair(p, -q));
            ans.push_back(make_pair(-p, q));
            ans.push_back(make_pair(-p, -q));
        }
    }
    return ans;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    vector<pair<int, int> > A = go(a), B = go(b);
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
        {
            int x1 = A[i].first, y1 = A[i].second;
            int x2 = B[j].first, y2 = B[j].second;
            if (x1 * x2 + y1 * y2 == 0 && (x1 != x2 && y1 != y2))
            {
                printf("YES\n");
                printf("0 0\n");
                printf("%d %d\n", x1, y1);
                printf("%d %d\n", x2, y2);
                return 0;
            }
        }
    printf("NO\n");
}