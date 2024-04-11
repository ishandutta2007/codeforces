#include <iostream>

using namespace std;

int star(int n)
{
    n  *= (n - 1);
    n  *= 6;
    n += 1;
    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << star(n);
}