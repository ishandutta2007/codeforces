#include<bits/stdc++.h>
using namespace std;

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    if (!v.size()) 
        os<<"]"; 
    else
        for (int i=0;i<v.size();++i)
            os<<v[i]<<",]"[i==v.size()-1];
    return os;
}

void printr(ostream& os){os<<endl;}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t<<" ";
	printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
	os<<t; if (sizeof...(args)) os<<", ";
	dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed

         
typedef long long LL;

#define maxn 200052
#define maxc 26

int n,m;
map<int,int> G[maxn];

LL even,odd;

int main()  {
    read(n,m);
    while (m--) {
        char op,c;
        int u,v,k;
        read(op);
        // dbg(op);
        if (op=='+')  {
            read(u,v,c),c-='a';
            if (G[v].count(u))  {
                ++even;
                if (G[v][u]==c)
                    ++odd;
            }
            G[u][v]=c;
        } else
        if (op=='-')    {
            read(u,v);
            if (G[v].count(u))  {
                --even;
                if (G[v][u]==G[u][v])
                    --odd;
            }
            G[u].erase(v);
        } else
        if (op=='?')    {
            read(k);
            if (k&1)
                print(even?"YES":"NO");
            else
                print(odd?"YES":"NO");
        } else assert(0);
        // dbg(odd,even);
    }
    return 0;
}