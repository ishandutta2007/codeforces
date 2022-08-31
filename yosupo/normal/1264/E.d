/+ dub.sdl:
    name "X"
    dependency "dunkelheit" version="1.0.1"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner, dkh.graph.mincostflow;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) assert(!sc.hasNext);

    int n, m;
    sc.read(n, m);
    int ec = n * (n - 1) / 2;
    int v = ec + n + 2;
    int sv = ec + n, tv = sv + 1;
    struct E {
        int to, rev, cap, dist;
    }
    E[][] g = new E[][](v);
    void addEdge(int from, int to, int cap, int dist) {
        g[from] ~= E(to, g[to].length.to!int, cap, dist);
        g[to] ~= E(from, g[from].length.to!int-1, 0, -dist);
    }
    int[][] def = new int[][](n, n);
    foreach (i; 0..m) {
        int a, b;
        sc.read(a, b); a--; b--;
        def[a][b] = 1;
        def[b][a] = -1;
    }
    int id = 0;
    foreach (i; 0..n) {
        foreach (j; i + 1..n) {
            addEdge(sv, id, 1, 0);
            if (def[i][j] != -1) {
                addEdge(id, ec + i, 1, 0);
            }
            if (def[j][i] != -1) {
                addEdge(id, ec + j, 1, 0);
            }
            id++;
        }
    }
    foreach (i; 0..n) {
        foreach (j; 1..n+1) {
            addEdge(ec + i, tv, 1, j - 1);
        }
    }
    auto mcfInfo = minCostFlow!(int, int, 0)(g, sv, tv, false);
    mcfInfo.manyFlow(10^^9);

    int[][] ans = new int[][](n, n);
    id = 0;
    foreach (i; 0..n) {
        foreach (j; i + 1..n) {
            foreach (e; g[id]) {
                if (e.to < ec || ec + n <= e.to) continue;
                if (e.cap) continue;
                if (e.to == ec + i) ans[i][j] = 1;
                else ans[j][i] = 1;
                break;
            }
            id++;
        }
    }

    foreach (i; 0..n) {
        foreach (j; 0..n) {
            write(ans[i][j]);
        }
        writeln;
    }
    return 0;
}
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/foundation.d */
 
// module dkh.foundation;

 
static if (__VERSION__ <= 2070) {
    /*
    Copied by https://github.com/dlang/phobos/blob/master/std/algorithm/iteration.d
    Copyright: Andrei Alexandrescu 2008-.
    License: $(HTTP boost.org/LICENSE_1_0.txt, Boost License 1.0).
    */
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/container/deque.d */
// module dkh.container.deque;

struct DequePayload(T) {
    import core.exception : RangeError;

    private T* _data;
    private uint start, len, cap;

    @property bool empty() const { return len == 0; }
    @property size_t length() const { return len; }
    alias opDollar = length;

    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (len <= i) throw new RangeError();
        if (start + i < cap) return _data[start + i];
        else return _data[start + i - cap];
    }
    ref inout(T) front() inout { return this[0]; }
    ref inout(T) back() inout { return this[$-1]; }

    void reserve(size_t newCap) {
        import core.memory : GC;
        import std.algorithm : max;
        import std.conv : to;
        if (newCap <= cap) return;
        T* newData = cast(T*)GC.malloc(newCap * T.sizeof);
        foreach (i; 0..length) {
            newData[i] = this[i];
        }
        _data = newData; start = 0; cap = newCap.to!uint;
    }
    void clear() {
        start = len = 0;
    }
    import std.algorithm : max;
    void insertFront(T item) {
        if (len == cap) reserve(max(cap * 2, 4));
        if (start == 0) start += cap;
        start--; len++;
        this[0] = item;
    }
    void insertBack(T item) {
        if (len == cap) reserve(max(cap * 2, 4));
        len++;
        this[len-1] = item;
    }
    void removeFront() {
        assert(!empty, "Deque.removeFront: Deque is empty");
        start++; len--;
        if (start == cap) start = 0;
    }
    void removeBack() {
        assert(!empty, "Deque.removeBack: Deque is empty");        
        len--;
    }
}

 
struct Deque(T, bool mayNull = true) {
    import core.exception : RangeError;
    import std.range : ElementType, isInputRange;
    import std.traits : isImplicitlyConvertible;

    alias Payload = DequePayload!T;
    Payload* _p;
    
