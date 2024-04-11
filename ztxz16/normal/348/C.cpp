#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647
#define ll long long

using namespace std;

vector <int> S[100005], Con[100005], Num[100005];
vector <int>::iterator it;
ll n, m, q, i, j, tot, s, x, y, t2, Now, init[100005], VV[100005];
ll list[100005], Val[100005];
ll tag, Hash[100005];
char kind[105];

int main()
{
    scanf("%I64d %I64d %I64d", &n, &m, &q);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &Val[i]);
    for (i = 1; i <= m; i++)
    {
        scanf("%I64d", &tot);
        s = 0;
        for (j = 1; j <= tot; j++)
            scanf("%I64d", &x), s += Val[x], S[i].push_back(x);
        if (tot >= 300)
            list[++t2] = i;
        init[i] = s;
    }
    
    for (i = 1; i <= t2; i++)
    {
        Now = list[i];
        tag++;
        for (it = S[Now].begin(); it != S[Now].end(); ++it)
            Hash[(*it)] = tag;
        for (j = 1; j <= m; j++)
        {
            if (j == Now)
                continue;
            s = 0;
            for (it = S[j].begin(); it != S[j].end(); ++it)
                if (Hash[(*it)] == tag)
                    s++;
            if (s > 0)
            {
                Con[j].push_back(Now);
                Num[j].push_back(s);
            }
        }
    }
    
    for (i = 1; i <= q; i++)
    {
        scanf("%s", kind);
        if (kind[0] == '?')
        {
            scanf("%I64d", &x);
            if (S[x].size() < 300)
            {
                s = 0;
                for (it = S[x].begin(); it != S[x].end(); ++it)
                    s += Val[*it];
                for (j = 0; j < Con[x].size(); j++)
                    s += VV[Con[x][j]] * Num[x][j];
                printf("%I64d\n", s);
            }
            
            else
            {
                s = init[x];
                printf("%I64d\n", s);
            }
        }
        
        else
        {
            scanf("%I64d %I64d", &x, &y);
            if (S[x].size() < 300)
            {
                for (it = S[x].begin(); it != S[x].end(); ++it)
                    Val[*it] += y;
                for (j = 0; j < Con[x].size(); j++)
                    init[Con[x][j]] += y * Num[x][j];
            }
            
            else
            {
                VV[x] += y;
                init[x] += S[x].size() * y;
                for (j = 0; j < Con[x].size(); j++)
                    init[Con[x][j]] += y * Num[x][j];
            }
        }
    }
    
    return 0;
}