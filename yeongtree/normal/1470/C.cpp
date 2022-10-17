#include <iostream>

using namespace std;

int out(int x)
{
    cout << "? " << x << endl; cout.flush();
    int t; cin >> t;
    return t;
}

int main()
{
    int n, k; cin >> n >> k;
    out(1);
    int t = out(n);
    if(t > k) { cout << "! " << n - 1; cout.flush(); return 0; }
    if(t < k) { cout << "! " << 1; cout.flush(); return 0; }
    t = out(n - 1);
    if(t > k)
    {
        if(n == 4) { cout << "! " << 2; cout.flush(); return 0; }
        int p = out(n - 2);
        if(p == k) { cout << "! " << n - 2; cout.flush(); return 0; }
        else { cout << "! " << n - 3; cout.flush(); return 0; }
    }
    if(t < k) { cout << "! " << n; cout.flush(); return 0; }
    int pos = n - 1;
    int s = 0, e = 0;
    for(int i = 2; i < 999; ++i)
    {
        pos -= i; pos = max(pos, 1);
        if(out(pos) > k)
        {
            s = max(pos - i - 1, 1);
            e = pos;
            break;
        }
    }
    while(s + 1 < e)
    {
        int mid = s + e >> 1;
        int p = out(mid);
        if(p == k) { cout << "! " << mid; cout.flush(); return 0; }
        else if(p < k) s = mid;
        else e = mid;
    }
    cout << "! " << s; cout.flush(); return 0;
}