    static if (!mayNull) @disable this();

     
    this(U)(U[] values...) if (isImplicitlyConvertible!(U, T)) {
        _p = new Payload();
        foreach (v; values) {
            insertBack(v);
        }
    }
     
    this(Range)(Range r)
    if (isInputRange!Range &&
    isImplicitlyConvertible!(ElementType!Range, T) &&
    !is(Range == T[])) {
        _p = new Payload();
        foreach (v; r) {
            insertBack(v);
        }
    }
    private this(Payload* p) { _p = p; }
    static Deque make() { return Deque(new Payload()); }
    
    private bool havePayload() const { return (!mayNull || _p); }    
    @property bool empty() const { return (!havePayload || _p.empty); }  
    @property size_t length() const { return (havePayload ? _p.length : 0); }  
    alias opDollar = length;  

    ref inout(T) opIndex(size_t i) inout {
        assert(!empty, "Deque.opIndex: Deque is empty");
        return (*_p)[i];
    }  
    ref inout(T) front() inout { return this[0]; }  
    ref inout(T) back() inout { return this[$-1]; }  

    void clear() { if (_p) _p.clear(); }  

     
    void insertFront(T item) {
        if (mayNull && !_p) _p = new Payload();
        _p.insertFront(item);
    }
    void insertBack(T item) {
        if (mayNull && !_p) _p = new Payload();
        _p.insertBack(item);
    }  
    alias opOpAssign(string op : "~") = insertBack;  
    alias stableInsertBack = insertBack;  

     
    void removeFront() {
        assert(!mayNull || _p, "Deque.removeFront: Deque is empty");
        _p.removeFront();
    }
    void removeBack() {
        assert(!mayNull || _p, "Deque.removeBack: Deque is empty");
        _p.removeBack();
    }  
    alias stableRemoveBack = removeBack;  

     
    alias Range = RangeT!(DequePayload!T);
    alias ConstRange = RangeT!(const DequePayload!T);  
    alias ImmutableRange = RangeT!(immutable DequePayload!T);  

    size_t[2] opSlice(size_t dim : 0)(size_t start, size_t end) const {
        assert(start <= end && end <= length);
        return [start, end];
    }  
    Range opIndex(size_t[2] rng) { return Range(_p, rng[0], rng[1]); }  
    ConstRange opIndex(size_t[2] rng) const { return ConstRange(_p, rng[0], rng[1]); }  
    ImmutableRange opIndex(size_t[2] rng) immutable { return ImmutableRange(_p, rng[0], rng[1]); }  
    auto opIndex() inout { return this[0..$]; }  

    static struct RangeT(QualifiedPayload) {
        alias A = QualifiedPayload;
        import std.traits : CopyTypeQualifiers;
        alias E = CopyTypeQualifiers!(A, T);
        A *p;
        size_t l, r;

        @property bool empty() const { return r <= l; }
        @property size_t length() const { return r - l; }
        alias opDollar = length;

        @property auto save() { return this; }
        
        ref inout(E) opIndex(size_t i) inout {
            version(assert) if (empty) throw new RangeError();
            return (*p)[l+i];
        }
        @property ref inout(E) front() inout { return this[0]; }
        @property ref inout(E) back() inout { return this[$-1]; }

        void popFront() {
            version(assert) if (empty) throw new RangeError();
            l++;
        }
        void popBack() {
            version(assert) if (empty) throw new RangeError();
            r--;
        }
        
        size_t[2] opSlice(size_t dim : 0)(size_t start, size_t end) const {
            assert(start <= end && end <= length);
            return [start, end];
        }
        auto opIndex(size_t[2] rng) { return RangeT(p, l+rng[0], l+rng[1]); }
        auto opIndex(size_t[2] rng) const { return RangeT!(const A)(p, l+rng[0], l+rng[1]); }
        auto opIndex(size_t[2] rng) immutable { return RangeT!(immutable A)(p, l+rng[0], l+rng[1]); }
        auto opIndex() inout { return this[0..$]; }
    } 
}

 
 

 

 

 

 

 

 
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/container/radixheap.d */
// module dkh.container.radixheap;

// import dkh.container.stackpayload;

