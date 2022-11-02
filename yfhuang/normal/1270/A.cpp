#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(){

    int t;
    int n, k1, k2;
    cin >> t;
    while(t--){
        cin >> n >> k1 >> k2;
        bool flag = false;
        for(int i = 1;i <= k1;i++){
            int a;
            scanf("%d", &a);
            if(a == n)
                flag = true;
        }
        for(int i = 1;i <= k2;i++){
            int a;
            scanf("%d", &a);
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}