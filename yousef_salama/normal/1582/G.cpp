#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1000005;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <int> low(MAXM, -1);
    vector <int> ind(MAXM, -1);
    int nprimes = 0;
    
    for(int i = 2; i < MAXM; i++){
        if(low[i] != -1)continue;
        
        low[i] = i;
        ind[i] = nprimes++;

        for(int j = i + i; j < MAXM; j += i)
            if(low[j] == -1)low[j] = i;
    }

    int n;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    string b;
    cin >> b;

    set <int> s;
    long long res = 0;

    vector < stack < pair <int, int> > > stk(nprimes);
    vector <int> cnt(nprimes, 0);

    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            s.insert(i);
            res += (int)s.size();

            continue;
        }

        int x = a[i];
        vector <int> v;
        while(x > 1){
            v.push_back(ind[low[x]]);
            x /= low[x];
        }

        if(b[i] == '*'){
            s.insert(i);
            res += (int)s.size();

            for(int j = 0; j < (int)v.size(); ){
                int k = j;
                while(k < (int)v.size() && v[k] == v[j])k++;

                stk[v[j]].push(make_pair(cnt[v[j]], i));
                cnt[v[j]] += k - j;

                j = k;
            }
        }else{
            for(int j = 0; j < (int)v.size(); ){
                int k = j;
                while(k < (int)v.size() && v[k] == v[j])k++;

                cnt[v[j]] -= k - j;
                while(!stk[v[j]].empty() && stk[v[j]].top().first > cnt[v[j]])
                    stk[v[j]].pop();

                if(stk[v[j]].empty()){
                    s.clear();
                }else{
                    while(true){
                        auto d = s.upper_bound(stk[v[j]].top().second);
                        if(d == s.end())break;
                        s.erase(d);
                    }
                }
                
                j = k;
            }

            res += (int)s.size();
        }
    }
    cout << res << '\n';

    return 0;
}