import std.functional : unaryFun;
import std.traits : isSigned, isUnsigned;

 
template RadixHeap(T, alias pred = "a") {
    alias _pred = unaryFun!pred;  
    alias K = typeof(_pred(T()));  
     
    static if (isUnsigned!K) {
         

        struct RadixHeap {
            static struct Payload {
                StackPayload!T[K.sizeof*8+1] v;
                size_t len;
                K last;

                 
                private static int bsr1(K x) {
                    import core.bitop : bsr;
                    return (x == 0) ? 0 : bsr(x)+1;
                }
                private void assign(T item) {
                    K key = _pred(item);
                    assert(last <= key);
                    v[bsr1(key^last)] ~= item;
                }
                private void pull() {
                    import std.range, std.algorithm;
                    if (v[0].length) return;
                    auto i = iota(K.sizeof*8+1).find!(a => v[a].length).front;
                     
                    last = v[i].data[].map!_pred.reduce!min;
                    v[i].data.each!(a => assign(a));
                    v[i].clear();
                }

                void insert(T item) {
                    len++;
                    assign(item);
                }
                T front() {
                    pull();
                    return v[0].back;
                }
                void removeFront() {
                    pull();
                    len--;
                    v[0].removeBack();
                }
            }
            Payload* p;

            @property bool empty() const { return (!p || p.len == 0); }  
            @property size_t length() const { return (!p ? 0 : p.len); }  
            alias opDollar = length;  

             
            T front() {
                assert(!empty, "RadixHeap.front: heap is empty");
                return p.front;
            }
            void insert(T item) {
                if (!p) p = new Payload();
                p.insert(item);
            }  
            void removeFront() {
                assert(!empty, "RadixHeap.removeFront: heap is empty");
                p.removeFront();
            }  
        }
    } else static if (isSigned!K) {
         
        import std.traits : Unsigned;
        static Unsigned!K pred2(in T item) {
            return _pred(item) ^ (K(1) << (K.sizeof*8 - 1));
        }
        alias RadixHeap = RadixHeap!(T, pred2);
    } else {
        static assert(false);
    }
}

 
 

 

 
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/graph/mincostflow.d */
// module dkh.graph.mincostflow;

// import dkh.container.deque;

 
struct MinCostFlowInfo(C, D, D EPS, T) {
    T g;
    int s, t;
    C nc, capFlow;  
    D nd, flow;  
    D[] dual;  
    private int[] pv, pe;
    this(T g, int s, int t) {
        this.g = g;
        this.s = s;
        this.t = t;
        flow = D(0);
        dual = new D[g.length]; dual[] = D(0);
        pv = new int[g.length];
        pe = new int[g.length];
    }
}

 
MinCostFlowInfo!(C, D, EPS, T) minCostFlow(C, D, D EPS, T)(T g, int s, int t, bool neg = false) {
    assert(s != t);
    auto mcfInfo = MinCostFlowInfo!(C, D, EPS, T)(g, s, t);
    mcfInfo.dualRef(neg);
    return mcfInfo;
}

 
 

 
C singleFlow(C, D, alias EPS, T)(ref MinCostFlowInfo!(C, D, EPS, T) mcfInfo, C c) {
    import std.algorithm;
    with (mcfInfo) {
        if (nd == D.max) return nc;
        c = min(c, nc);
        for (int v = t; v != s; v = pv[v]) {
            g[pv[v]][pe[v]].cap -= c;
            g[v][g[pv[v]][pe[v]].rev].cap += c;
        }        
        capFlow += c;
        flow += c * nd;
        nc -= c;
        if (!nc) dualRef(mcfInfo, false);
    }
    return c;
}

 
void manyFlow(C, D, alias EPS, T)(ref MinCostFlowInfo!(C, D, EPS, T) mcfInfo, C c) {
    with (mcfInfo) {
        while (c) {
            C f = singleFlow(mcfInfo, c);
            if (!f) break;
            c -= f;
        }
    }
}

// import dkh.container.stackpayload;
// import dkh.container.radixheap;

