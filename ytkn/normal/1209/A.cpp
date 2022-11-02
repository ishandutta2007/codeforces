#include <iostream>
#include <algorithm>
#include <vector>

using  namespace std;

bool used[100];
int n;
int ans = 0;

bool all_used(){
    for(int i = 0; i < n; i++){
        if(!used[i]) return false; 
    }
    return true;
}

int main(){
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    while(!all_used()){
        int m = -1;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                if(m < 0){
                    m = a[i];
                    used[i] = true;
                }else if(a[i]%m == 0){
                    used[i] = true;
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}