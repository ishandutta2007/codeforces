/+ dub.sdl:
    name "E"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;

// import dcomp.graph.maxflow;

int main() {
    auto sc = new Scanner(stdin);
    int n, m, s, t;
    sc.read(n, m, s, t); s--; t--;

    struct E {
        int to, cap, rev;
    }
    void addEdge(E[][] g, int from, int to, int cap) {
        g[from] ~= E(to, cap, g[to].length.to!int);
        g[to] ~= E(from, 0, g[from].length.to!int-1);
    }

    E[][] g = new E[][](n);

    struct E2 {
        int to, id;
    }
    E2[][] gn = new E2[][](n);

    bool[] used = new bool[n];
    int[] pa;
    bool dfs(int p, int q) {
        if (used[p]) return false;
        if (p == q) return true;
        used[p] = true;
        foreach (e; gn[p]) {
            if (dfs(e.to, q)) {
                pa ~= e.id;
                return true;
            }
        }
        return false;
    }
    bool make(int p, int q) {
        used[] = false;
        pa = new int[0];
        return dfs(p, q);
    }

    int[] U = new int[m], V = new int[m], G = new int[m];
    foreach (i; 0..m) {
        int u, v, h; sc.read(u, v, h); u--; v--;
        U[i] = u; V[i] = v; G[i] = h;
        if (h == 0) {
            addEdge(g, u, v, 100000);
        } else {
            addEdge(g, u, v, 1);
            addEdge(g, v, u, 100000);
            gn[u] ~= E2(v, i);
        }
    }
    int[] sm = new int[m];
    foreach (i; 0..m) {
        int u = U[i], v = V[i];
        if (G[i] == 0) continue;
        sm[i]++;
        if (make(v, u)) {
            foreach (d; pa) {
                sm[d]++;
            }
            continue;
        }
        make(s, u);
        foreach (d; pa) {
            sm[d]++;
        }    
        make(v, t);
        foreach (d; pa) {
            sm[d]++;
        }
    }
    auto mfI = maxFlow!(int, 0)(g, s, t);
    writeln(mfI.flow);
    foreach (i; 0..m) {
        int u = U[i], v = V[i];
        int di = 0;
        bool f;
        if (G[i] == 0) {
            f = false;
        } else {
            f = !mfI.dual[u] && mfI.dual[v];
        }
        writeln(sm[i], " ", sm[i] + (f ? 0 : 1));
    }
    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/graph/maxflow.d */
// module dcomp.graph.maxflow;

// import dcomp.container.deque;

 
struct maxFlowInfo(C) {
    C flow;
    bool[] dual;
}

 
maxFlowInfo!(C) maxFlow(C, C EPS, T)(T g, int s, int t) {
    assert(s != t);
    import std.algorithm : map;
    import std.range : array;
    import std.conv : to;
    int n = g.length.to!int;
    int[] level = new int[n];
    int[] iter = new int[n];

    void bfs() {
        level[] = -1; level[s] = 0;
        auto que = Deque!int(s);
        while (!que.empty) {
            int v = que.back; que.removeBack();
            foreach (e; g[v]) {
                if (e.cap <= EPS) continue;
                if (level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.insertBack(e.to);
                }
            }
        }
    }

    C dfs(int v, int t, C f) {
        import std.algorithm : min;
        if (v == t) return f;
        auto edgeList = g[v][iter[v]..$];
        foreach (ref e; edgeList) {
            if (e.cap <= EPS) continue;
            if (level[v] < level[e.to]) {
                C d = dfs(e.to, t, min(f, e.cap));
                if (d <= EPS) continue;
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
            iter[v]++;
        }
        return 0;
    }

    C flow = 0;
    while (true) {
        bfs();
        if (level[t] < 0) break;
        iter[] = 0;
        while (true) {
            C f = dfs(s, t, C.max);
            if (!f) break;
            flow += f;
        }
    }

    auto mfInfo = maxFlowInfo!C();
    mfInfo.flow = flow;
    mfInfo.dual = level.map!"a == -1".array;
    return mfInfo;
}


 
 


 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/foundation.d */
// module dcomp.foundation;
 
static if (__VERSION__ <= 2070) {
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
version (X86) static if (__VERSION__ < 2071) {
    import core.bitop : bsf, bsr, popcnt;
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/container/deque.d */
// module dcomp.container.deque;

 
struct Deque(T, bool mayNull = true) {
    import core.exception : RangeError;
    import core.memory : GC;
    import std.range : ElementType, isInputRange;
    import std.traits : isImplicitlyConvertible;

    struct Payload {
        T *d;
        size_t st, length, cap;
        @property bool empty() const { return length == 0; }
        alias opDollar = length;
        ref inout(T) opIndex(size_t i) inout {
            version(assert) if (length <= i) throw new RangeError();
            return d[(st+i >= cap) ? (st+i-cap) : st+i];
        }
        private void expand() {
            import std.algorithm : max;
            assert(length == cap);
            auto nc = max(size_t(4), 2*cap);
            T* nd = cast(T*)GC.malloc(nc * T.sizeof);
            foreach (i; 0..length) {
                nd[i] = this[i];
            }
            d = nd; st = 0; cap = nc;
        }
        void clear() {
            st = length = 0;
        }
        void insertFront(T v) {
            if (length == cap) expand();
            if (st == 0) st += cap;
            st--; length++;
            this[0] = v; 
        }
        void insertBack(T v) {
            if (length == cap) expand();
            length++;
            this[length-1] = v; 
        }
        void removeFront() {
            assert(!empty, "Deque.removeFront: Deque is empty");        
            st++; length--;
            if (st == cap) st = 0;
        }
        void removeBack() {
            assert(!empty, "Deque.removeBack: Deque is empty");        
            length--;
        }
    }
    struct RangeT(A) {
        alias T = typeof(*(A.p));
        alias E = typeof(A.p.d[0]);
        T *p;
        size_t a, b;
        @property bool empty() const { return b <= a; }
        @property size_t length() const { return b-a; }
        @property RangeT save() { return RangeT(p, a, b); }
        @property RangeT!(const A) save() const {
            return typeof(return)(p, a, b);
        }
        alias opDollar = length;
        @property ref inout(E) front() inout { return (*p)[a]; }
        @property ref inout(E) back() inout { return (*p)[b-1]; }
        void popFront() {
            version(assert) if (empty) throw new RangeError();
            a++;
        }
        void popBack() {
            version(assert) if (empty) throw new RangeError();
            b--;
        }
        ref inout(E) opIndex(size_t i) inout { return (*p)[i]; }
        RangeT opSlice() { return this.save; }
        RangeT opSlice(size_t i, size_t j) {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
        RangeT!(const A) opSlice() const { return this.save; }
        RangeT!(const A) opSlice(size_t i, size_t j) const {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
    }
    
    alias Range = RangeT!Deque;
    alias ConstRange = RangeT!(const Deque);
    alias ImmutableRange = RangeT!(immutable Deque);
    
    Payload* p;
    private void I() { if (mayNull && !p) p = new Payload(); }
    private void C() const {
        version(assert) if (mayNull && !p) throw new RangeError();
    }
    static if (!mayNull) {
        @disable this();
    }
     
    private this(Payload* p) {
        this.p = p;
    }
    this(U)(U[] values...) if (isImplicitlyConvertible!(U, T)) {
        p = new Payload();
        foreach (v; values) {
            insertBack(v);
        }
    }
     
    this(Range)(Range r)
    if (isInputRange!Range &&
    isImplicitlyConvertible!(ElementType!Range, T) &&
    !is(Range == T[])) {
        p = new Payload();
        foreach (v; r) {
            insertBack(v);
        }
    }
    static Deque make() { return Deque(new Payload()); }
    @property bool havePayload() const { return (!mayNull || p); }
     
    @property bool empty() const { return (!havePayload || p.empty); }
     
    @property size_t length() const { return (havePayload ? p.length : 0); }
     
    alias opDollar = length;
    ref inout(T) opIndex(size_t i) inout {C; return (*p)[i]; }
     
    ref inout(T) front() inout {C; return (*p)[0]; }
     
    ref inout(T) back() inout {C; return (*p)[$-1]; }
    void clear() { if (p) p.clear(); }
     
    void insertFront(T v) {I; p.insertFront(v); }
     
    void insertBack(T v) {I; p.insertBack(v); }
     
    alias stableInsertBack = insertBack;
     
    void removeFront() {C; p.removeFront(); }
     
    void removeBack() {C; p.removeBack(); }
     
    Range opSlice() {I; return Range(p, 0, length); }
}


 

 

 

 

 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            if (f.eof) return false;
            line = lineBuf[];
            f.readln(line);
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
            } else {
                auto buf = line.split.map!(to!E).array;
                static if (isStaticArray!T) {
                     
                    assert(buf.length == T.length);
                }
                x = buf;
                line.length = 0;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}