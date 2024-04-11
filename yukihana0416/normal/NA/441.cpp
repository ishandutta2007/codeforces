#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 20;

int n;

int check(string s)
{
    int res = 0;
    for(auto x : s)
    {
        if('0' <= x && x <= '9') res |= 1;
        if('a' <= x && x <= 'z') res |= 2;
        if('A' <= x && x <= 'Z') res |= 4;
    }
    return res == 7;
}

int dfs(string &s, int p, int q)
{
    if(p == q)
    {
        return check(s);
    }

    s[p] = '0';
    if(dfs(s, p + 1, q)) return 1;
    s[p] = 'a';
    if(dfs(s, p + 1, q)) return 1;
    s[p] = 'A';
    if(dfs(s, p + 1, q)) return 1;
    return 0;
}

void work()
{
    cin >>n;
    while(n--)
    {
        string s;
        cin >>s;
        int flag = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j + i < s.size(); j++)
            {
                string t = s;
                if(dfs(t, j , j + i))
                {
                    cout <<t <<endl;
                    flag = 1;
                }
                if(flag) break;
            }

            if(flag) break;
        }
    }
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