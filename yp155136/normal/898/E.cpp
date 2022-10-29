#include <bits/stdc++.h>
using namespace std;

int main ()
{
    set<int> st;
    for (int i=0;i*i < 1010101010;i++)
    {
        st.insert(i*i);
    }
    priority_queue<int,vector<int>,greater<int> > pq1,pq2;
    //pq1 --> sqrt --> not sqrt
    //pq2 --> not sqrt --> sqrt
    int n;
    cin >> n;
    for (int i=0;n>i;i++)
    {
        int x;
        cin >> x;
        auto iter=st.find(x);
        if (iter != st.end())
        {
            if (x == 0) pq1.push(2);
            else pq1.push(1);
        }
        else
        {
            auto iter = st.lower_bound(x);
            auto iter2=iter;
            --iter2;
            pq2.push(min( (*iter)-x,x-(*(iter2)) ));
        }
    }
    long long ans=0;
    if (pq1.size() > pq2.size())
    {
        int need = (pq1.size()-pq2.size())/2;
        while (need--)
        {
            ans += pq1.top();
            pq1.pop();
        }
    }
    else
    {
        swap(pq1,pq2);
        int need = (pq1.size()-pq2.size())/2;
        while (need--)
        {
            ans += pq1.top();
            pq1.pop();
        }
    }
    cout<<ans<<endl;
}