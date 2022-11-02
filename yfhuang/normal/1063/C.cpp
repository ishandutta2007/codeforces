#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;

string ask(int x, int y){
    cout << x << " " << y << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans;
}

bool in(int x, int y){
    return 0 <= x and x <= 1e9 and y >= 0 and y <= 1e9;
}

int main(){
    cin >> n;
    long long l = 1, r = 2e9;
    string str = ask(0, 0);
    for(int i = 1;i < n;i++){
        long long mid = (l + r) / 2;
        long long x = (mid + 1) / 2;
        long long y = mid / 2;
        if(ask(x, y) == str){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    //cout << l << " " << r << endl;
    //if(l == r){
    //    cout << "!!!" << endl;
    //}
    long long x1 = (l + 1) / 2;
    long long y1 = l / 2;
    long long x2 = l / 2 + 1;
    long long y2 = (l + 1) / 2;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}