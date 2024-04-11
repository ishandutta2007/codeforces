#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

int ans[300][300];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i%2 == 0){
                ans[j][i] = i*n+j+1;
            }else{
                ans[j][i] = (i+1)*n-j;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j];
            if(j == n-1) cout << endl;
            else cout << ' ';
        }
    }
}