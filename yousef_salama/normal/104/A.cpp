#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
int main(){
//    freopen("a.in", "r", stdin);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 10, 10, 10}, n;
    cin >> n;
    n -= 10;
    if(n == 0)cout << 0 << endl;
    else if(n == 1)cout << 4 << endl;
    else if(n > 1 && n < 10)cout << 4 << endl;
    else if(n == 10)cout << 15 << endl;
    else if(n == 11)cout << 4 << endl;
    else cout << 0 << endl;
    return 0;
}