#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char s[3][1005];
int cnt[30][3];
vector<pair<pair<int, int>, int>> P;
vector<pair<int, int>> ans;
int main()
{
    scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
    int Minn = 2000;
    for (int i = 0; i < 3; i++)
    {
        int len = strlen(s[i] + 1);
        Minn = min(Minn, len);
        for (int j = 1; j <= len; j++)
        {
            cnt[s[i][j] - 'A'][i]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while (P.size() < Minn)
        {
            pair<int, int> tmp = {0, 0};
            if (cnt[i][0] <= cnt[i][1] && cnt[i][0] <= cnt[i][2] && cnt[i][1] && cnt[i][2])
                tmp = {1, 2};
            else if (cnt[i][2] <= cnt[i][0] && cnt[i][2] <= cnt[i][1] && cnt[i][0] && cnt[i][1])
                tmp = {0, 1};
            else if (cnt[i][1] <= cnt[i][0] && cnt[i][1] <= cnt[i][2] && cnt[i][0] && cnt[i][2])
                tmp = {0, 2};
            if (tmp == make_pair(0, 0))
                break;
            P.push_back(make_pair(tmp, i));
            cnt[i][tmp.first]--;
            cnt[i][tmp.second]--;
        }
    }
    vector<int> res[3];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < cnt[i][j]; k++)
            {
                res[j].push_back(i);
            }
        }
    }
    for (auto &p : P)
    {
        int Now = 3 - p.first.second - p.first.first;
        ans.push_back({res[Now].back(), p.second});
        res[Now].pop_back();
    }
    while (res[0].size() + res[1].size() + res[2].size())
    {
        pair<int, int> tmp = {0, 0};
        if (res[0].size() <= res[1].size() && res[0].size() <= res[2].size() && res[1].size() && res[2].size())
            tmp = {1, 2};
        else if (res[1].size() <= res[0].size() && res[1].size() <= res[2].size() && res[0].size() && res[2].size())
            tmp = {0, 2};
        else if (res[2].size() <= res[1].size() && res[2].size() <= res[0].size() && res[0].size() && res[1].size())
            tmp = {0, 1};
        else
        {
            for (int j = 0; j < 3; j++)
                if (res[j].size())
                    tmp = {j, j};
        }
        ans.push_back({res[tmp.first].back(), res[tmp.second].back()});
        res[tmp.first].pop_back();
        if (tmp.second != tmp.first)
            res[tmp.second].pop_back();
    }
    printf("%d\n", ans.size());
    for (auto &p : ans)
    {
        printf("%c%c\n", p.first + 'A', p.second + 'A');
    }
}