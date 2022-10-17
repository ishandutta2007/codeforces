#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a = 0, b = 0;
    for(int i = 0; i < n; ++i){int k; cin >> k; if(k == 1) ++a; else ++b;}

    if(b == 0)
    {
        for(int i = 0; i < a; ++i) cout << "1 ";
    }

    else if(a == 0)
    {
        for(int i = 0; i < b; ++i) cout << "2 ";
    }

    else if(a & 1)
    {
        cout << "2 ";
        for(int i = 0; i < a; ++i) cout << "1 ";
        for(int i = 1; i < b; ++i) cout << "2 ";
    }

    else
    {
        cout << "2 ";
        for(int i = 1; i < a; ++i) cout << "1 ";
        for(int i = 1; i < b; ++i) cout << "2 ";
        cout << "1 ";
    }

    return 0;
}