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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int N;
vector <int> fib;
int main(){
    cin >> N;
    if(N == 0)cout << 0 << ' ' << 0 << ' ' << 0 << endl;
    else if(N == 1)cout << 0 << ' ' << 0 << ' ' << 1 << endl;
    else{
        fib.push_back(0);
        fib.push_back(1);
        while(fib.back() != N){
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        }
        cout << fib[fib.size() - 3] << ' ' << fib[fib.size() - 3] << ' ' << fib[fib.size() - 4] << endl;
    }

    return 0;
}