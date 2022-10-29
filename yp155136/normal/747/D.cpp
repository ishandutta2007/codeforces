#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 + 6;

int t[MAX_N];
int L[MAX_N],R[MAX_N];

int main () {
    int n,k;
    while (scanf("%d %d",&n,&k) != EOF) {
        for (int i=1;n>=i;i++) {
            scanf("%d",&t[i]);
        }
        t[n+1]=0;
        int id=1;
        int st=-1,ed=-1;
        int cnt=0;
        for (int i=1;n+1>=i;i++) {
            if (t[i] < 0) {
                //cout<<"in i = "<<i<<endl;
                cnt++;
                if (st<0) st=ed=i;
                else ed=i;
            }
            else {
                if (st==-1) continue;
                L[id] = st;
                R[id] = ed;
                id++;
                st=ed=-1;
            }
        }
        //cout<<"id = "<<id<<endl;
        if (cnt > k) {
            puts("-1");
            continue;
        }
        //we must have the solution
        L[id] = n+1;
        R[id] = n+1;
        id++;
        int ans=2*(id-2);
        priority_queue<int,vector<int>,greater<int> > pq;
        for (int i=1;id-2>i;i++) {
            //cout<<"i = "<<i<<" , L[i] = "<<L[i]<<" , R[i] = "<<R[i]<<endl;
            pq.push(L[i+1]-R[i]-1);
        }
        int tmp=cnt;
        cnt = k-cnt;
        //cout<<"cnt = "<<cnt<<endl;
        while (!pq.empty()) {
            int t=pq.top();
            pq.pop();
            //cout<<"t = "<<t<<endl;
            if (t <= cnt) {
                //cout<<"innnn\n";
                ans -=2;
                cnt -= t;
            }
        }

        for (int i=n;i>=1;i--) {
            if (t[i] >= 0) {
                t[i] = -1;
            }
            else {
                break;
            }
        }
        t[n+1]=0;
        id=1;
        st=-1,ed=-1;
        cnt=0;
        for (int i=1;n+1>=i;i++) {
            if (t[i] < 0) {
                cnt++;
                if (st<0) st=ed=i;
                else ed=i;
            }
            else {
                if (st==-1) continue;
                L[id] = st;
                R[id] = ed;
                id++;
                st=ed=-1;
            }
        }
        if (cnt > k) {
            printf("%d\n",ans);
            continue;
        }
        //we must have the solution
        L[id] = n+1;
        R[id] = n+1;
        id++;
        int ans2=2*(id-2)-1;
        priority_queue<int,vector<int>,greater<int> > pq2;
        for (int i=1;id-2>i;i++) {
            //cout<<"i = "<<i<<" , L[i] = "<<L[i]<<" , R[i] = "<<R[i]<<endl;
            pq2.push(L[i+1]-R[i]-1);
        }
        tmp=cnt;
        cnt = k-cnt;
        //cout<<"cnt = "<<cnt<<endl;
        while (!pq2.empty()) {
            int t=pq2.top();
            pq2.pop();
            //cout<<"t = "<<t<<endl;
            if (t <= cnt) {
                //cout<<"innnn\n";
                ans2 -=2;
                cnt -= t;
            }
        }
        printf("%d\n",min(ans,ans2) );
    }
}