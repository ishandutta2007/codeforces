#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << a*10 << ' ' << b*10+1 << endl;
    }else if(a+1 == b){
        cout << a*10+9 << ' ' << b*10 << endl;
    }else if(a == 9 && b == 1){
        cout << 99 << ' ' << 100 << endl;
    }else{
        cout << -1 << endl;
    }
}