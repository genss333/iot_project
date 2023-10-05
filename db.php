<?php

$servername = "localhost";

$username = "root";

$password = "";

$databasename = "iotdb";

$conn = new

mysqli($servername, $username, $password, $databasename);

if ($conn->connect_error) {
    echo "Connection failed: " . $conn->connect_error;
}

$conn->set_charset("utf8mb4");

?>