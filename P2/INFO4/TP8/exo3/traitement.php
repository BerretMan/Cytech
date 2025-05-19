<?php
session_start();

if (strpos($_SESSION["lettres"], $_POST["id"]) === false) {
    $_SESSION["lettres"] .= $_POST["id"]; 
    if (!strpos($_SESSION["mot"], $_POST["id"]) !== false) {
        $_SESSION["coup"]++; 
    }
}

#affiche le nombre de coup restant 
echo "Il reste " . (10-(int)$_SESSION["coup"]) . " coups. <br>";



    #affiche l'état du mot
    $mot_afficher = ""; 
    $i=0;
    foreach(str_split($_SESSION["mot"]) as $char) {
        $i++;
        if (strpos($_SESSION["lettres"], $char) !== false) {
            $mot_afficher .= $char; 
        } else {
            $mot_afficher .= "-"; 
        }
    }
    
    echo $mot_afficher; 

    if ((10-(int)$_SESSION["coup"]) <=0) {
        echo "<br>😔Non😔, tu as perdu <br> Le mot était " . $_SESSION["mot"];
        $_SESSION["victoire"]=true;
        exit();
    }

    if ($mot_afficher == $_SESSION["mot"]) {
        echo "<br>🎉 Bravo🎉, tu as gagné";
    }
    
?>