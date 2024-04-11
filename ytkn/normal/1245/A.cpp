#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

template <typename T>
T gcd(T a, T b){
    if(a < b) swap(a, b);
    while(b != 0){
        T tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum< t; dum++){
        int a, b;
        cin >> a >> b;
        int m = gcd<int>(a, b);
        if(m == 1){
            cout << "Finite" << endl;
        }else{
            cout << "Infinite" << endl;
        }
    }
}