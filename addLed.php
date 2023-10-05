<?php 
    include 'db.php';

    $id = $_POST['id'];
    $detatil = $_POST['detail'];

    $sql = "INSERT INTO `tbdevices` (`id`, `status`, `detail`, `close_date_time`) VALUES ('$id', 'OFF', '$detatil', '')";
    
    $result = $conn->query($sql);

    header("Location:index.php");

?>