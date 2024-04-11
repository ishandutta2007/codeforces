#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
multiset <pair <ll, ll>> s;
class frog{
public:
    ll x, t;
    int c, id, pos;
    void input(int id){
        cin>>x>>t;
        this->id=id;
        c=0;
    }
    void setup(int i){
        pos=i;
    }
} f[200001];
class segmentSet: public set<pair <pair <ll, ll>, int>>{
public:
#define left first.first
#define right first.second
#define id second
    void add(pair <pair <ll, ll>, int> p){
        while(true){
            auto it=upper_bound(p);
            if(it==end()){
                insert(p);
                return;
            }
            if(it->right<=p.right) erase(it);
            else if(it->left>p.right){
                insert(p);
                return;
            }
            else{
                auto temp=*it;
                erase(it);
                temp.left=p.right;
                insert(temp);
                //you can modify it in theory without messing with the order but elements in set are immutable 
                insert(p);
                return;
            }
        }
    }
    void feed(ll p){
        pair <pair <ll, ll>, int> fr;
        {
            auto it=lower_bound({{p, -1e18}, 0});
            if(it==end()) it=find(*rbegin());
            else if(it!=begin()){
                auto temp=prev(it);
                if(temp->right>=p) it=temp;
            }
            if((it->left<=p)&&(it->right>=p)){
                fr=*it;
                erase(it);
            }
            else return;
        }
        while(!s.empty()){
            if(s.rbegin()->first<fr.left) break;
            auto it=s.lower_bound({fr.left, -1});
            if(it->first>fr.right) break;
            f[fr.id].c++;
            f[fr.id].t+=it->second;
            fr.right+=it->second;
            s.erase(it);
        }
        add(fr);
    }
#undef left
#undef right
#undef id
} fS;
int n, m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) f[i].input(i);
    sort(f+1, f+n+1, [](frog A, frog B){
        return A.x<B.x;
    });
    for(int i=n; i>=1; i--){
        f[i].setup(i);
        fS.add({{f[i].x, f[i].x+f[i].t}, f[i].pos});
    }
    {
        ll p, b;
        for(int i=1; i<=m; i++){
            cin>>p>>b;
            s.insert({p, b});
            fS.feed(p);
        }
    }
    sort(f+1, f+n+1, [](frog A, frog B){
        return A.id<B.id;
    });
    for(int i=1; i<=n; i++) cout<<f[i].c<<' '<<f[i].t<<'\n';
}