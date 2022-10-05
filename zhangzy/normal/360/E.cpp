#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct R{
  int to,nex,val;
}r[10100];
int hea[10100],n,m,k,s1,s2,t,x,y,z,cnt=0,fr[110],id[110],l[110];
ll d1[10100],d2[10100],dd;

void out(string s){
  cout<<s<<endl;
  for (int i=k;i--;) cout<<r[id[i]].val<<' ';
  exit(0);
}

queue<int>q; int in[10100];
void spf(int s,int t,ll d[]){
  for (int i=1;i<=n;++i) d[i]=1e16, in[i]=0;
  d[s]=0; for (;!q.empty();q.pop());
  for (q.push(s);!q.empty();q.pop()){
    x=q.front(); in[x]=0;
    for (int i=hea[x];i;i=r[i].nex){
      y=r[i].to; dd=d[x]+r[i].val;
      if (dd<d[y]){
	d[y]=dd;
	if (!in[y]++) q.push(y);
      }
    }
  }
}

int main(){
  cin>>n>>m>>k>>s1>>s2>>t;
  for (int i=m;i--;)
    cin>>x>>y>>z, r[++cnt]=(R){y,hea[x],z}, hea[x]=cnt;
  for (int i=k;i--;)
    cin>>x>>y>>l[i]>>z, r[id[i]=++cnt]=(R){y,hea[x],z}, hea[fr[i]=x]=cnt;
  for (int fl=1;fl;){
    fl=0;
    spf(s1,t,d1); spf(s2,t,d2);
    if (d1[t]<d2[t]) out("WIN");
    for (int i=k;i--;)
      if (d1[fr[i]]<d2[fr[i]]&&r[id[i]].val-l[i]){
	r[id[i]].val=l[i]; fl=1;
      }
    if (fl) continue;
    for (int i=k;i--;)
      if (d1[fr[i]]<=d2[fr[i]]&&r[id[i]].val-l[i]){
	r[id[i]].val=l[i]; fl=1;
      }
  }
  spf(s1,t,d1); spf(s2,t,d2);
  if (d1[t]==d2[t]) out("DRAW");
  puts("LOSE");
}