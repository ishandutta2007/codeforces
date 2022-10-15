#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef VInt::iterator VIter;
typedef pair<int, int> PInt;
typedef vector<PInt> VPInt;
typedef vector<VPInt> VVPInt;
typedef VPInt::iterator VPIter;

VVInt graph, g, g1;
VInt colors, parents, enter, leave, low, bcc;
int myTime = 0;
int newIndex = 0;

/*
 *   ,   enter, leave  low
 */
void visitLow(int u, const VVInt& graph) {
   colors[u] = 1;
   low[u] = enter[u] = ++myTime;
   
   for(auto it = graph[u].begin(); it != graph[u].end(); it++)
      if(colors[*it] == 0) {
         parents[*it] = u;
         visitLow(*it, graph);
         low[u] = min(low[u], low[*it]);
      } else if(colors[*it] == 1 && *it != parents[u]) {
         low[u] = min(low[u], enter[*it]);
      }
   
   colors[u] = 2;
   leave[u] = ++myTime;      
}

/*
 *    ,   bcc
 */
void visitBCC(int u) {
   for(VIter it = graph[u].begin(); it != graph[u].end(); it++)
      if(parents[*it] == u) {
         bcc[*it] = (low[*it] < enter[u]) ? bcc[u] :         //    
                    (low[*it] > enter[u]) ? -1 :             //    
                    (newIndex++);                            //      
         visitBCC(*it);         
      }
}

/*
 *   BCC,   ,  -1,   
 * (u, v)    ,      
 */
 int getBCC(int u, int v) {
    return bcc[(enter[u] > enter[v]) ? u : v];
 }

/*
 *  :  n  m,  m  
 *  :  ,      
 */
int main() {
std::ios::sync_with_stdio(false); std::cin.tie(0);
   int R, C, i;
   cin >> R >> C;
   vs s(R);
   for (int i = 0; i < R; ++i) cin >> s[i];
   int n = R * C;
   graph.resize(n);
   g.resize(n);
   g1.resize(n);
   for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) if (s[i][j] == '.') {
     int v = i * C + j;
     if (i + 1 < R && s[i + 1][j] == '.') {
       int v1 = (i + 1) * C + j;
       g[v].push_back(v1);
       g1[v1].push_back(v);
     }
     if (j + 1 < C && s[i][j + 1] == '.') {
       int v1 = i * C + j + 1;
       g[v].push_back(v1);
       g1[v1].push_back(v);
     }
   }
   
   enter.resize(n);
   leave.resize(n);
   low.resize(n);
   vi was(n, 1);
   int res = 2;

   colors.assign(n, 0);
   parents.assign(n, -1);
   visitLow(0, g);
   if (colors[n - 1] == 0) res = 0;
   for (int i = 0; i < n; ++i) if (!colors[i]) was[i] = 0;
   
   colors.assign(n, 0);
   parents.assign(n, -1);
   visitLow(n-1, g1);
   for (int i = 0; i < n; ++i) if (!colors[i]) was[i] = 0;

   for (int i = 0; i < n; ++i) for (int j : g[i]) if (was[i] && was[j]) {
    graph[i].push_back(j);
    graph[j].push_back(i);
   }

   myTime = 0;   
   colors.assign(n, 0);
   parents.assign(n, -1);
   for (i = 0; i < n; i++) {
      if (colors[i] == 0) {
         visitLow(i, graph);
      }
   }
         
   //    (  bcc)
   //    " " ,
   //       
   bcc.assign(n, -1);
   for(i = 0; i < n; i++)
      if(parents[i] == -1)
         visitBCC(i);   
   
   //  
   VPInt bridges;
   VVPInt comps(newIndex);
   for(i = 0; i < n; i++)
      for(VIter it = graph[i].begin(); it != graph[i].end(); it++)
         if(i < *it) {
            int id = getBCC(i, *it);
            ((id == -1) ? bridges : comps[id]).push_back(PInt(i, *it));
         }

   vi comp_num(n, -1);
   for(i = 0; i < newIndex; i++) {
      for(VPIter edge = comps[i].begin(); edge != comps[i].end(); edge++)
         comp_num[edge->first] = comp_num[edge->second] = i;
   }

   if (comp_num[0] != comp_num[n - 1] || comp_num[0] == -1) res = min(res, 1);

   cout << res << endl;
}