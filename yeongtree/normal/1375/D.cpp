#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> A;
priority_queue<int, vector<int>, greater<int>> Q;
int arr[1010];
int cnt[1010];

void dfs(int x, int p)
{
    A.push_back(x);
    int t = arr[x];
    arr[x] = x;
    if(x == p) return;
    dfs(t, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        A.clear();
        cin >> n;
        for(int i = 0; i < n; ++i) cnt[i] = 0;
        for(int i = 0; i < n; ++i) cin >> arr[i], ++cnt[arr[i]];
        for(int i = 0; i < n; ++i) if(cnt[i] == 0) Q.push(i);
        while(Q.size())
        {
            int i = Q.top(); Q.pop();
            if(i == n) break;
            A.push_back(i);
            if(!--cnt[arr[i]]) Q.push(arr[i]);
            arr[i] = i;
        }
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] != i) A.push_back(i), dfs(arr[i], i);
        }

        cout << A.size() << '\n';
        for(int i : A) cout << i + 1 << ' ';
        cout << '\n';
    }
}