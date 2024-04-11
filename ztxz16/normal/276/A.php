<?php
    $Ans = -2147483647;
    fscanf(STDIN, "%d %d", $n, $k);
    for ($i = 1; $i <= $n; $i++)
    {
        fscanf(STDIN, "%d %d", $f, $t);
        if ($t > $k)
            $Now = $f - ($t - $k);
        else
            $Now = $f;
        if ($Now > $Ans)
            $Ans = $Now;
    }
    
    echo $Ans;
?>