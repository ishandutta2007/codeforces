#include <bits/stdc++.h>
using namespace std;

int m, mask1, mask2;
map <int, int> mp;
vector <int> b;

bool rec(int i, int rem, int sum, int mask){
    if(m - i < rem)return false;

    if(rem == 0){
        if(mp.count(sum)){
            mask1 = mask;
            mask2 = mp[sum];

            int common = mask1 & mask2;
            mask1 ^= common;
            mask2 ^= common;

            return true;
        }
        mp[sum] = mask;

        return false;
    }

    if(rec(i + 1, rem, sum, mask))return true;
    if(rec(i + 1, rem - 1, sum + b[i], mask | (1 << i)))return true;
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    b.resize(n);

    vector <int> odd, even;

    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        
        if(b[i] % 2 == 0){
            even.push_back(b[i]);
        }else{
            odd.push_back(b[i]);
        }
    }

    vector <int> a;

    if((int)even.size() >= 3){
        a.push_back((even[2] - even[1] + even[0]) / 2);
        a.push_back(even[0] - a.back());
        a.push_back(even[1] - a.back());

        for(int i = 3; i < (int)even.size(); i++)
            a.push_back(even[i] - a.back());
        
        for(int x : odd)
            a.push_back(x - a.back());

    }else if((int)even.size() >= 1 && (int)odd.size() >= 2){
        a.push_back((odd[1] - odd[0] + even[0]) / 2);
        a.push_back(even[0] - a.back());
        a.push_back(odd[0] - a.back());

        for(int i = 1; i < (int)even.size(); i++)
            a.push_back(even[i] - a.back());
        
        for(int i = 2; i < (int)odd.size(); i++)
            a.push_back(odd[i] - a.back());
    }else{
        m = min(n, 26);
        bool found = false;

        for(int sz = 1; sz <= m / 2; sz++){
            mp.clear();
            if(rec(0, sz, 0, 0)){
                vector <int> v, w;
                for(int i = 0; i < m; i++){
                    if(mask1 & (1 << i))v.push_back(b[i]);
                    if(mask2 & (1 << i))w.push_back(b[i]);
                }
                
                a.push_back(0);
                for(int i = 0; i < sz - 1; i++){
                    a.push_back(v[i] - a.back());
                    a.push_back(w[i] - a.back());
                }
                a.push_back(v[sz - 1] - a.back());

                for(int i = 0; i < n; i++){
                    if(i < m){
                        if(mask1 & (1 << i))continue;
                        if(mask2 & (1 << i))continue;
                        a.push_back(b[i] - a.back());
                    }else{
                        a.push_back(b[i] - a.back());
                    }
                }

                found = true;
                break;
            }
        }

        if(!found){
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}