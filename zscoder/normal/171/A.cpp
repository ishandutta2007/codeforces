#include <iostream>

using namespace std;

int reverseint(int num_)
{
        int inv; inv = 0;

        while (num_>0)
        {
                inv = inv * 10 + (num_%10);
                num_ = num_ / 10;
        }

        return inv;
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << a + reverseint(b);
    return 0;
}