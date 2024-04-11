#include <bits/stdc++.h>
using namespace std;
int n, m;
pair <int, int> p[300000];
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
vector <int> uni(vector <int> x, vector <int> y){
    vector <int> res;
    for(auto a: x) for(auto b: y) if(a==b) res.push_back(a);
    return res;
}
void test(){
    if(m<=2){
        puts("YES");
        exit(0);
    }
    int pa=rng()%m;
    int pb=rng()%m;
    while(pa==pb){
        pa=rng()%m;
        pb=rng()%m;
    }
    int firstnum=-1;
    if((p[pa].first==p[pb].first)||(p[pa].first==p[pb].second)) firstnum=p[pa].first;
    else if((p[pa].second==p[pb].first)||(p[pa].second==p[pb].second)) firstnum=p[pa].second;
    if(firstnum==-1) return;
    vector <int> now;
    for(int i=0; i<m; i++) if(p[i].first==firstnum||p[i].second==firstnum) continue;
    else{
        if(now.empty()){
            now.push_back(p[i].first);
            now.push_back(p[i].second);
        }
        else{
            vector <int> temp;
            temp.push_back(p[i].first);
            temp.push_back(p[i].second);
            now=uni(now, temp);
            if(now.empty()) return;
        }
    }
    puts("YES");
    exit(0);
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>p[i].first>>p[i].second;
        if(p[i].first>p[i].second) swap(p[i].first, p[i].second);
    }
    sort(p, p+m);
    m=unique(p, p+m)-p;
    for(int i=0; i<20; i++) test();
    puts("NO");
}