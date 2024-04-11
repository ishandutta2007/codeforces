#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int t[200009];
int p[200009];
int hol[200009];
int last[200009];
int jobb[200009];
vector<char> answer;
vector<int> G[200009];
vector<int> st;
void dfs(int x)
{
    st.push_back(x);
    if(st.size()>n)
    {
        jobb[st.back()]=st[st.size()-n];
    }
    for(int sz: G[x])
    {
        dfs(sz);
    }
    st.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
        hol[p[i]]=i;
        last[i]=m+1;
    }
    p[0]=p[n];
    p[n+1]=p[1];
    for(int i=1; i<=m; i++)
    {
        cin>>t[i];
    }
    for(int i=m; i>=1; i--)
    {
        G[last[p[hol[t[i]]+1]]].push_back(i);
        last[t[i]]=i;
        jobb[i]=m+1;
    }
    jobb[m+1]=m+1;
    dfs(m+1);
    for(int i=m; i>=1; i--)
    {
        jobb[i]=min(jobb[i], jobb[i+1]);
    }
    for(int i=1; i<=q; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        if(n==1 || bb>=jobb[aa])
        {
            answer.push_back('1');
        }
        else answer.push_back('0');
    }
    for(char ccc: answer)
    {
        cout<<ccc;
    }
    cout<<endl;

    return 0;
}