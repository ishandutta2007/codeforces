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
    int n;
    cin >> n;
    int a = n / 36;
    int b = (n % 36) / 3;
    if(((n % 36) % 3) == 2){
        b++;
        if(b == 12){
            b = 0;
            a++;
        }
    }
    cout << a << ' ' << b << endl;
    return 0;
}