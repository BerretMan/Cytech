<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="bonjour.css">
</head>
<body>
    <table> 
    <tr>
        <th>Nom</th>
        <th>Prénom</th>
        <th>Date de Naissance</th>
        <th>Poste</th>
        <th>Age</th>
    </tr>
    <?php 

        function calculAge($date) {
                $a= substr($date,6);
                return date("Y")-$a;
        }



        $joueur = [
            ["Nom" => "Giroud", "Prénom" => "Olivier", "Date de Naissance" => "30/09/1986", "Poste" => "Attaquant"],
            ["Nom" => "Griezman", "Prénom" => "Antoine", "Date de Naissance" => "21/03/1991", "Poste" => "Attaquant"],
            ["Nom" => "MBappe", "Prénom" => "Kylian", "Date de Naissance" => "20/11/1998", "Poste" => "Attaquant"],
            ["Nom" => "Nobbs", "Prénom" => "Jordan", "Date de Naissance" => "08/12/1992", "Poste" => "Milieu"],
            ["Nom" => "Williamson", "Prénom" => "Leah", "Date de Naissance" => "29/03/1997", "Poste" => "Défense"],
            ["Nom" => "Earps", "Prénom" => "Mary", "Date de Naissance" => "07/03/1993", "Poste" => "Gardien"]
        ];
        foreach ($joueur as $j) {
            echo "<tr><td>" . $j["Nom"] . "</td><td>" . $j["Prénom"] . "</td><td>" . $j["Date de Naissance"] . "</td><td>" . $j["Poste"] . "</td><td>" . calculAge($j["Date de Naissance"]) . "</td>";
        }
        echo "</table>";
        echo "<br> <hr>";
        $nom = 'Harry';
        setlocale(LC_TIME, 'fr_FR.UTF-8');
date_default_timezone_set('Europe/Paris');
        echo "Bonjour tout le monde \n";
        echo strftime('%A %d %B %Y, %H:%M:%S');


        
    ?>
</body>
</html>