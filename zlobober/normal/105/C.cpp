#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

const int N = 1050;


struct resid
{
    resid(){}
    char type;
    string name;
    int bonus;
    friend bool operator <(resid a, resid b)
    {
        if (a.type != b.type)
            return a.type < b.type;
        return a.bonus > b.bonus;
    }
    resid(char _type, int _bonus)
    {
        type = _type;
        bonus = _bonus;
    }
} R[N];

struct thing
{
    int v;
    int s;
    string name;
    char type;
    int _g;
    int get()
    {
        if (_g == -1)
        {
            _g = 0;
            for (int i = 0; i < C.size(); i++)
                _g += R[C[i]].bonus * (R[C[i]].type == type);
        }
        return _g;
    }
    vector<int> C;
    thing(char _type, int _v) : type(_type), v(_v) { _g = -1; }
    friend bool operator <(thing a, thing b)
    {
        if (a.type != b.type)
            return a.type < b.type;
        return a.v + a.get() > b.v + b.get();
    }
    thing(){ _g = -1; }
} T[N];

map<string, int> things;

map<string, int> resids;

int n;

void print(thing t)
{
    cout << t.name;
    cout << ' ';
    cout << t.C.size() << ' ';
    for (int i = 0; i < t.C.size(); i++)
        cout << R[t.C[i]].name << ' ';
    cout << endl;
}

void stup()
{
    sort(T, T + n);
    thing *a = lower_bound(T, T + n, thing('a', 1e9));
    thing *d = lower_bound(T, T + n, thing('d', 1e9));
    thing *r = lower_bound(T, T + n, thing('r', 1e9));
    print(*a);
    print(*d);
    print(*r);

}

int k;

vector<int> VA;
vector<int> VR;
vector<int> VS;

bool was[N];

void clever()
{
    sort(R, R + k);
    resid *a = lower_bound(R, R + k, resid('a', 1e9));
    resid *d = lower_bound(R, R + k, resid('d', 1e9));
    resid *r = lower_bound(R, R + k, resid('r', 1e9));
    resid *an = d;
    resid *dn = r;
    resid *rn = R + k;
    for (int i = 0; i < n; i++)
    {
        T[i].C.resize(0);

        if (T[i].type == 'a')
            for (int j = 0; j < T[i].s && (a + j) != an; j++)
                T[i].C.push_back((a + j) - R);

        if (T[i].type == 'd')
            for (int j = 0; j < T[i].s && (d + j) != dn; j++)
                T[i].C.push_back((d + j) - R);

        if (T[i].type == 'r')
            for (int j = 0; j < T[i].s && (r + j) != rn; j++)
                T[i].C.push_back((r + j) - R);
    }
    sort(T, T + n);
    thing *aa = lower_bound(T, T + n, thing('a', 1e9));
    thing *dd = lower_bound(T, T + n, thing('d', 1e9));
    thing *rr = lower_bound(T, T + n, thing('r', 1e9));
    for (int i = 0; i < aa->C.size(); i++)
        was[aa->C[i]] = 1;
    for (int i = 0; i < dd->C.size(); i++)
        was[dd->C[i]] = 1;
    for (int i = 0; i < rr->C.size(); i++)
        was[rr->C[i]] = 1;
    for (int i = 0; i < k; i++)
    {
        if (!was[i])
        {
            if (aa->C.size() != aa->s)
                aa->C.push_back(i);
            else if (dd->C.size() != dd->s)
                dd->C.push_back(i);
            else if (rr->C.size() != rr->s)
                rr->C.push_back(i);
        }
    }
    print(*aa);
    print(*dd);
    print(*rr);
}

int main()
{
    cin >> n;
    string name, clas;
    int a, d, r, s;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> clas >> a >> d >> r >> s;
        T[i].name = name;
        switch(clas[0])
        {
            case 'w':
                clas[0] = 'a';
                T[i].v = a;
                break;
            case 'a':
                clas[0] = 'd';
                T[i].v = d;
                break;
            case 'o':
                clas[0] = 'r';
                T[i].v = r;
                break;
        }
        T[i].type = clas[0];
        T[i].s = s;
        things[name] = i;
    }
    cin >> k;
    int bonus;
    int th;
    string in;
    for (int i = 0; i < k; i++)
    {
        cin >> name >> clas;
        cin >> bonus >> in;
        th = things[in];
        T[th].C.push_back(i);
        R[i].bonus = bonus;
        R[i].name = name;
        switch(clas[0])
        {
            case 'g':
                clas[0] = 'a';
                break;
            case 's':
                clas[0] = 'd';
                break;
            case 'p':
                clas[0] = 'r';
                break;
        }
        R[i].type = clas[0];
    }

    bool good = false;
    for (int i = 0; i < n; i++)
        good |= T[i].C.size() != T[i].s;
    if (!good)
    {
        stup();
    }
    else
    {
        clever();
    }

}