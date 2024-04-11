#include <iostream>
#include <utility>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#include <algorithm>
#include <set>

using namespace std;

const int MIN = -1e9;

struct X
{
    int x, y, z, num;
};

bool operator< (const X &x, const X &y)
{
    if(x.x < y.x) return true;
    if(x.x > y.x) return false;
    if(x.y < y.y) return true;
    if(x.y > y.y) return false;
    if(x.z < y.z) return true;
    if(x.z > y.z) return false;
    return false;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    int n; cin >> n;
    X arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        arr[i].num = i + 1;
    }

    set<X> S;
    for(int i = 0; i < n; ++i)
        S.insert(arr[i]);

    for(int i = 0; 2 * i < n; ++i)
    {
        auto l = S.begin();
        cout << l->num << ' ';
        int xx = l->x;
        int xy = l->y;
        int xz = l->z;

        int fx, fy, fz;
        fx = next(l)->x;
        S.erase(l);

        auto r1 = S.lower_bound({fx, xy, MIN});
        if(r1->x == fx) fy = r1->y;
        else fy = prev(r1)->y;

        auto r2 = S.lower_bound({fx, fy, xz});
        if(r2->x == fx && r2->y == fy) fz = r2->z;
        else fz = prev(r2)->z;

        auto r3 = S.lower_bound({fx, fy, fz});
        cout << r3->num << '\n';
        S.erase(r3);
    }

    return 0;
}