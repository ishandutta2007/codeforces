#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[20];

int main(){
    int n;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        bool flag = false;
        for(int i = 0;i < (1 << n);i++){
            int sum = 0;
            for(int j = 0;j < n;j++){
                if(i & (1 << j)){
                    sum += a[j];
                }else{
                    sum -= a[j];
                }
            }
            if(sum % 360 == 0){
                flag = true;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}