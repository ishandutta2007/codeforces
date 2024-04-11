#include <bits/stdc++.h>
using namespace std;

int solve(const vector <int>& a, const vector <int>& b){
    if(a.empty() || b.empty())return 0;
    
    /*cout << "a ::: ";
    for(int x : a)
        cout << x << ' ';
    cout << endl;

    cout << "b ::: ";
    for(int x : b)
        cout << x << ' ';
    cout << endl;*/

    int cur = 0;
    for(int i = 1; i < (int)a.size(); i++){
        cur += binary_search(b.begin(), b.end(), a[i]);
    }

    int ret = cur;

    int i = 0, L = a[0], R = a[0], l = 0, r = 0;
    while(L <= b.back()){
        if(i + 1 < (int)a.size() && a[i + 1] == R + 1){
            cur -= binary_search(b.begin(), b.end(), a[i + 1]);
            i++;
            R++;
            continue;
        }

        while(r < (int)b.size() && b[r] <= R)r++;
        while(l < (int)b.size() && b[l] < L)l++;

        //cout << i << ',' << L << ',' << R << ' ' << l << ',' << r << ' ' << cur << endl;;

        int nxt = -1;
        if(l < (int)b.size()){
            if(b[l] == L)nxt = 1;
            else nxt = nxt == -1 ? b[l] - L : min(nxt, b[l] - L);
        }
        if(r < (int)b.size()){
            if(r > 0 && b[r - 1] == R)nxt = 1;
            else nxt = nxt == -1 ? b[r] - R : min(nxt, b[r] - R);
        }
        if(i + 1 < (int)a.size()){
            nxt = nxt == -1 ? a[i + 1] - R - 1 : min(nxt, a[i + 1] - R - 1);
        }
        
        ret = max(ret, cur + r - l);
        if(nxt == -1){
            L++;
            R++;
        }else{
            L += nxt;
            R += nxt;
        }
    }

    //cout << "ret :: " << ret << endl;
    
    return ret;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        vector <int> a_neg, a_pos;
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);

            if(a < 0)a_neg.push_back(-a);
            else a_pos.push_back(a);
        }

        vector <int> b_neg, b_pos;
        for(int i = 0; i < m; i++){
            int b;
            scanf("%d", &b);

            if(b < 0)b_neg.push_back(-b);
            else b_pos.push_back(b);
        }

        reverse(a_neg.begin(), a_neg.end());
        reverse(b_neg.begin(), b_neg.end());

        printf("%d\n", solve(a_neg, b_neg) + solve(a_pos, b_pos));
    }
    return 0;
}