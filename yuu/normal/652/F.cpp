#include <bits/stdc++.h>
using namespace std;
#define love long
#define live long
int n;
love live m, t;
bool have_char[256];
class ant{
public:
  love live s;
  int d, id;
  void input(int id){
    this->id=id;
    cin>>s;
    char c;
    cin>>c;
    have_char[c]=1;
    if(c=='L') d=-1;
    else d=+1;
  }
  love live at(love live time){
    love live res=(s+time*d)%m;
    if(res<=0) res+=m;
    return res;
  }
  void move(love live time){
    (s+=time*d)%=m;
    if(s<=0) s+=m;
  }
};
love live dist_cw(love live a, love live b){
  (a-=b)%=m;
  if(a<0) a+=m;
  return a;
}
deque <ant> a;
love live get_pos_after_time(int index, love live t){
  deque <ant> pos, neg;
  for(int i=(index+1)%n; ; (i+=1)%=n){
    if(a[i].d<0) neg.push_back(a[i]);
    if(i==index) break;
  }
  for(int i=(index+n-1)%n; ; (i+=n-1)%=n){
    if(a[i].d>0) pos.push_back(a[i]);
    if(i==index) break;
  }
  ant A=a[index];
  love live now=0;
  while(t>0){
    love live dist;
    if(A.d<0){
      dist=dist_cw(A.s, pos.front().at(now));
      pos.push_back(pos.front());
      pos.pop_front();
      if((dist==0)&&(pos.size()==1)) dist=m;
    }
    else{
      dist=dist_cw(neg.front().at(now), A.s);
      neg.push_back(neg.front());
      neg.pop_front();
      if((dist==0)&&(neg.size()==1)) dist=m;
    }
    if(t*2<=dist){
      A.move(t);
      return A.s;
    }
    else{
      A.move(dist/2);
      A.d=-A.d;
      now+=(dist+1)/2;
      t-=(dist+1)/2;
    }
  }
  return A.s;
}
void reduce_time(){
  love live pos_0=get_pos_after_time(0, m);
  int index_0;
  for(int i=0; i<n; i++) if(a[i].at(m)==pos_0){
    index_0=i;
    break;
  }
  vector <int> path;
  path.push_back(0);
  do{
    path.push_back((path.back()+index_0)%n);
  }
  while(path.back()!=0);
  path.pop_back();
  love live remainder=t%m;
  (t/=m)%=path.size();
  deque <love live> index;
  for(int i=0; i<n; i++) index.push_back(a[i].id);
  for(int i=0; i<path[t]; i++){
    a.push_back(a.front());
    a.pop_front();
  }
  for(int i=0; i<n; i++) a[i].id=index[i];
  t=remainder;
}
love live ans[300000];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>n>>m>>t;
  a.resize(n);
  for(int i=0; i<n; i++) a[i].input(i);
  deque <love live> end_poses;
  for(int i=0; i<n; i++) end_poses.push_back(a[i].at(t));
  sort(end_poses.begin(), end_poses.end());
  if(!(have_char['L']&&have_char['R'])){
    for(int i=0; i<n; i++) cout<<a[i].at(t)<<" \n"[i+1==n];
    return 0;
  }
  sort(a.begin(), a.end(), [](ant A, ant B){
    return A.s<B.s;
  });
  reduce_time();
  love live end_pos_0=get_pos_after_time(0, t);
  love live end_pos_1=get_pos_after_time(1, t);
  while((end_poses[0]!=end_pos_0)||(end_poses[1]!=end_pos_1)){
    end_poses.push_back(end_poses.front());
    end_poses.pop_front();
  }
  for(int i=0; i<n; i++) ans[a[i].id]=end_poses[i];
  for(int i=0; i<n; i++) cout<<ans[i]<<" \n"[i+1==n];
}