<?php
    session_start();
    if (!isset($_SESSION["password"])) {
        header("Location: connexion.php");
    }
    switch($_SESSION["type"]) {
        case "eleve":
            echo "Bienvenue à toi élève <br> " .  $_SESSION["nom"] . " " . $_SESSION["prenom"] . "<br> <br>";
            break;
        case "prof":
            echo "Bienvenue à vous <br> " .  $_SESSION["nom"] . " " . $_SESSION["prenom"] . " prof de " . $_SESSION["matiere"] ."<br> <br>";
            break;
        case "admin":
            echo "Je suis admin";
            break;
    }
?>

