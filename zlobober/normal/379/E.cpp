#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;

const int N = 350;

const double eps = 1e-9;

struct vt
{
    double x, y;
    vt(double _x, double _y)
    {
        x = _x, y = _y;
    }
    friend vt operator+(vt a, vt b)
    {
        return vt(a.x + b.x, a.y + b.y);
    }
    friend vt operator -(vt a, vt b)
    {
        return vt(a.x - b.x, a.y - b.y);
    }
    friend double operator *(vt a, vt b)
    {
        return a.x * b.x + a.y * b.y;
    }
    friend double operator ^(vt a, vt b)
    {
        return a.x * b.y - b.x * a.y;
    }
    friend vt operator *(vt a, double k)
    {
        return vt(a.x * k, a.y * k);
    }
    friend vt operator /(vt a, double k)
    {
        return vt(a.x / k, a.y / k);
    }
    friend vt operator *(double k, vt a)
    {
        return vt(k * a.x, k * a.y);
    }
    vt(){}
};

double ans[N];

const double inf = 1500;

inline vt inter(vt a, vt b, vt c, vt d)
{
    assert(fabs((d - c) ^ (b - a)) > eps);
    return (a * ((d - c) ^ (b - c)) + b * ((a - c) ^ (d - c))) / ((d - c) ^ (b - a));
}

double dist(vt a, vt b)
{
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void go(vector<pair<vt, vt> > S)
{
    vector<vt> C;
    C.push_back(vt(0, inf));
    C.push_back(vt(0, 0));
    C.push_back(vt(1, 0));
    C.push_back(vt(1, inf));
    vector<char> msk;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j + 1 < C.size(); j++)
        {
            if (dist(C[j], C[j + 1]) < eps)
                C.erase(C.begin() + j + 1), --j;
        }
        vt a = S[i].first;
        vt b = S[i].second;
        int mnj = N;
        int mxj = -N;
        for (int j = 0; j < C.size(); j++)
        {
            msk.push_back(((a - b) ^ (C[j] - b)) >= -eps);
            if (msk.back())
                mnj = min(mnj, j), mxj = max(mxj, j);    
        }
        if (mnj > mxj)
            continue;
        assert(mnj >= 1);
        assert(mxj + 1 < C.size());
        vt p = inter(C[mnj], C[mnj - 1], a, b);
        vt q = inter(C[mxj], C[mxj + 1], a, b);
        double S = 0;
        vector<vt> R(C.begin() + mnj, C.begin() + mxj + 1);
        R.push_back(q);
        R.push_back(p);
        C.erase(C.begin() + mnj, C.begin() + mxj + 1);
        C.insert(C.begin() + mnj, p);
        C.insert(C.begin() + mnj + 1, q);
        for (int t = 0; t < R.size(); t++)
            S += R[t] ^ R[(t + 1 == R.size()) ? 0 : t + 1];
        S = fabs(S) / 2;
        ans[i] += S;
    }
}

int A[N][N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            scanf("%d", &A[i][j]);
    for (int j = 0; j < k; j++)
    {
        vector<pair<vt, vt> > P;
        for (int i = 0; i < n; i++)
            P.push_back(make_pair(vt(0, A[i][j]), vt(1, A[i][j + 1])));
        go(P);
    }
    for (int i = 0; i < n; i++)
        printf("%.10lf\n", ans[i]);
}