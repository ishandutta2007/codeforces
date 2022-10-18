#include <bits/stdc++.h>
using namespace std;

struct yasser{
    set < pair <int, int> > s;
    
    yasser(){}
    
    bool empty(){
        return s.empty();
    }

    bool query(int a, int b){
        auto d = s.lower_bound(make_pair(a, 0));
        if(d == s.end())return false;
        return (d->second < b);
    }

    void add(int a, int b){
        auto d = s.lower_bound(make_pair(a, 0));
        if(d != s.end() && (d->second <= b))return;

        while(true){
            auto d = s.lower_bound(make_pair(a, 1 << 20));
            if(d == s.begin())break;
            d--;

            if(d->second < b)break;
            s.erase(d);
        }
        s.insert(make_pair(a, b));
    }
};

int main(){
    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector <yasser> d(n + 1);
    d[0].add(0, 0);

    for(int i = 0; i < n; i++){
        if(a[i] <= i + 1){
            int L = 0, R = i;
            while(L < R){
                int mid = (L + R + 1) / 2;
                if(d[mid].query(a[i] - i - 1, a[i]))L = mid;
                else R = mid - 1;
            }
            d[L + 1].add(a[i] - i - 1, a[i]);
        }

        /*
        cout << i << ',' << a[i] << " ::: " << endl;
        for(int j = 0; j <= n; j++){
            cout << j << " ===> ";
            for(auto p : d[j].s)
                cout << p.first << ',' << p.second << ' ';
            cout << endl;
        }
        cout << "------------" << endl;
        */
    }

    int mx = 0;
    for(int i = 1; i <= n; i++)
        if(!d[i].empty())mx = max(mx, i);
    
    printf("%d\n", mx);

    return 0;
}