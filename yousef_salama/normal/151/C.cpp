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
long long q;
int main(){
    cin >> q;
    int cnt = 0;
    long long n = q;
    vector <long long> v;
    for(long long i = 2; i * i <= n; i++)if(n % i == 0){
        while(n % i == 0){
            n /= i;
            v.push_back(i);
        }
    }
    if(n > 1)v.push_back(n);
    cnt = v.size();
    if(cnt == 1 || cnt == 0){
        cout << 1 << endl;
        cout << 0 << endl;
    }else if(cnt == 2){
        cout << 2 << endl;
    }else{
        cout << 1 << endl;
        long long ans = 1;
        for(int i = 0; i < cnt - 2; i++)
            ans *= v[i];
        cout << q / ans << endl;
    }
    return 0;
}