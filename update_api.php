<?php 
include 'db.php';
//close warning
error_reporting(E_ERROR | E_PARSE);

$id = $_GET['id'];
$sql = "UPDATE `tbdevices` SET `status` = 'OFF' WHERE `tbdevices`.`id` = '$id'";
$result = $conn->query($sql);
header('Content-Type: text/html; charset=utf-8');
echo json_encode($id);
?>