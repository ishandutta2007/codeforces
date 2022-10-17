#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P
{
    int s, e, x;
};

bool operator< (const P &x, const P &y)
{
    return x.s < y.s;
}

bool operator> (const P &x, const P &y)
{
    return x.s > y.s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n], B[n]; for(int i = 0; i < n; ++i) cin >> A[i] >> B[i];

    vector<P> lw, gr;
    for(int i = 0; i < n; ++i)
    {
        if(A[i] < B[i]) lw.push_back({A[i], B[i], i + 1});
        else gr.push_back({A[i], B[i], i + 1});
    }

    if(lw.size() >= gr.size())
    {
        sort(lw.begin(), lw.end(), greater<P>());
        cout << lw.size() << '\n';
        for(auto &i : lw) cout << i.x << ' ';
    }

    else
    {
        sort(gr.begin(), gr.end(), less<P>());
        cout << gr.size() << '\n';
        for(auto &i : gr) cout << i.x << ' ';
    }

    return 0;
}