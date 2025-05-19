<?php
    $login=$_GET["login"] ?? '';
    $password=$_GET["password"] ?? '';

    $valid= [["HarryDu93","giny<3"],["HermioneDu64","pattenrond"],["RonDu33","tfcForEver"]];

    foreach ($valid as $id) {
        if ($id[0]==$login && $id[1] ==$password) {
            header('Location: accueil.php');
            exit();
        }
    }
    header('Location: connexion.html');
    exit();
?>