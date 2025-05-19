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
        session_start();
        $nombre=rand(0,336531);

        $file = "mot.txt";
        $ligne = file($file);
        $_SESSION["mot"]=trim($ligne[$nombre]);
        $_SESSION["coup"]=0;
        $_SESSION["lettres"]="";
        $_SESSION["victoire"]=false;
    ?>

    <div class="game">
        <h1>Le jeu du pendu</h1>
        <div class="keyboard">
            <div>
                <button id="a">a</button>
                <button id="z">z</button>
                <button id="e">e</button>
                <button id="r">r</button>
                <button id="t">t</button>
                <button id="y">y</button>
                <button id="u">u</button>
                <button id="i">i</button>
                <button id="o">o</button>
                <button id="p">p</button>
            </div>
        <div>
            <button id="q">q</button>
            <button id="s">s</button>
            <button id="d">d</button>
            <button id="f">f</button>
            <button id="g">g</button>
            <button id="h">h</button>
            <button id="j">j</button>
            <button id="k">k</button>
            <button id="l">l</button>
            <button id="m">m</button>
        </div>
        <div>
            <button id="w">w</button>
            <button id="x">x</button>
            <button id="c">c</button>
            <button id="v">v</button>
            <button id="b">b</button>
            <button id="n">n</button>
        </div>
    </div>
    <div class="result">
        <p id="result"></p>
    </div>

    
    <script src="pendu.js"></script>
</body>
</html>