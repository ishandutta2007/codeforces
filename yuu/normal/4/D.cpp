#include<bits/stdc++.h>
using namespace std;
int main () {
int n, a, b;
int h[5001],w[5001],f[5001];
cin>>n>>h[0]>>w[0];
f[0]=0;
vector<int> order;
order.emplace_back(0);
for (int i=1; i<= n; i++) {
cin>>h[i]>>w[i]; 
f[i]=-1e9; 
order.emplace_back(i);
}
sort( order.begin(), order.end(), [h](int a, int b){return h[a]<h[b];});
for(int i: order)
for (int j: order)
{
if (h[i]>h[j]&&w[i]>w[j]) f[i] = max(f[i], f[j]+1);
}
int id = max_element(f, f+n+1) - f;
cout << f[id]<<'\n';
deque<int> ans;
while(id){
ans.push_front(id);
for(int i: order) {
if (w[i]>=w[id]) continue;
if(f[i]+1==f[id]){
id =i; break;
}

}
}
for(int x: ans) cout<< x<<' ';

}