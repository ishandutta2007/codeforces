#include <iostream>
#include <queue>

using namespace std;

int pen[202020];
int n;

void upd(int x, int val)
{
    ++x;
    while(x <= n)
    {
        pen[x] += val;
        x += x & -x;
    }
}

int sum(int x)
{
    int ret = 0;
    while(x)
    {
        ret += pen[x];
        x &= x - 1;
    }
    return ret;
}

inline int abs(int x) {return x < 0 ? -x : x;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i, --i;
    int ord[n]; for(int i = 0; i < n; ++i) ord[arr[i]] = i;

    priority_queue<int> dn;
    priority_queue<int, vector<int>, greater<int>> up;

    dn.push(ord[0]);
    upd(n - ord[0] - 1, 1);
    cout << "0 ";

    long long per = 0;
    long long pos = 0;
    int mid = ord[0];
    for(int i = 1; i < n; ++i)
    {
        pos += sum(n - ord[i] - 1);
        upd(n - ord[i] - 1, 1);

        per += abs(dn.top() - ord[i]);
        if(dn.top() < ord[i])
        {
            up.push(ord[i]);
            per -= up.size();
        }
        else
        {
            per -= dn.size();
            dn.push(ord[i]);
        }

        if(dn.size() > up.size() + 1)
        {
            up.push(dn.top());
            dn.pop();
        }
        else if(dn.size() < up.size())
        {
            dn.push(up.top());
            up.pop();
        }

        per -= max(0, (dn.top() - mid - 1)) * (dn.size() - up.size());
        mid = dn.top();

        cout << pos + per << ' ';
    }
}