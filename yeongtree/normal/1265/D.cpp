#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d; cin >> a >> b >> c >> d;

    if(a + b + c + d == 0) cout << "YES\n";
    else if(a > b + 1 || c + 1 < d) cout << "NO";
    else if(a <= b && c >= d)
    {
        b -= a; c -= d;
        if(b == c)
        {
            cout << "YES\n";
            for(int i = 0; i < a; ++i) cout << "0 1 ";
            for(int i = 0; i < b; ++i) cout << "2 1 ";
            for(int i = 0; i < d; ++i) cout << "2 3 ";
        }
        else if(b == c + 1)
        {
            cout << "YES\n";
            for(int i = 0; i < a; ++i) cout << "1 0 ";
            cout << "1 ";
            for(int i = 0; i < d; ++i) cout << "2 3 ";
            for(int i = 0; i < c; ++i) cout << "2 1 ";
        }
        else if(b + 1 == c)
        {
            cout << "YES\n";
            for(int i = 0; i < d; ++i) cout << "2 3 ";
            cout << "2 ";
            for(int i = 0; i < a; ++i) cout << "1 0 ";
            for(int i = 0; i < b; ++i) cout << "1 2 ";
        }
        else cout << "NO";
    }
    else if(a == b + 1)
    {
        if(c + d == 0)
        {
            cout << "YES\n";
            cout << "0 ";
            for(int i = 1; i < a; ++i) cout << "1 0 ";
        }
        else cout << "NO";
    }
    else if(c + 1 == d)
    {
        if(a + b == 0)
        {
            cout << "YES\n";
            cout << "3 ";
            for(int i = 1; i < d; ++i) cout << "2 3 ";
        }
        else cout << "NO";
    }
    else cout << "NO";

    return 0;
}