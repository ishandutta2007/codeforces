#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 +6;

vector<int> v[4];

struct Kirino {
    int p[4];
    void meruru() {
        for (int i=0;4>i;i++) {
            scanf("%d",&p[i]);
        }
        if (p[2] < p[0]) swap(p[0],p[2]);
        if (p[3] < p[1]) swap(p[3],p[1]);
        for (int i=0;4>i;i++) {
            v[i].push_back(p[i]);
        }
    }
} kirino[MAX_N];

int main (){
    int n;
    scanf("%d",&n);
    int x,y;
    scanf("%d %d",&x,&y);
    v[0].push_back(0);
    v[1].push_back(0);
    v[2].push_back(x+1);
    v[3].push_back(y+1);
    for (int i=1;n>=i;i++) {
        kirino[i].meruru();
    }
    for (int i=0;4>i;i++) {
        if(i>=2) {
            for (int &j:v[i]) j=-j;
        }
        sort(v[i].begin(),v[i].end());
    }
    int cnt[4];
    scanf("%d %d %d %d",&cnt[0],&cnt[2],&cnt[1],&cnt[3]);
    for (int i=1;n>=i;i++) {
        bool can=true;
        for (int j=0;4>j;j++) {
            int tmp=kirino[i].p[(j+2)%4];
            if (j<2) {
                int tmpp=tmp;
                int pos=lower_bound(v[j].begin(),v[j].end(),tmp) - v[j].begin();
                pos--;
                if (kirino[i].p[j] != kirino[i].p[j+2]) pos--;
                //cout<<"i = "<<i<<" , j = "<<j<<" , pos = "<<pos<<endl;
                if (pos!=cnt[j]) can=false;
            }
            else {
                tmp=-tmp;
                int tmpp=tmp;
                int pos=lower_bound(v[j].begin(),v[j].end(),tmp) - v[j].begin();
                //cout<<"i = "<<i<<" , j = "<<j<<" , pos = "<<pos<<endl;
                pos--;
                if (kirino[i].p[j] != kirino[i].p[j-2]) pos--;
                //cout<<"i = "<<i<<" , j = "<<j<<" , pos = "<<pos<<endl;
                if (pos!=cnt[j]) can=false;
            }
        }
        if (can) {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
}