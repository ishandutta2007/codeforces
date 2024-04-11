#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

vpii questions;

void add_question(int x, int v)
{
    questions.push_back({0, 0});
    int si=questions.size();
    si--;
    int idx=0;
    for(int i=si-1; i>=0; i--)
    {
        if(questions[i].F>x)
        {
            questions[i+1]=questions[i];
        }
        else
        {
            idx=i+1;
            break;
        }
    }
    //cout<<"idx:::"<<idx<<endl;
    questions[idx]={x, v};
}

int ask(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    int z;
    cin>>z;
    if(z==-1) exit(0);
    add_question(y, z);
    return z;
}

void final_ans(int x)
{
    cout<<"! "<<x<<endl;
    fflush(stdout);
    for(int i=(int)(questions.size())-1; i>=0; i--)
    {
        if(questions[i].F>=x) questions[i].S++;
        else break;
    }
}

void printqs()
{
    cout<<"qs"<<endl;
    for(auto& p: questions) cout<<p.F<<": "<<p.S<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin>>n>>t;
    for(int tt=1; tt<=t; tt++)
    {
        //printqs();
        cin>>k;
        int k1=1;
        int k2=n;
        for(int i=0; i<questions.size(); i++)
        {
            if(questions[i].F-questions[i].S<k) k1=questions[i].F+1;
            if(questions[i].F-questions[i].S>=k)
            {
                k2=questions[i].F-1;
                break;
            }
        }
        while(k1<=k2)
        {
            int mid=(k1+k2)/2;
            int x=ask(1, mid);
            x=mid-x;
            if(x<k) k1=mid+1;
            else k2=mid-1;
        }
        final_ans(k1);
    }



    return 0;
}