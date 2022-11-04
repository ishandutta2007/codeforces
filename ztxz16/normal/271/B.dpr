var
    n, m : longint;
    i, j : longint;
    Ans, Now : longint;
    a : array[1..500] of array[1..500] of longint;
    Prime, dis : array[1..100500] of longint;
begin
    Prime[1] := 1;
    for i := 2 to 1000 do
    begin
        if (Prime[i] = 1) then
            continue;
        j := i * i;
        while j <= 100500 do
        begin
            Prime[j] := 1;
            j := j + i;
        end;
    end;
    
    for i := 100500 downto 1 do
        if (Prime[i] = 0) then
            dis[i] := 0
        else
            dis[i] := dis[i + 1] + 1;
    read(n, m);
    for i := 1 to n do
        for j := 1 to m do
            read(a[i, j]);
    Ans := 2147483647;
    for i := 1 to n do
    begin
        Now := 0;
        for j := 1 to m do
            Now := Now + dis[a[i, j]];
        if (Now < Ans) then
            Ans := Now;
    end;
    
    for i := 1 to m do
    begin
        Now := 0;
        for j := 1 to n do
            Now := Now + dis[a[j, i]];
        if (Now < Ans) then
            Ans := Now;
    end;
    
    writeln(Ans);
end.