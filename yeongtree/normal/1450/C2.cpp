#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n][n];
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                char d; cin >> d;
                if(d == '.') A[i][j] = 0;
                if(d == 'X') A[i][j] = 1;
                if(d == 'O') A[i][j] = -1;
                if((i + j) % 3 == 0 && A[i][j] == 1) ++a;
                if((i + j) % 3 == 1 && A[i][j] == -1) ++a;
                if((i + j) % 3 == 1 && A[i][j] == 1) ++b;
                if((i + j) % 3 == 2 && A[i][j] == -1) ++b;
                if((i + j) % 3 == 2 && A[i][j] == 1) ++c;
                if((i + j) % 3 == 0 && A[i][j] == -1) ++c;
            }
        }

        if(a <= b && a <= c)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if((i + j) % 3 == 0 && A[i][j] == 1) A[i][j] = -A[i][j];
                    if((i + j) % 3 == 1 && A[i][j] == -1) A[i][j] = -A[i][j];
                }
            }
        }
        else if(b <= a && b <= c)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if((i + j) % 3 == 1 && A[i][j] == 1) A[i][j] = -A[i][j];
                    if((i + j) % 3 == 2 && A[i][j] == -1) A[i][j] = -A[i][j];
                }
            }
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if((i + j) % 3 == 2 && A[i][j] == 1) A[i][j] = -A[i][j];
                    if((i + j) % 3 == 0 && A[i][j] == -1) A[i][j] = -A[i][j];
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(A[i][j] == 0) cout << '.';
                if(A[i][j] == 1) cout << 'X';
                if(A[i][j] == -1) cout << 'O';
            }
            cout << '\n';
        }
    }
}