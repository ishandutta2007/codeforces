#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)cout << (a[i] ^ b[i]);
}