<?php
    include 'db.php';

    $name = $_POST['id'];
    
    foreach ($name as $id) {
        $sql = "SELECT * FROM `tbdevices` WHERE `id` = '$id'";
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        if ($row["status"] == "ON") {
            $action = "OFF";
        } else {
            $action = "ON";
        }
        $sql = "UPDATE `tbdevices` SET `status` = '$action' WHERE `id` = '$id'";
        $result = $conn->query($sql);
    }
    header("Location: index.php");
?>