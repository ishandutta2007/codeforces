#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string a;
        cin >> a;

        bool found = false;
        for(int mask = 0; mask < (1 << 3); mask++){
            int c = 0;
            bool ok = true;

            for(int i = 0; i < (int)a.size(); i++){
                if(mask & (1 << (a[i] - 'A'))){
                    c++;
                }else{
                    if(c == 0){
                        ok = false;
                        break;
                    }
                    c--;
                }
            }
            if(ok && c == 0){
                found = true;
                break;
            }
        }

        if(found)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}