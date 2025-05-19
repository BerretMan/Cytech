<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $file = "mediateque.json";
    $tab = file_get_contents($file);
    $array_data = json_decode($tab, true);
    if ($array_data === null) {
        $array_data = []; 
    }
    $ajout = [
        'realisateur' => $_POST['realisateur'],
        'annee de realisation' => $_POST['annee'],
        'titre' => $_POST['titre'],
        'duree' => $_POST['duree']
    ];
    $array_data[] = $ajout;
    $final_data = json_encode($array_data, JSON_PRETTY_PRINT);  
    if ($final_data !== false) {
        file_put_contents($file, $final_data);
    } else {
        echo "Erreur d'encodage JSON.";
    }
}
?>