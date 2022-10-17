#include <iostream>
#include <vector>

using namespace std;

class fenwick
{
    long long *arr;
    int len;
public:
    fenwick(const int &N) : arr(new long long[N + 1]), len(0) {}
    ~fenwick() {delete []arr;}

    void add(long long x)
    {
        arr[++len] = x;
        int base = len & (len - 1), tar = len - 1;
        while(base != tar)
        {
            arr[len] += arr[tar];
            tar &= tar - 1;
        }
        return;
    }

    void update(int n, long long x)
    {
        ++n;
        while(n <= len)
        {
            arr[n] += x;
            n += n & -n;
        }
        return;
    }

    long long sum(int n) const
    {
        arr[0] = 0;
        while(n)
        {
            arr[0] += arr[n];
            n &= n - 1;
        }
        return arr[0];
    }

    void init(void) {len = 0; return;}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //phase 1 : input
    int n, q; cin >> n >> q;
    int per[n]; for(int &i : per){cin >> i; --i;}
    int l[q]; for(int &i : l){cin >> i; --i;}
    int r[q]; for(int &i : r){cin >> i; --i;}

    vector<pair<int, int> > qr_l[n]{}, qr_r[n]{};
    for(int i = 0; i < q; ++i)
    {
        qr_l[l[i]].emplace_back(r[i], i);
        qr_r[r[i]].emplace_back(l[i], i);
    }

    //phase 2 : pretreatment - place of bigger one
    int inv[n]; for(int i = 0; i < n; ++i) inv[per[i]] = i;

    vector<int> ls_l[n]{}, ls_r[n]{};
    int mqueue[n], qlen = 0; mqueue[0] = (1 << 20);

    for(int i = n - 1; ~i; --i)
    {
        while(per[i] > mqueue[qlen]) ls_l[i].push_back(inv[mqueue[qlen--]]);
        mqueue[++qlen] = per[i];
    }

    qlen = 0;
    for(int i = 0; i < n; ++i)
    {
        while(per[i] > mqueue[qlen]) ls_r[i].push_back(inv[mqueue[qlen--]]);
        mqueue[++qlen] = per[i];
    }

    //phase 3 : operate fenwick tree
    long long ans[q]{};
    fenwick fw_1(n), fw_n(n);

    for(int i = n - 1; i >= 0; --i)
    {
        int cnt = n - i - 1;

        for(const int &v : ls_l[i])
        {
            int cnt_v = n - v - 1;
            fw_1.update(cnt_v, cnt - 1);
            fw_n.update(cnt_v, -1);
        }

        fw_1.add(-cnt);
        fw_n.add(1);

        long long as; if(qr_l[i].size()) as = fw_1.sum(cnt + 1) + cnt * fw_n.sum(cnt + 1);
        for(const auto &p : qr_l[i])
            ans[p.second] += as - (fw_1.sum(n - p.first - 1) + cnt * fw_n.sum(n - p.first - 1));
    }

    fw_1.init(); fw_n.init();
    for(int i = 0; i < n; ++i)
    {
        for(const int &v : ls_r[i])
        {
            fw_1.update(v, i - 1);
            fw_n.update(v, -1);
        }

        fw_1.add(-i);
        fw_n.add(1);

        long long as; if(qr_r[i].size()) as = fw_1.sum(i + 1) + i * fw_n.sum(i + 1);
        for(const auto &p : qr_r[i])
            ans[p.second] += as - (fw_1.sum(p.first) + i * fw_n.sum(p.first));
    }

    //phase 4 : output
    for(int i = 0; i < q; ++i)
        cout << ans[i] + r[i] - l[i] + 1 << ' ';

    return 0;
}