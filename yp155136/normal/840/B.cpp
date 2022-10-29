#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 6e5 + 6;

int d[MAX_N];

struct DisjointSet {
    int p[MAX_N];
    void init() {
        for (int i=0;MAX_N>i;i++) p[i]=i;
    }
    int Find(int x) {
        return p[x]==x?x:p[x]=Find(p[x]);
    }
    void Union(int x,int y) {
        p[Find(x)] = Find(y);
    }
} djs;

vector<int> edg[MAX_N];

int stamp=0;

int pin[MAX_N],pout[MAX_N];
pii get_stamp[MAX_N];
bool cha[MAX_N];
int par[MAX_N];

void dfs(int id,int p) {
    //cout<<"id = "<<id<<" ,p  = "<<p<<endl;
    stamp++;
    pin[id] = stamp;
    par[id] = p;
    get_stamp[stamp] = make_pair(id,1);
    for (int i:edg[id]) {
        if (i!=p) dfs(i,id);
    }
    stamp++;
    pout[id] = stamp;
    get_stamp[stamp] = make_pair(id,0);
    //cout<<"pin["<<id<<"] = "<<pin[id]<<" , pout["<<id<<"] = "<<pout[id]<<endl;
}

bool deg[MAX_N];
bool edge[MAX_N];

int main () {
    map<pii,int> mp;
    int n,m;
    scanf("%d %d",&n,&m);
    int magic = -1;
    for (int i=1;n>=i;i++) {
        scanf("%d",&d[i]);
        if (d[i] == -1) {
            magic = i;
        }
    }
    djs.init();
    for (int i=0;m>i;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        if (djs.Find(x) != djs.Find(y)) {
            djs.Union(x,y);
            edg[x].push_back(y);
            edg[y].push_back(x);
            deg[x] ^= 1;
            deg[y] ^= 1;
            edge[i+1] = 1;
        }
        mp[make_pair(x,y)] = i+1;
        mp[make_pair(y,x)] = i+1;
    }
    dfs(1,1);
    for (int i=1;n>=i;i++) {
        if (d[i] == -1) continue;
        if (d[i] == deg[i]) continue;
        if (magic == -1) {
            int ffind=-1;
            for (int j=i+1;n>=j;j++) {
                if (d[j] == -1) continue;
                if (d[j] != deg[j]) {
                    ffind=j;
                    break;
                }
            }
            if (ffind == -1) {
                puts("-1");
                return 0;
            }
            if (pout[i] > pout[ffind]) {
                cha[pout[ffind]] ^= 1;
                cha[pout[i]] ^= 1;
            }
            else {
                cha[pout[i]] ^= 1;
                cha[pout[ffind]] ^= 1;
            }
            i=ffind;
        }
        else {
            //cout<<"i = "<<i<<" , magic = "<<magic<<endl;
            int ffind= magic;
            //cout<<"pout["<<i<<"] = "<<pout[i]<<" , pout["<<ffind<<"] = "<<pout[ffind]<<endl;
            if (pout[i] > pout[ffind]) {
                cha[pout[ffind]] ^= 1;
                cha[pout[i]] ^= 1;
            }
            else {
                cha[pout[i]] ^= 1;
                cha[pout[ffind]] ^= 1;
            }
        }
    }
    bool pre = false;
    for (int i=1;2*n-1>=i;i++) {
        pre ^= cha[i];
        edge[mp[make_pair(get_stamp[i].first,get_stamp[i+1].first)]] ^= pre;
    }
    int cnt=0;
    for (int i=1;m>=i;i++) {
        cnt += edge[i];
    }
    printf("%d\n",cnt);
    for (int i=1;m>=i;i++) {
        if (edge[i]) printf("%d\n",i);
    }
}