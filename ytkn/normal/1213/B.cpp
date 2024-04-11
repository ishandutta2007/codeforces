#include <iostream>

using namespace std;

int a[150000];
const int INF = 1e+7;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j= 0; j < n; j++){
            cin>> a[j];
        }
        int m = INF;
        int ans = 0;
        for(int j = n-1; j >= 0; j--){
            if(a[j] > m) ans++;
            m = min(m, a[j]);
        }
        cout << ans << endl;
    }
}