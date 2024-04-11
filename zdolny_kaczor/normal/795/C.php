<?php
  fscanf(STDIN, "%d\n", $number); // reads number from STDIN
  if ($number % 2 == 1) {
    echo 7;
    $number -= 3;
  }
  for ($i = 0; $i < $number; $i += 2) {
    echo 1;
  }
?>