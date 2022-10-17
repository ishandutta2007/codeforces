#include <iostream>
#include <string>

using namespace std;

inline int abs(int x){return (x >= 0 ? x : -x);}

int main()
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int x1, y1, x2, y2, n; cin >> x1 >> y1 >> x2 >> y2 >> n;
    string str; cin >> str;

    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        switch(str[i])
        {
            case 'U': arr[i] = 0; break;
            case 'D': arr[i] = 1; break;
            case 'L': arr[i] = 2; break;
            case 'R': arr[i] = 3; break;
        }
    }

    int x[n + 1], y[n + 1];
    x[0] = 0; y[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        x[i] = x[i - 1] + dx[arr[i - 1]];
        y[i] = y[i - 1] + dy[arr[i - 1]];
    }

    long long s = -1, t = (long long)1e15;
    while(s + 1 < t)
    {
        long long mid = (s + t) / 2;
        long long q = mid / n;
        long long r = mid % n;
        long long ndx = q * x[n] + x[r];
        long long ndy = q * y[n] + y[r];
        long long dst = abs(x1 + ndx - x2) + abs(y1 + ndy - y2);

        if(mid < dst) s = mid;
        else t = mid;
    }

    if(t == (long long)1e15) cout << "-1";
    else cout << t;

    return 0;
}