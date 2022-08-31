#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 400500;

map<int, vector<int> > bad;

void relax(vector<pair<int, int> >& S, const vector<int>& B)
{
    vector<pair<int, int> > res;
    for (int i = 0; i < S.size(); )
    {
        S[i].second = *upper_bound(B.begin(), B.end(), S[i].second) - 1;
        res.push_back(S[i]);
        while (i != S.size() && S[i].first <= res.back().second)
            i++;
    }
    res.swap(S);
    res.clear();
}

#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        bad[y].push_back(x);
        if (y > 1)
            bad[y - 1];
        if (y < n)
            bad[y + 1];
    }
    bad[1], bad[n];
    vector<pair<int, int> > seg(1, make_pair(1, 1));
    vector<pair<int, int> > nseg;
    for (map<int, vector<int> >::iterator it = bad.begin(); it != bad.end(); it++)
    {
        int y = it->first;
        it->second.push_back(n + 1);
        sort(it->second.begin(), it->second.end());
        for (int i = 0; i < seg.size(); i++)
        {
            int l = seg[i].first, r = seg[i].second;
            vector<int>::iterator itl = lower_bound(it->second.begin(), it->second.end(), l);
            vector<int>::iterator itr = upper_bound(it->second.begin(), it->second.end(), r);
            vector<int> U(itl, itr);
            U.insert(U.begin(), l - 1);
            U.push_back(r + 1);
            for (int j = 0; j + 1 < U.size(); j++)
            {
                int nl = U[j] + 1, nr = U[j + 1] - 1;
                if (nl > nr)
                    continue;
                nseg.push_back(make_pair(nl, nr));
            }
        }
        eprintf("%d\n", y);
        relax(nseg, it->second);
        nseg.swap(seg);
        nseg.clear();
        for (int i = 0; i < seg.size(); i++)
            eprintf("[%d %d] ", seg[i].first, seg[i].second);
        eprintf("\n");
    }
    bool ans = (!seg.empty() && seg.back().second == n);
    if (ans)
        printf("%d\n", 2 * n - 2);
    else
        printf("-1\n");
}