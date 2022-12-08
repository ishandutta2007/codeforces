#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
//#include <set>
using namespace std;

int wins[100010];

struct set{
    int a, b, t;
    set(int na, int nb, int nt)
    {
        a=na;
        b=nb;
        t=nt;
    }
};

vector<set> steps;
int ss;

void arreglar(int n, int i, int j)
{
        while(steps[j].t<n && max(steps[j].a, steps[j].b)<i)
            {
                steps[j].t++;
                
                if(steps[j].t<n)
                {
                    if(wins[steps[j].t]==1)
                    {
                        steps[j].a++;
                        if(j<ss-1) steps[j+1].a--;
                    }
                    else
                    {
                        steps[j].b++;
                        if(j<ss-1) steps[j+1].b--;
                    }
                    
                    if(j<ss-1 && max(steps[j+1].a, steps[j+1].b)<i) arreglar(n, i, j+1);
                }
            }
            
            
            if(steps[j].t==n)
            {
                for(int k=ss-1; k>=j; k--)
                {
                    steps.pop_back();
                }
                ss=j;
            }
}

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> wins[i];

    vector<pair<int, int> > sols;
    
    int i, w=wins[n-1], l=3-w;
    for(i=1; i*i<=n; i++)
    {
        int acc[3]={0,0,0}, a=0, b=0;
        for(int j=0; j<n; j++)
        {
            if(wins[j]==1) a++;
            if(wins[j]==2) b++;
            if(max(a,b)==i)
            {
                if(a>b) acc[1]++;
                if(b>a) acc[2]++;
                a=0;
                b=0;
            }
        }
        if(a==0 && b==0 && acc[w]>acc[l]) sols.push_back(make_pair(acc[w], i));
        //cout << i << " " << a << " " << b << " " << acc[w] << " " << acc[l] << endl;
    }
    int  acc[3]={0,0,0}, a=0, b=0;
    for(int j=0; j<n; j++)
    {
        if(wins[j]==1) a++;
        if(wins[j]==2) b++;
        if(max(a,b)==i)
        {
            if(a>b) acc[1]++;
            if(b>a) acc[2]++;
            set s(a,b,j);
            steps.push_back(s);
            a=0;
            b=0;
        }
    }
    
    ss=steps.size();
    
    while(i<=n)
    {
        for(int j=0; j<ss; j++)
        {
            
            arreglar(n, i, j);
        }
        
        acc[1]=0; acc[2]=0;
        for(int j=0; j<ss; j++)
        {
            acc[wins[steps[j].t]]++;
        }
        
        /*cout << " " << i << endl << " " << acc[w] << " " << acc[l] << endl;
        for(int j=0; j<ss; j++)
            cout << steps[j].t << " " << steps[j].a << " " << steps[j].b << endl;*/
        if(ss && steps[ss-1].t==n-1 && acc[w]>acc[l])
        {
            sols.push_back(make_pair(acc[w], i));
        }
        i++;
    } 
    
    sort(sols.begin(), sols.end());
    vector<pair<int, int> >::iterator it;
    it = std::unique (sols.begin(), sols.end());
    sols.resize( std::distance(sols.begin(),it) );
    int so=sols.size();
    cout << so << endl;
    
    for(int i=0; i<so; i++)
    {
        cout << sols[i].first << " " << sols[i].second << endl;
    }
    if(so)
    cout << endl;
}