<?php
    print_r($_GET);

    $file=fopen("data.csv","a");
    fputcsv($file,array_values($_GET));
    fclose($file)

?>