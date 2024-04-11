#include <bits/stdc++.h>
using namespace std;
class node{
public:
  using pointer=node*;
  pointer next, prev, inv;
  int value;
  node(int value): value(value), next(nullptr), prev(nullptr), inv(nullptr){}
  void unlink(){
    if(prev!=nullptr) prev->next=next;
    if(next!=nullptr) next->prev=prev;
    prev=next=nullptr;
  }
};
bool cmp(node::pointer A, node::pointer B){
  return A->value<B->value;
}
node::pointer px[100000];
node::pointer py[100000];
node::pointer temp[100000];
void build(node::pointer* first, node::pointer* last){
  sort(first, last, cmp);
  node::pointer* prev=nullptr;
  for(auto p=first; p!=last; p++){
    if(prev!=nullptr){
      (*prev)->next=(*p);
      (*p)->prev=(*prev);    
    }
    prev=p;
  }
}
int ans=0;
void solve(node::pointer xb, node::pointer xe, node::pointer yb, node::pointer ye){
  ans++;
  while(xb!=xe){
      auto l=xb;
      auto r=xe;
      auto u=yb;
      auto d=ye;
      while(true){
        if((l->next->value)-(l->value)>1){
          while(yb->inv->value<=l->value) yb=yb->next;
          while(ye->inv->value<=l->value) ye=ye->prev;
          int sz=0;
          for(auto i=xb; i!=l->next; i=i->next){
            i->inv->unlink();
            temp[sz++]=i->inv;
          }
          build(temp, temp+sz);
          auto old=xb;
          xb=l->next;
          xb->prev=nullptr;
          l->next=nullptr;
          solve(old, l, temp[0], temp[sz-1]);
          break;
        }
        else if((r->value)-(r->prev->value)>1){
          while(yb->inv->value>=r->value) yb=yb->next;
          while(ye->inv->value>=r->value) ye=ye->prev;
          int sz=0;
          for(auto i=r; i!=nullptr; i=i->next){
            i->inv->unlink();
            temp[sz++]=i->inv;
          }
          build(temp, temp+sz);
          auto old=xe;
          xe=r->prev;
          xe->next=nullptr;
          r->prev=nullptr;
          solve(r, old, temp[0], temp[sz-1]);
          break;
        }
        else if((d->value)-(d->prev->value)>1){
          while(xb->inv->value>=d->value) xb=xb->next;
          while(xe->inv->value>=d->value) xe=xe->prev;
          int sz=0;
          for(auto i=d; i!=nullptr; i=i->next){
            i->inv->unlink();
            temp[sz++]=i->inv;
          }
          build(temp, temp+sz);
          auto old=ye;
          ye=d->prev;
          ye->next=nullptr;
          d->prev=nullptr;
          solve(d, old, temp[0], temp[sz-1]);
          break;
        }
        else if((u->next->value)-(u->value)>1){
          while(xb->inv->value<=u->value) xb=xb->next;
          while(xe->inv->value<=u->value) xe=xe->prev;
          int sz=0;
          for(auto i=yb; i!=u->next; i=i->next){
            i->inv->unlink();
            temp[sz++]=i->inv;
          }
          build(temp, temp+sz);
          auto old=yb;
          yb=u->next;
          yb->prev=nullptr;
          u->next=nullptr;
          solve(old, u, temp[0], temp[sz-1]);
          break;
        }
        else{
          l=l->next;
          r=r->prev;
          u=u->next;
          d=d->prev;
          if((l->value>=r->value)&&(u->value>=d->value)) return;//can't cut anymore
        }
      }
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0, x, y; i<n; i++){
    cin>>x>>y;
    px[i]=new node(x);
    py[i]=new node(y);
    px[i]->inv=py[i];
    py[i]->inv=px[i];
  }
  build(px, px+n);
  build(py, py+n);
  solve(px[0], px[n-1], py[0], py[n-1]);
  cout<<ans<<'\n';
}