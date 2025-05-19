<?php
    session_start();
    $_SESSION["pseudo"]=$_POST["pseudo"];
    $_SESSION["password"]=$_POST["password"];

    if (($handle = fopen('../exo1/data.csv', 'r'))) {
        $headers = fgetcsv($handle, 1000, ',');
        while (($data = fgetcsv($handle, 1000, ','))) {
            $row = array_combine($headers, $data);
            if ($row["pseudo"]==$_POST["pseudo"] && $row["password"]==$_POST["password"]) {
                $_SESSION["nom"]=$row["nom"];
                $_SESSION["prenom"]=$row["prenom"];
                $_SESSION["type"]="eleve";
                echo "Mot de passe correct";
                header("Location: accueil.php");
                exit();
            } else {
                echo "incorecte";
            }

        }
        fclose($handle);
    }

    if (($handle = fopen('../exo2/data.csv', 'r'))) {
        $headers = fgetcsv($handle, 1000, ',');
        while (($data = fgetcsv($handle, 1000, ','))) {
            $row = array_combine($headers, $data);
            if ($row["pseudo"]==$_POST["pseudo"] && $row["password"]==$_POST["password"]) {
                $_SESSION["nom"]=$row["nom"];
                $_SESSION["prenom"]=$row["prenom"];
                $_SESSION["matiere"]=$row["matiere"];
                $_SESSION["type"]="prof";
                echo "Mot de passe correct";
                header("Location: accueil.php");
                exit();
            } else {
                echo "incorecte";
            }

        }
        fclose($handle);
    }

    if (($handle = fopen('../exo4/data.csv', 'r'))) {
        $headers = fgetcsv($handle, 1000, ',');
        while (($data = fgetcsv($handle, 1000, ','))) {
            if ($row["pseudo"]==$_POST["pseudo"] && $row["password"]==$_POST["password"]) {
            $row = array_combine($headers, $data);
                echo "Mot de passe correct";
                $_SESSION["type"]="admin";
                header("Location: accueil.php");
                exit();
            } else {
                echo "incorecte";
            }

        }
        fclose($handle);
    }


?>