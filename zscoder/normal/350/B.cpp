#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000 * 100 + 5;
int type[N], prev[N];
int cntFrom[N];
int n;
inline bool read()
{
    if (!(cin >> n))
        return false;

    for(int i = 0; i < n; i++)
        scanf("%d", &type[i]);
  
    for(int i = 0; i < n; i++) 
    {
        cin >> prev[i];
        prev[i]--;
        if (prev[i] != -1)
            cntFrom[prev[i]]++;
    }

    return true;
}

inline void solve()
{
    vector < int > ans;
    for(int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            int curV = i;

            vector < int > cur;
            while (prev[curV] != -1 && cntFrom[prev[curV]] <= 1)
            {
                cur.push_back(curV);

                curV = prev[curV];

            }

            cur.push_back(curV);

            if (ans.size() < cur.size())
                ans = cur;
        }
    }

    printf("%d\n", ans.size());
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i] + 1);
    }   
    puts("");
}
int main()
{
    while (read())
     solve();
}