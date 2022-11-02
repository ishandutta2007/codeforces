#include <iostream>
#include <set>
using namespace std;
set<int> hori;
set<int> veri;
set<int> hertek;
set<int> vertek;
int hhany[200005];
int vhany[200005];
char c[200005];
int akt[200005];
int w, h, n;
int main()
{
   cin>>w>>h>>n;
   for(int i=0; i<=w; i++)
   {
       vhany[i]=0;
   }
    for(int i=0; i<=h; i++)
   {
       hhany[i]=0;
   }
   vhany[w]=1;
   hhany[h]=1;
   hori.insert(0);
   hori.insert(h);
   veri.insert(0);
   veri.insert(w);
   hertek.insert(h);
   vertek.insert(w);
for(int i=1; i<=n; i++)
{
    cin>>c[i]>>akt[i];
}
   for(int i=1; i<=n; i++)
   {

       if(c[i]=='H')
       {
           int k=*hori.lower_bound(akt[i]);
           set<int>::iterator it;
           if(k<akt[i])
           {

           }
           else
           {
            it=hori.lower_bound(akt[i]);
            it--;
            k=*it;
           }
           int v=*hori.lower_bound(akt[i]);
           if(v>akt[i])
           {

           }
           else
           {
            it=hori.lower_bound(akt[i]);;
            it++;
            v=*it;
           }

           hori.insert(akt[i]);
           hhany[v-k]--;
           if(hhany[v-k]==0)
           {
               hertek.erase(v-k);
           }
           hhany[v-akt[i]]++;
           hertek.insert(v-akt[i]);
           hhany[akt[i]-k]++;
           hertek.insert(akt[i]-k);
           set<int>::iterator iii;
           iii=hertek.end();
           iii--;
           int e=*iii;
          iii=vertek.end();
           iii--;
           int m=*iii;

           cout<<(long long)e*m<<endl;
       }
       else
       {
            int k=*veri.lower_bound(akt[i]);
           set<int>::iterator it;
           if(k<akt[i])
           {

           }
           else
           {
            it=veri.lower_bound(akt[i]);
            it--;
            k=*it;
           }
           int v=*veri.lower_bound(akt[i]);
           if(v>akt[i])
           {

           }
           else
           {
            it=veri.lower_bound(akt[i]);;
            it++;
            v=*it;
           }
           veri.insert(akt[i]);
           vhany[v-k]--;
           if(vhany[v-k]==0)
           {
               vertek.erase(v-k);
           }
           vhany[v-akt[i]]++;
           vertek.insert(v-akt[i]);
           vhany[akt[i]-k]++;
           vertek.insert(akt[i]-k);
           set<int>::iterator iii;
           iii=hertek.end();
           iii--;
           int e=*iii;
          iii=vertek.end();
           iii--;
           int m=*iii;

           cout<<(long long)e*m<<endl;
       }
   }
    return 0;
}