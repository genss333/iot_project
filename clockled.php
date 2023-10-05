<?php 
    include 'db.php';
    $close = $_POST['close'];
    $id = $_GET['id'];

    $sql = "UPDATE `tbdevices` SET `close_date_time` = '$close' WHERE `id` = '$id'";
    $result = $conn->query($sql);
    header("Location: index.php");
?>
