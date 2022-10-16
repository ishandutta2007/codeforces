#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stack>
using namespace std;
string s, a;
string cmt[1000001];
stack <pair<int, int> > st;
vector <int> adj[1000001];
int high[1000001];
vector <int> ans[1000001];
int n=0;
int highmax;
void dfs(int u){
    for(int i=0; i<adj[u].size(); i++){
        high[adj[u][i]]=high[u]+1;
        dfs(adj[u][i]);
    }
}
int main(){
//    freopen("E.INP", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]==',')
            s[i]=' ';
    }
    stringstream ss(s);
    st.push(make_pair(0, 1000000));
    while(true){
        string a;
        int temp;
        ss>>cmt[++n];
        if(cmt[n]==""){
            n--;
            break;
        }
        ss>>temp;
        adj[st.top().first].push_back(n);
        st.top().second--;
        if(st.top().second==0) st.pop();
        if(temp>0) st.push(make_pair(n, temp));
    }
    dfs(0);
    for(int i=1; i<=n; i++){
        ans[high[i]].push_back(i);
        highmax=max(highmax, high[i]);
    }
    cout<<highmax<<'\n';
    for(int i=1; i<=highmax; i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<cmt[ans[i][j]]<<' ';
        }
        cout<<'\n';
    }
}