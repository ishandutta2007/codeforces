#include<bits/stdc++.h>
using namespace std;
vector<int> g[20000];
int a[100001];
vector<int> p;
void dele(int x)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        a[g[x][i]]--;
        if (a[g[x][i]] == 1)
            p.push_back(g[x][i]);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        a[x]++;
        a[y]++;

    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            p.push_back(i);

    }
    while (p.size()>1)
    {
        int x = p[0];
        int y = p[1];
        int ans;
        cout << "? " << x << " " << y << endl;
        cin >> ans;
        if (ans == x || ans == y)
        {
            cout << "! " << ans << endl;
            return 0;
        }
        dele(x);
        dele(y);
        p.erase(p.begin());
        p.erase(p.begin());

    }
    cout <<"! "<<p[0] << endl;

}