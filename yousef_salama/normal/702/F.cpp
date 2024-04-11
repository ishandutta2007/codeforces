#include <bits/stdc++.h>
using namespace std;

struct customer{
    int index, money, shirts_cnt;
    customer(){}
    customer(int index, int money, int shirts_cnt): index(index), money(money), shirts_cnt(shirts_cnt){}
    
    bool operator <(const customer& c) const{
        if(money != c.money)return money < c.money;
        else return index < c.index;
    }
};

struct yasser{
    vector < set <customer> > v;
    vector <int> money_added, shirts_added;

    yasser(){
        v = vector < set <customer> > (31);
        money_added = vector <int> (31, 0);
        shirts_added = vector <int> (31, 0);
    }
    
    void add(int index, int money){
        int i = 32 - __builtin_clz(money);
        v[i].insert(customer(index, money, 0));
    }

    void update(int price){
        int i = 32 - __builtin_clz(price);
        
        while(!v[i].empty() && prev(v[i].end())->money + money_added[i] >= price){
            auto d = prev(v[i].end());

            int nxt = d->money + money_added[i] - price;
            int j = (nxt == 0 ? 0 : 32 - __builtin_clz(nxt));

            v[j].insert(customer(d->index, nxt - money_added[j], d->shirts_cnt + shirts_added[i] - shirts_added[j] + 1));
            v[i].erase(d);
        }

        for(int j = i + 1; j < 31; j++){
            money_added[j] -= price;
            shirts_added[j]++;

            int mn = (j == 0 ? 0 : (1 << (j - 1)));
            while(!v[j].empty() && v[j].begin()->money + money_added[j] < mn){
                int nxt = v[j].begin()->money + money_added[j];
                int k = (nxt == 0 ? 0 : 32 - __builtin_clz(nxt));

                v[k].insert(customer(v[j].begin()->index, nxt - money_added[k], v[j].begin()->shirts_cnt + shirts_added[j] - shirts_added[k]));
                v[j].erase(v[j].begin());
            }
        }
    }

    void fill(vector <int>& res){
        for(int i = 0; i < 31; i++)
        for(customer c : v[i])
            res[c.index] = c.shirts_cnt + shirts_added[i];
    }
};

int main(){
    int n;
    scanf("%d", &n);

    vector < pair <int, int> > tshirts(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &tshirts[i].first, &tshirts[i].second);

    sort(tshirts.begin(), tshirts.end(), [](const pair <int, int>& a, const pair <int, int>& b){
        if(a.second != b.second)return a.second > b.second;
        else return a.first < b.first;
    });

    int k;
    scanf("%d", &k);

    yasser y;

    for(int i = 0; i < k; i++){
        int b;
        scanf("%d", &b);

        y.add(i, b);
    }

    for(int i = 0; i < n; i++)
        y.update(tshirts[i].first);

    vector <int> res(k, -1);
    y.fill(res);

    for(int i = 0; i < k; i++){
        if(i > 0)printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");

    return 0;
}