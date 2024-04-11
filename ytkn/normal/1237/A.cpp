#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    long a;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a%2 != 0){
            if(a > 0){
                if(cnt%2 == 0) cout << a/2 << endl;
                else cout << (a+1)/2 << endl;
            }else{
                if(cnt%2 != 0) cout << (a)/2 << endl;
                else cout << (a-1)/2 << endl;
            }
            cnt++;
        }else{
            cout << (a/2) << endl;
        }
        //cout << cnt << endl;
    }
}