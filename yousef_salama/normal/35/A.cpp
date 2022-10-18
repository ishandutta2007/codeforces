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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int b[4];
    b[0] = b[1] = b[2] = b[3] = 0;
    int n, itr = 3, f, t;
    cin >> n;
    b[n] = 1;
    while(itr--){
        cin >> f >> t;
        swap(b[f], b[t]);
    }
    for(int i = 0; i < 4; i++)if(b[i])
        cout << i << endl;
    return 0;
}