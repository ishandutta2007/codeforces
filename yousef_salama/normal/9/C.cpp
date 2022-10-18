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

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;
int Solve(string s, int n){
    if(atoi(s.c_str()) > n)
        return 0;
    else
        return 1 + Solve(s + '0', n) + Solve(s + '1', n);
}
int main(){
    int n;
    cin >> n;
    cout << Solve("1", n) << endl;
    return 0;
}