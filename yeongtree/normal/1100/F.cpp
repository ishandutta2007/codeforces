#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void bemax(int &x, const int &y)
{
    if(x < y) x = y;
    return;
}

void bemin(int &x, const int &y)
{
    if(x > y) x = y;
    return;
}

struct query
{
    int b, e, num;
    query(const int &_b, const int &_e, const int &_num)
        : b(_b), e(_e), num(_num) {}
};

class basis
{
    int* base;
    int len;

public:
    basis(void) : base(new int[20]{}), len(0) {}

    basis(const basis &other) : base(new int[20]{}), len(other.len)
    {
        for(int i = 0; i < len; ++i)
            base[i] = other.base[i];
    }

    ~basis(){delete []base;}

    void operator=(const basis &other)
    {
        int mlen = (len < other.len ? other.len : len);
        for(int i = 0; i < mlen; ++i)
            base[i] = other.base[i];
        len = other.len;
        return;
    }

    void operator+=(const basis &other)
    {
        if(this->len == 20) return;

        if(len < other.len)
        {
            basis temp = (*this);
            (*this) = other;
            (*this) += temp;
            return;
        }

        for(int i = 0; i < other.len; ++i)
        {
            int tmp = other.base[i];
            for(int j = 0; j < len; ++j)
                bemin(tmp, tmp ^ base[j]);
            if(tmp) base[len++] = tmp;
        }

        return;
    }

    void init(int x)
    {
        base[0] = x;
        for(int i = 1; i < len; ++i)
            base[i] = 0;
        len = (x != 0);
        return;
    }

    void integratenum(int x)
    {
        if(len == 20) return;
        for(int i = 0; i < len; ++i)
            bemin(x, x ^ base[i]);
        if(x) base[len++] = x;
        return;
    }

    int get(void)
    {
        int ans = 0;
        for(int i = 0; i < len; ++i)
            bemax(ans, ans ^ base[i]);
        return ans;
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin.sync_with_stdio(false);

    const int N = 1 << 19;
    int n; cin >> n;
    int arr[N]{}; for(int i = 0; i < n; ++i) cin >> arr[i];

    int m; cin >> m;
    int ans[m];
    vector<query> var[19]{};

    //cout << clock() << endl;

    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        if(x == y) ans[i] = arr[x];
        for(int j = 18; ~j; --j)
            if((x >> j) != (y >> j)){var[j].emplace_back(x, y, i); break;}
    }

    //cout << clock() << endl;

    vector<basis> psum(N);
    for(int i = 0; i < 19; ++i)
    {
        int rng = 1 << i;
        for(int j = 0; j < N; j += (rng << 1))
        {
            psum[j + rng - 1].init(arr[j + rng - 1]);
            for(int k = j + rng - 2; k >= j; --k)
            {
                psum[k] = psum[k + 1];
                psum[k].integratenum(arr[k]);
            }

            psum[j + rng].init(arr[j + rng]);
            for(int k = j + rng + 1; k < j + (rng << 1); ++k)
            {
                psum[k] = psum[k - 1];
                psum[k].integratenum(arr[k]);
            }
        }

        //cout << clock();

        basis tmp;
        for(const auto &q : var[i])
        {
            tmp = psum[q.b];
            tmp += psum[q.e];
            ans[q.num] = tmp.get();
        }

        //cout << ' ' << clock() << endl;
    }
    for(int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
    return 0;
}