#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 105;
int A[N];
bool used[N];
int cnt[N];



int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), cnt[A[i]]++;
    vector<int> groups;
    for (int i = 0; i < N; i++)
    {
        int r = cnt[i];
        if (!r)
            continue;
        sort(groups.rbegin(), groups.rend());
        for (int j = 0; j < groups.size(); j++)
        {
            int d = min(r, i - groups[j] + 1);
            groups[j] += d;
            r -= d;
            if (r == 0)
                break;
        }
        if (r)
        {
            while (r)
            {
                int d = min(r, i + 1);
                groups.push_back(d);
                r -= d;
            }
        }
    }
    printf("%d\n", (int)groups.size());
}