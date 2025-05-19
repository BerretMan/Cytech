<?php
session_start();

$score =0;

for($i=1;$i<=20;$i++) {
    if($_POST[(string)$i]*$i ==$_SESSION["nombre"]*$i) {
        $score++;
    }
}

echo "<form method='POST' id='f'>";
for ($i=1;$i<=11;$i++) {
    echo "<label>" . $_SESSION["nombre"] . "x" . $i . "</label><input type=number name='" . $i . "' value='" . $_SESSION["nombre"]*$i . "'/><br>";
}
echo "</form>";
echo "Le résultat est de " . $score . ".";
?>