#include <bits/stdc++.h>

using namespace std;

int n, q;

const int L = 200050;
int a[L];
int cnt[L];

struct segment
{
    int l, r;
    int v;

    bool operator<(const segment &other) const
    {
        return r < other.r;
    }
};

set<segment> segments;

segment get_segment(int x, bool insert)
{
    auto seg = *segments.lower_bound({0, x, 0});
    segments.erase(seg);
    int l = seg.l;
    int r = seg.r;
    while (l > 0 && segments.lower_bound({0, l - 1, 0})->v == seg.v)
    {
        auto prev_seg = *segments.lower_bound({0, l - 1, 0});
        if (prev_seg.r != l - 1)
            break;
        segments.erase(prev_seg);
        l = prev_seg.l;
    }
    while (r < L && segments.lower_bound({0, r + 1, 0})->v == seg.v)
    {
        auto next_seg = *segments.lower_bound({0, r + 1, 0});
        if (next_seg.l != r + 1)
            break;
        segments.erase(next_seg);
        r = next_seg.r;
    }
    if (insert)
        segments.insert({l, r, seg.v});
    return {l, r, seg.v};
}

int get_ans()
{
    return get_segment(L - 1, true).l - 1;
}

void print()
{
    for (auto &&s : segments)
        cout << s.l << " " << s.r << " " << s.v << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < L - 1; i++)
    {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
    }
    segment s;
    s.l = 0;
    s.v = cnt[0];
    for (int i = 1; i < L - 1; i++)
    {
        if (cnt[i] != s.v)
        {
            s.r = i - 1;
            segments.insert(s);
            s.v = cnt[i];
            s.l = i;
        }
    }
    s.r = L;
    segments.insert(s);
    for (int i = 0; i < q; i++)
    {
        int k, l;
        cin >> k >> l;
        k--;
        auto seg = get_segment(a[k], false);
        if (a[k] > seg.l)
        {
            segments.insert({seg.l, a[k] - 1, seg.v});
            seg.l = a[k];
        }
        if (seg.v == 1)
        {
            segments.insert({seg.l, seg.l, 0});
            if (seg.l != seg.r)
                segments.insert({seg.l + 1, seg.r, 1});
        }
        else
        {
            auto next_seg = get_segment(seg.r + 1, false);
            segments.insert({seg.l, seg.r, 1});
            segments.insert({next_seg.l, next_seg.l, 0});
            if (next_seg.l != next_seg.r)
                segments.insert({next_seg.l + 1, next_seg.r, 1});
        }
        a[k] = l;
        seg = get_segment(a[k], false);
        if (a[k] > seg.l)
        {
            segments.insert({seg.l, a[k] - 1, seg.v});
            seg.l = a[k];
        }
        if (seg.v == 0)
        {
            segments.insert({seg.l, seg.l, 1});
            if (seg.l != seg.r)
                segments.insert({seg.l + 1, seg.r, 0});
        }
        else
        {
            auto next_seg = get_segment(seg.r + 1, false);
            segments.insert({seg.l, seg.r, 0});
            segments.insert({next_seg.l, next_seg.l, 1});
            if (next_seg.l != next_seg.r)
                segments.insert({next_seg.l + 1, next_seg.r, 0});
        }
        cout << get_ans() << endl;
    }
    return 0;
}