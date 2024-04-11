#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> cl[2000];
bool arr[2000];

void f(int x, int y)
{
    if(cl[x].empty() || cl[y].empty()) return;

    for(int i = 1; i <= k; ++i)
    {
        int t = (cl[x].size() <= i ? cl[y][0] : cl[x][i]);
        cout << "? " << t + 1 << endl;
        cout.flush();
        char c; cin >> c;
        if(i == cl[x].size() && c == 'Y') arr[t] = true;
    }
    for(int i = 0; i < k; ++i)
    {
        int t = (cl[y].size() <= i ? cl[x][0] : cl[y][i]);
        cout << "? " << t + 1 << endl;
        cout.flush();
        char c; cin >> c;
        if(i && i <= cl[y].size() && c == 'Y') arr[t] = true;
    }
    for(int i = 0; i < k; ++i)
    {
        int t = (cl[x].size() <= i ? cl[y][0] : cl[x][i]);
        cout << "? " << t + 1 << endl;
        cout.flush();
        char c; cin >> c;
        if((i || cl[y].size() == k) && i < cl[x].size() && c == 'Y') arr[t] = true;
    }
    cout << "R" << endl;
    cout.flush();
}

int main()
{
    cin >> n >> k; m = n / k;

    for(int i = 0; i < m; ++i)
    {
        for(int j = i * k; j < (i + 1) * k; ++j)
        {
            cout << "? " << j + 1 << endl;
            cout.flush();
            char c; cin >> c;
            if(c == 'N') cl[i].push_back(j);
            else arr[j] = true;
        }
        cout << "R" << endl;
        cout.flush();
    }

    for(int i = 0; i < m; ++i)
    {
        for(int j = i + 1; j < m; ++j)
            f(i, j);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) if(!arr[i]) ++ans;
    cout << "! " << ans << endl;
    cout.flush();

    return 0;
}