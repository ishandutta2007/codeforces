/+ dub.sdl:
    name "E"
    dependency "dunkelheit" version="1.0.1"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner, dkh.graph.maxflow;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) assert(!sc.hasNext);

    int n, m;
    sc.read(n, m);

    int[] x1 = new int[m];
    int[] x2 = new int[m];
    int[] y1 = new int[m];
    int[] y2 = new int[m];
    foreach (i; 0..m) {
        sc.read(x1[i], y1[i], x2[i], y2[i]);
        x2[i]++; y2[i]++;
    }

    int[] xv = x1 ~ x2 ~ [0];
    int[] yv = y1 ~ y2 ~ [0];

    xv = xv.sort.uniq.array;
    yv = yv.sort.uniq.array;

    int getX(int x) {
        return xv.assumeSorted.lowerBound(x).length.to!int;
    }
    int getY(int y) {
        return yv.assumeSorted.lowerBound(y).length.to!int;
    }

    int w = xv.length.to!int - 1;
    int h = yv.length.to!int - 1;

    bool[][] mp = new bool[][](h, w);
    foreach (i; 0..m) {
        int l = getX(x1[i]), r = getX(x2[i]);
        int d = getY(y1[i]), u = getY(y2[i]);

        foreach (x; l..r) {
            foreach (y; d..u) {
                mp[y][x] = true;
            }
        }
    }

    struct Edge {
        int to, rev;
        long cap;
    }

    void addEdge(Edge[][] g, int from, int to, long cap) {
        g[from] ~= Edge(to, g[to].length.to!int, cap);
        g[to] ~= Edge(from, g[from].length.to!int-1, 0);
    }

    auto g = new Edge[][](1 + w + h + 1);
    int sv = w + h, tv = sv + 1;

    foreach (i; 0..w) {
        addEdge(g, sv, i, xv[i + 1] - xv[i]);
    }
    foreach (i; 0..h) {
        addEdge(g, w + i, tv, yv[i + 1] - yv[i]);
    }

    foreach (i; 0..w) {
        foreach (j; 0..h) {
            if (mp[j][i]) {
                addEdge(g, i, w + j, 10L^^18);
            }
        }
    }

    writeln(maxFlow!(long, 0)(g, sv, tv).flow);

    return 0;
}
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/foundation.d */
 
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
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/container/deque.d */
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

 
 

 

 

 

 

 

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/container/stackpayload.d */
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

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/graph/maxflow.d */
// module dkh.graph.maxflow;

// import dkh.container.deque;

 
struct MaxFlowInfo(C) {
    C flow;  
    bool[] dual;  
}

 
MaxFlowInfo!(C) maxFlow(C, C EPS, T)(T g, size_t s, size_t t, C gap = C.max) {
    assert(s != t);
    import std.conv : to;
    int[] level = new int[g.length];
    int[] iter = new int[g.length];

    void bfs() {
        level[] = -1; level[s] = 0;
        auto que = Deque!int();
        que.insertBack(s.to!int);
        while (!que.empty) {
            int v = que.front; que.removeFront;
            foreach (e; g[v]) {
                if (e.cap <= EPS) continue;
                if (level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.insertBack(e.to);
                }
            }
        }
    }

    C dfs(int v, C f) {
        import std.algorithm : min;
        if (v == t) return f;
        C res = 0;
        auto edgeList = g[v][iter[v]..$];
        foreach (ref e; edgeList) {
            if (e.cap <= EPS) continue;
            if (level[v] >= level[e.to]) continue;            
            C d = dfs(e.to, min(f, e.cap));
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            res += d;
            f -= d;
            if (f == 0) break;
            iter[v]++;
        }
        return res;
    }

    C flow = 0;
    while (gap - flow > EPS) {
        bfs();
        if (level[t] < 0) break;
        iter[] = 0;
        while (true) {
            C f = dfs(s.to!int, gap - flow);
            if (!f) break;
            flow += f;
        }
    }

    import std.algorithm : map;
    import std.range : array;
    auto mfInfo = MaxFlowInfo!C();
    mfInfo.flow = flow;
    mfInfo.dual = level.map!"a == -1".array;
    return mfInfo;
}

 
 

MaxFlowInfo!(C) maxFlowSlow(C, T)(T g, int s, int t, C gap = C.max) {
    assert(s != t);
    import std.algorithm : map;
    import std.range : array;
    import std.conv : to;
    auto n = g.length;

    bool[] used = new bool[n];
    bool dfs(int v) {
        if (v == t) return true;
        used[v] = true;
        foreach (ref e; g[v]) {
            if (used[e.to]) continue;
            if (!e.cap) continue;
            if (dfs(e.to)) {
                e.cap -= 1;
                g[e.to][e.rev].cap += 1;
                return true;
            }
        }
        return false;
    }
    
    C flow = 0;
    while (flow < gap) {
        used[] = false;
        if (!dfs(s)) break;
        flow++;
    }
    auto mfInfo = MaxFlowInfo!C();
    mfInfo.flow = flow;
    mfInfo.dual = used.map!"!a".array;
    return mfInfo;
}

 

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/scanner.d */
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