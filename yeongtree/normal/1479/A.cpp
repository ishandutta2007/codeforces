#include <iostream>

using namespace std;

int n;

int Q(int x)
{
    if(x == 0 || x == n + 1) return (int)1e9;
    cout << "? " << x << endl; cout.flush();
    int ret; cin >> ret;
    return ret;
}

void R(int x)
{
    cout << "! " << x << endl; cout.flush();
    exit(0);
}

int main()
{
    cin >> n;

    int s = 1, e = n + 1;
    while(s + 1 < e)
    {
        int mid = s + e >> 1;
        int x = Q(mid - 1);
        int y = Q(mid);
        int z = Q(mid + 1);
        if(x > y && z > y) R(mid);
        if(x < y) e = mid;
        else s = mid;
    }

    R(s);
}