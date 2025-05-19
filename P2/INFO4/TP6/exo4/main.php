<?php
        session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form method="POST" id="f">
    <?php
        $nombre=random_int(0,20);
        $_SESSION["nombre"]= $nombre;
        for ($i=1;$i<=11;$i++) {
            echo "<label>" . $nombre . "x" . $i . "</label><input type=number name='" . $i . "'/><br>";
        }
    ?>

    <input type="submit">
    </form>
    <p id="res"></p>
    <script src="main.js"></script>
</body>
</html>