void dualRef(bool neg, C, D, alias EPS, T)(ref MinCostFlowInfo!(C, D, EPS, T) mcfInfo) {
    import std.conv : to;
    import std.traits : isIntegral;
    import std.typecons;
    import std.container;
    import std.algorithm;
    alias P = Tuple!(int, "to", D, "dist");

    with(mcfInfo) {
        int n = g.length.to!int;
        D[] dist = new D[n]; dist[] = D.max;
        pv[] = -1; pe[] = -1;
        StackPayload!int refV;
        auto que = (){
            static if (!neg) {
                static if (isIntegral!D) {
                    return RadixHeap!(P, "a.dist")();
                } else {
                    return heapify!"a.dist>b.dist"(make!(Array!P));
                }
            } else {
                return Deque!P();
            }
        }();
        void insert(P p) {
            static if (!neg) {
                que.insert(p);
            } else {
                que.insertBack(p);
            }
        }
        P pop() {
            P p;
            static if (!neg) {
                p = que.front();
                que.removeFront();
            } else {
                p = que.back();
                que.removeBack();
            }
            return p;
        }
        insert(P(s, D(0)));
        dist[s] = D(0);
        while (!que.empty) {
            P p = pop();
            int v = p.to;
            if (dist[v] < p.dist) continue;
            if (!neg) {
                if (v == t) break;
                refV ~= v;
            }
            foreach (int i, e; g[v]) {
                D ed = e.dist + dual[v] - dual[e.to];
                if (e.cap && dist[e.to] > dist[v] + ed + EPS) {
                    dist[e.to] = dist[v] + ed;
                    pv[e.to] = v; pe[e.to] = i;
                    insert(P(e.to, dist[e.to]));
                }
            }
        }
        if (dist[t] == D.max) {
            nd = D.max;
            nc = 0;
            return;
        }
        static if (!neg) {
            foreach (v; refV.data) {
                if (dist[v] >= dist[t]) continue;
                dual[v] += dist[v]-dist[t];
            }
        } else {
            for (int v = 0; v < n; v++) {
                if (dist[v] == D.max) dual[v] = D.max;
                else dual[v] += dist[v];
            }
        }
        
        nd = dual[t]-dual[s];
        nc = C.max;
        for (int v = t; v != s; v = pv[v]) {
            nc = min(nc, g[pv[v]][pe[v]].cap);
        }
    }
}

void dualRef(C, D, alias EPS, T)(ref MinCostFlowInfo!(C, D, EPS, T) mcfInfo, bool neg) {
    if (neg == false) {
        dualRef!false(mcfInfo);
    } else {
        dualRef!true(mcfInfo);
    }
}

 

 
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/container/stackpayload.d */
// module dkh.container.stackpayload;

 
struct StackPayload(T, size_t MINCAP = 4) if (MINCAP >= 1) {
    import core.exception : RangeError;

    private T* _data;
    private uint len, cap;

    @property bool empty() const { return len == 0; }
    @property size_t length() const { return len; }
    alias opDollar = length;

     
    inout(T)[] data() inout { return (_data) ? _data[0..len] : null; }
    
    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (len <= i) throw new RangeError();
        return _data[i];
    }  
    ref inout(T) front() inout { return this[0]; }  
    ref inout(T) back() inout { return this[$-1]; }  

    void reserve(size_t newCap) {
        import core.memory : GC;
        import core.stdc.string : memcpy;
        import std.conv : to;
        if (newCap <= cap) return;
        void* newData = GC.malloc(newCap * T.sizeof);
        cap = newCap.to!uint;
        if (len) memcpy(newData, _data, len * T.sizeof);
        _data = cast(T*)(newData);
    }  
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }  
     
    void clear() {
        len = 0;
    }

    void insertBack(T item) {
        import std.algorithm : max;
        if (len == cap) reserve(max(cap * 2, MINCAP));
        _data[len++] = item;
    }  
    alias opOpAssign(string op : "~") = insertBack;  
    void removeBack() {
        assert(!empty, "StackPayload.removeBack: Stack is empty");
        len--;
    }  
}

 
/* IMPORT /Users/yosupo/Programs/dunkelheit/source/dkh/scanner.d */
// module dkh.scanner;

// import dkh.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    private File f;
     
    this(File f) {
        this.f = f;
    }
    private char[512] lineBuf;
    private char[] line;
    private bool succW() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (!line.empty && line.front.isWhite) {
            line.popFront;
        }
        return !line.empty;
    }
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            line = lineBuf[];
            f.readln(line);
            if (!line.length) return false;
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else static if (isStaticArray!T) {
                foreach (i; 0..T.length) {
                    assert(succW());
                    x[i] = line.parse!E;
                }
            } else {
                StackPayload!E buf;
                while (succW()) {
                    buf ~= line.parse!E;
                }
                x = buf.data;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }

     
    int unsafeRead(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
     
    void read(Args...)(auto ref Args args) {
        import std.exception : enforce;
        static if (args.length != 0) {
            enforce(readSingle(args[0]));
            read(args[1..$]);
        }
    }
     
    bool hasNext() {
        return succ();
    }
}


 
 

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/