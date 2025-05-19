<?php 

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $a=$_POST["a"];
    $b=$_POST["b"];
    $c=$_POST["c"];
    $delta=pow($b,2)-4*$a*$c;
    
    if ($delta>0) {
        echo "L'équation a deux solutions \n \n";
        echo "x_1=" . (-$b+sqrt($delta))/2*$a . "\n";
        echo "x_2=" . (-$b-sqrt($delta))/2*$a;
    }
    if ($delta==0) {
        echo "L'équation a une solutions \n \n";
        echo "x=" . (-$b)/2*$a . "\n";
    } else {
        echo "L'équation n'a pas de solution dans ℝ \n \n";
    }
}

?>