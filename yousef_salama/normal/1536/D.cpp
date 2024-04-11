#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        int m;
        set <int> s;
        bool ok = true;
        
        for(int i = 0; i < n; i++){
            int b;
            scanf("%d", &b);

            if(!ok)continue;

            if(i == 0){
                s.insert(b);
                m = b;

                continue;
            }

            if(m == b)continue;

            auto d = s.lower_bound(m);
            if(b < m){
                if(d == s.begin()){
                    s.insert(b);
                }else{
                    if(*prev(d) > b){
                        ok = false;
                        continue;
                    }
                    s.insert(b);
                }
            }else{
                if(next(d) == s.end()){
                    s.insert(b);
                }else{
                    if(*next(d) < b){
                        ok = false;
                        continue;
                    }
                    s.insert(b);
                }
            }
            m = b;
        }

        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}