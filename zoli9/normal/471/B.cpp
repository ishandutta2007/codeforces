#include <iostream>
#include <algorithm>
using namespace std;
int n;
int hely, hely1, hely2;
struct task
{
    int id;
    int d;
};
task t[2001];
int ren(const void *a, const void *b)
{
    task x=(*(task*)a);
    task y=(*(task*)b);
    return x.d-y.d;
}
int elso[2001];
int masodik[2001];
int harmadik[2001];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].d;
        t[i].id=i;
    }
    qsort(t+1, n, sizeof(task), ren);
    hely=0;
    hely1=0;
    hely2=0;
    for(int i=3; i<=n; i++)
    {
        if(t[i].d==t[i-1].d && t[i-1].d==t[i-2].d)
        {
            hely=i;
            break;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(t[i].d==t[i-1].d)
        {
            if(hely1==0)
            {
                hely1=i;
            }
            else
            {
                hely2=i;
                break;
            }
        }
    }
    if(hely==0 && hely2==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
        {
            elso[i]=t[i].id;
            masodik[i]=t[i].id;
            harmadik[i]=t[i].id;
        }
    if(hely>0)
    {

        elso[hely-2]=t[hely-2].id;
        elso[hely-1]=t[hely-1].id;
        elso[hely]=t[hely].id;
        masodik[hely-2]=t[hely-1].id;
        masodik[hely-1]=t[hely].id;
        masodik[hely]=t[hely-2].id;
        harmadik[hely-2]=t[hely].id;
        harmadik[hely-1]=t[hely-2].id;
        harmadik[hely]=t[hely-1].id;


    }
    else
    {
        elso[hely1]=t[hely1-1].id;
        elso[hely1-1]=t[hely1].id;

        masodik[hely2]=t[hely2-1].id;
        masodik[hely2-1]=t[hely2].id;


    }
    for(int i=1; i<=n; i++)
    {
        cout<<elso[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<masodik[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<harmadik[i]<<" ";
    }
    cout<<endl;


    return 0;
}