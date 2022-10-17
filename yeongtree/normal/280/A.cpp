#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cmath>
#include <iomanip>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;
const long double PI = atan(1.0l) * 4;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, c; cin >> w >> h >> c;
    if(h > w) swap(w, h);
    if(c > 90) c = 180 - c;
    long double x = (long double)w / 2;
    long double y = (long double)h / 2;
    long double a = (long double)c / 180 * PI;
    long double b = atan((long double)y / x);

    if(a < 2 * b) cout << fixed << setprecision(20) << 4 * x * y - (pow((x - tan(a / 2) * y), 2) + pow((y - tan(a / 2) * x), 2)) * tan(a);
    else cout << fixed << setprecision(20) << 2 * y * (y / tan(a / 2) + y * tan(a / 2));
}