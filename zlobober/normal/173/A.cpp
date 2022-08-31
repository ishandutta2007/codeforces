#include <iostream>
#include <cstring>
using namespace std;

char to[256];

bool beat (int a, int b)
{
    return (a + 1) % 3 == b;
}

const int N = 1050;
int A[N], B[N];
int a;

int b;

pair<int, int> simulate(int x)
{
    int pta = 0, ptb = 0;
    int first = 0, second = 0;
    for (int i = 0; i < x; i++)
    {
        second += beat(A[pta], B[ptb]);
        first += beat(B[ptb], A[pta]);
        pta = (pta + 1) % a;
        ptb = (ptb + 1) % b;
    }
    return make_pair(first, second);
}

int get(char c)
{
    return to[c];
}

char buf[N];

int main()
{
    to['R'] = 0;
    to['S'] = 1;
    to['P'] = 2;
    int n;
    cin >> n;
    cin >> (buf);
    a = strlen(buf);
    char c;
    for (int i = 0; i < a; i++)
        A[i] = get(buf[i]);
    cin >> buf;
    b = strlen(buf);
    for (int i = 0; i < b; i++)
        B[i] = get(buf[i]);
    pair<int, int> u = simulate(a * b);
    pair<int, int> v = simulate(n % (a * b));
    int k = n / (a * b);
    cout << k * u.first + v.first << ' ' << k * u.second + v.second << endl;
}