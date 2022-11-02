#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m, k;
        cin >> n >> m >> k;
        long c[100];
        bool flag = true;
        for(int j = 0; j < n; j++){
            cin >> c[j];
        }
        for(int j = 0; j < n-1; j++){
            if(c[j] >= max(c[j+1]-k, (long)0)){
                m += c[j]-max(c[j+1]-k, (long)0);
            }else if(m >= max(c[j+1]-k, (long)0)-c[j]){
                m -= max(c[j+1]-k, (long)0)-c[j];
            }else{
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
    }
}