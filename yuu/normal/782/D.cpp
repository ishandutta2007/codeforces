#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
pair <string, string> t[1001];
string str;
vector <int> adj[1001];
bool done[1001];
string ans[1001];
set <string> s;
vector <int> ins, outs, temp;
int n;
void dfs(int u){
    done[u]=1;
    if(s.find(t[u].second)!=s.end()){
        cout<<"NO";
        exit(0);
    }
    ans[u]=t[u].second;
    s.insert(t[u].second);
    for(int v: adj[u])
        if(!done[v])
            dfs(v);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>n;
    FOR(i, 1, n){
        cin>>str;
        t[i].first=t[i].first+str[0]+str[1]+str[2];
        cin>>str;
        t[i].second=t[i].first;
        t[i].second[2]=str[0];
    }
    FOR(i, 1, n){
        FOR(j, i+1, n){
            if(t[i].first==t[j].first){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    FOR(i, 1, n)
        if((!done[i])&&(!adj[i].empty()))
            dfs(i);
    //OK;
    FOR(i, 1, n)
        if(!done[i])
            outs.push_back(i);
    while(!outs.empty()){
        ins.clear();
        while(!outs.empty()){
            if(s.find(t[outs.back()].first)!=s.end())
                ins.push_back(outs.back());
            else
                temp.push_back(outs.back());
            outs.pop_back();
        }
        if(ins.empty()){
            while(!temp.empty()){
                ans[temp.back()]=t[temp.back()].first;
                temp.pop_back();
            }
            break;
        }
        else{
            while(!ins.empty()){
                if(s.find(t[ins.back()].second)!=s.end()){
                    cout<<"NO";
                    exit(0);
                }
                else{
                    ans[ins.back()]=t[ins.back()].second;
                    s.insert(t[ins.back()].second);
                    ins.pop_back();
                }
            }
            outs=temp;
            temp.clear();
        }
    }
    cout<<"YES\n";
    FOR(i, 1, n)
        cout<<ans[i]<<'\n';
}