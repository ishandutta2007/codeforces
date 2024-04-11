#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000500;
vector<int> S[N];

int A[N];
vector<int> all;

int tmp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        S[A[i]].push_back(i);
        all.push_back(A[i]);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int ans = 0;
    for (int i = 0; i < all.size(); i++)
        ans = max(ans, (int)S[all[i]].size());
    for (int i = 0; i < all.size(); i++)
    {
        int a = all[i];
        for (int j = 0; j < i; j++)
        {
            int b = all[j];
            int pta = 0, ptb = 0;
            int pt = 0;
            while (pta != S[a].size() && ptb != S[b].size())
            {
                if (S[a][pta] < S[b][ptb])
                    tmp[pt++] = 0, pta++;
                else
                    tmp[pt++] = 1, ptb++;
            }
            for (; pta != S[a].size(); )
                tmp[pt++] = 0, pta++;
            for (; ptb != S[b].size(); )
                tmp[pt++] = 1, ptb++;
            int ds = 0;
            for (int p = 0; p < pt - 1; p++)
                ds += tmp[p] != tmp[p + 1];
            ans = max(ans, ds + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}