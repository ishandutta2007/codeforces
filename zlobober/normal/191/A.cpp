#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 500500;
int D[N];

const int E = 26;
int mx[E][E];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < E; i++)
        for (int j = 0; j < E; j++)
            mx[i][j] = -1e6;
    for (int i = 0; i < n; i++)
    {
        char buf[20];
        cin >> buf;
        int len = strlen(buf);
        int f = buf[0] - 'a';
        int l = buf[len - 1] - 'a';
        for (int u = 0; u < E; u++)
            mx[u][l] = max(mx[u][l], mx[u][f] + len);
        mx[f][l] = max(mx[f][l], len);
    }
    int ans = 0;
    for (int i = 0; i < E; i++)
        ans = max(ans, mx[i][i]);
    cout << ans << endl;
}