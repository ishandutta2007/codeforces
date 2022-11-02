#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long long sum = (1 << n);
        for(int i = n - 1;i >= n - n / 2;i--){
            sum -= (1 << i); 
        }
        for(int i = 1;i < n - n / 2;i++){
            sum += (1 << i);
        }
        cout << sum << endl;
    }
    return 0;
}