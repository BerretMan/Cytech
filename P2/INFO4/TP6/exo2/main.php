<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
function triBulle(array $tab) {
    $taille = count($tab);
    $cpt = true;

    while ($cpt) {
        $cpt = false;
        for ($i = 0; $i < $taille - 1; $i++) {
            if ($tab[$i] > $tab[$i + 1]) {
                // Échange des valeurs
                $temp = $tab[$i];
                $tab[$i] = $tab[$i + 1];
                $tab[$i + 1] = $temp;
                
                $cpt = true;
            }
        }
    }
    
    return $tab;
}

    function show_tab(array $tab) {
        echo "[";
        for ($i=0;$i<count($tab);$i++) {
            echo $tab[$i] . ",";
        }
        echo "]";
    }
    $t=[1,5,6,81,7];
    echo "avant le tri<br>";
    show_tab($t);
    echo "<br><hr> Après le tri<br>";
    show_tab(triBulle($t));

?>
</body>
</html>