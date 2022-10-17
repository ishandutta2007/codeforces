#include <iostream>
#include <set>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        set<int> S;
        for(int i = 0; i < n; ++i) S.insert(i);
        int A[n];
        while(!S.empty())
        {
            int x = *S.begin();
            cout << "? " << x + 1 << endl; cout.flush();
            int y, z = -1, w = -1;
            cin >> y; --y;
            z = y;

            while(y != w)
            {
                cout << "? " << x + 1 << endl; cout.flush();
                cin >> w; --w;
                A[z] = w;
                S.erase(z);
                z = w;
            }
        }

        cout << "! ";
        for(int i = 0; i < n; ++i) cout << A[i] + 1 << ' ';
        cout << endl;
        cout.flush();
    }
}