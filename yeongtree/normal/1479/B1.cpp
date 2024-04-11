#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;
    int a = 0, b = -1, c = -1, d = 0;
    for(auto i : A)
    {
        if(a == 0)
        {
            ++d;
            b = i;
            a = 1;
        }

        else if(a == 1 && b == i)
        {
            ++d;
            c = i;
            a = 2;
        }

        else if(a == 1)
        {
            ++d;
            b = i;
        }

        else if(a == 2 && b == i && c == i) ;

        else if(a == 2 && b == i)
        {
            ++d;
            c = i;
        }

        else if(a == 2 && c == i)
        {
            ++d;
            b = i;
        }

        else if(b == c)
        {
            ++d;
            c = i;
        }

        else
        {
            ++d;
            b = i;
            c = -1;
            a = 1;
        }
    }

    cout << d;
}