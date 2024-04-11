#include <bits/stdc++.h>
using namespace std;

struct event{
    long long a, b, t;
    event(long long a, long long b, long long t): a(a), b(b), t(t){}

    bool operator <(const event& e) const{
        return a < e.a;
    }
};

int main(){
    int n;
    scanf("%d", &n);
    
    vector <event> evs;
    multiset <long long> p;
    
    for(int i = 0; i < n; i++){
        long long a, b, t;
        scanf("%lld %lld %lld", &a, &b, &t);
    
        evs.push_back(event(a, b, t));
        p.insert(a + t);
    }
    sort(evs.begin(), evs.end());

    int i = 0;
    long long cur_time = 0, num_swords = 0;
    multiset < pair <long long, long long> > s;
    
    while(cur_time < (1LL << 61)){
        while(i < (int)evs.size() && evs[i].a <= cur_time){
            s.insert(make_pair(evs[i].t, evs[i].b));
            p.erase(p.lower_bound(evs[i].a + evs[i].t));
            
            i++;
        }

        while(!s.empty() && cur_time + s.begin()->first > s.begin()->second)
            s.erase(s.begin());

        long long nxt_event = i == (int)evs.size() ? 1LL << 61 : evs[i].a;

        if(s.empty() || cur_time + s.begin()->first > nxt_event){
            long long nxt_time = 1LL << 61;
            if(!s.empty())nxt_time = min(nxt_time, cur_time + s.begin()->first);
            if(!p.empty())nxt_time = min(nxt_time, *p.begin());
            
            if(nxt_time < (1LL << 61))num_swords++;
            cur_time = nxt_time;
        }else{
            long long cur_swords = (min(nxt_event, s.begin()->second) - cur_time) / s.begin()->first;
            num_swords += cur_swords;
            cur_time += cur_swords * s.begin()->first;
        }
    }
    printf("%lld\n", num_swords);

    return 0;
}