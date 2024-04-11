#include <iostream>

using  namespace std;

int d[200000];

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            d[j] = c-'0';
        }
        bool ok = false;
        for(int j = 0; j <= 10; j++){
            int l = 0, r = 0;
            int il = n;
            int ir = -1;
            for(int k = 0; k < n; k++){
                if(d[k] < j){
                    if(d[k] >= l) l = d[k];
                    else break;
                    ir = max(ir, k);
                }else if(d[k] > j){
                    if(d[k] >= r) r = d[k];
                    else break;
                    il = min(il, k);
                }
                if(k == n-1){
                    ok = true;
                    for(int l = 0; l < n; l++){
                        if(d[l] == j && il <= l && ir >= l) ok = false;
                    }
                    if(ok){
                    //cout << j << ' ' << il << ' ' << ir << endl;
                        for(int l = 0; l < n; l++){
                            if(d[l] < j) cout << 1;
                            else if(d[l] == j && l < il) cout << 2;
                            else if(d[l] == j && l > ir) cout << 1;
                            else cout << 2;
                        }
                        cout << endl;
                    }
                }
            }
            if(ok) break;
        }
        if(!ok){
            cout << '-' << endl;
        }
    }
}