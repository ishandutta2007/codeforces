#include <iostream>
using namespace std;

const int N = 150;

struct note
{
    int s, r, h, c;
} Q[N];

bool bad[N];

bool ls(note a, note b)
{
    return a.s < b.s && a.h < b.h && a.r < b.r;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Q[i].s >> Q[i].r >> Q[i].h >> Q[i].c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (ls(Q[i], Q[j]))
                bad[i] = 1;
        }
    int mnc = 1e9;
    int mni = -1;
    for (int i = 0; i < n; i++)
        if (!bad[i])
            if (mnc > Q[i].c)
                mnc = Q[i].c, mni = i + 1;

    if (mni == -1)
        while(1);
    cout << mni;
}