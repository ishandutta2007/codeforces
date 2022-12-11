#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 20;

int n;
int a[maxn];
int b[maxn];

void work()
{
    cin >>n;
    for(int i = 0; i < n; i++) cin >>a[i];

    map< int, vector<int> > mp;
    for(int i = 0; i < n; i++)
    {
        mp[a[i]].push_back(i);
    }

    vector< pair<int, vector<int> > > one, two, mul;

    for(const auto &x : mp)
    {
        if(x.second.size() == 1) one.push_back(x);
        if(x.second.size() == 2) two.push_back(x);
        if(x.second.size() > 2) mul.push_back(x);
    }

//    cout <<one.size() <<" " <<two.size() <<" " <<mul.size() <<endl;

    int flag = 1, na = 0, nb = 0;

    na = one.size() / 2;
    nb = one.size() - na;
    swap(na, nb);
    for(int i = 0; i < na; i++)
    {
        auto v = one[i].second;
        for(auto x : v) b[x] = 0;
    }
    for(int i = na; i < na + nb; i++)
    {
        auto v = one[i].second;
        for(auto x : v) b[x] = 1;
    }

    if(na == nb)
    {
        puts("YES");
        for(int i = 0; i < n; i++) cout <<(char) (b[i] + 'A');
        cout <<endl;
        return ;
    }

    if(mul.size() == 0)
    {
        puts("NO");
    }
    else
    {
        int x = mul[0].second[0];
        b[x] = 1;
        puts("YES");
        for(int i = 0; i < n; i++) cout <<(char) (b[i] + 'A'); cout <<endl;
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