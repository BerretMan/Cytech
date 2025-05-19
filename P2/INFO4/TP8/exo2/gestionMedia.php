<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
    
</head>
<body>
   <?php
    $file=file_get_contents("mediateque.json");
    $json=(array)json_decode($file);

    echo "<table>";
    echo "<th>realisateur</th><th>titre</th><th>duree</th><th>annee de realisation</th>";
    foreach($json as $film) {
        echo "<tr> <td>$film->realisateur</td><td>$film->titre</td><td>$film->duree</td><td>" . $film->{'annee de realisation'} . "</td></tr>";
    }
    echo "</table>";

   ?> 

   <form id="leform">
        <label>realisateur</label>
        <br>
        <input name="realisateur" type="text">
        <br>
        <label>titre</label>
        <br>
        <input name="titre" type="text">
        <br>
        <label>duree (en minutes)</label>
        <br>
        <input name="duree" type="number">
        <br>
        <label>annee de realisation</label>
        <br>
        <input name="annee" type="number">
        <br>
        <button action="submit">Ajouter un film</button>

   </form>

   <p id="res"></p>

   <script src="formulaire.js"></script>
</body>
</html>