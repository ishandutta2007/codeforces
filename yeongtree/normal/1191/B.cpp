#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct X
{
    int c, n;
};

void input(X &x)
{
    string tmp; cin >> tmp;
    x.n = tmp[0] - 48;
    if(tmp[1] == 'm') x.c = 0;
    if(tmp[1] == 'p') x.c = 1;
    if(tmp[1] == 's') x.c = 2;
}

bool three(X &x, X &y, X &z)
{
    if(x.c == y.c && y.c == z.c)
    {
        int arr[3] = {x.n, y.n, z.n};
        sort(arr, arr + 3);
        if(arr[0] == arr[1] && arr[1] == arr[2]) return true;
        if(arr[0] + 1 == arr[1] && arr[1] + 1 == arr[2]) return true;
    }
    return false;
}

bool two(X &x, X &y)
{
    if(x.c == y.c)
    {
        int arr[2] = {x.n, y.n};
        sort(arr, arr + 2);
        if(arr[0] == arr[1]) return true;
        if(arr[0] + 1 == arr[1]) return true;
        if(arr[0] + 2 == arr[1]) return true;
    }
    return false;
}


int main()
{
    X a, b, c;
    input(a); input(b); input(c);

    if(three(a, b, c)) {cout << '0'; return 0;}
    if(two(a, b) || two(b, c) || two(c, a)) {cout << '1'; return 0;}
    cout << '2'; return 0;
}