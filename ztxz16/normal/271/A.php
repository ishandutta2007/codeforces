<?php
    fscanf(STDIN, "%d", $n);
    $n++;
    $Hash = array();
    $temp = 1;
    while ((int)($temp) != 0)
    {
        $temp = $n;
        while ($temp > 0)
        {
            if ($Hash[$temp % 10] == $n)
                break;
            $Hash[$temp % 10] = $n;
            $temp /= 10;
        }
        
        $n++;
    }
    
    echo $n - 1;
?>