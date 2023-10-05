<?php
include 'db.php';
//close warning
error_reporting(E_ERROR | E_PARSE);

if ($_SERVER['REQUEST_METHOD'] == "GET") {
    $id = $_GET['id'];
    if ($id == null) {
        $sql = "SELECT COUNT(status) as status FROM tbdevices WHERE status = 'ON'";
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        header('Content-Type: text/html; charset=utf-8');
        echo json_encode($row);
    } else {
        $sql = "SELECT * FROM `tbdevices` WHERE `id` = '$id'";
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        header('Content-Type: text/html; charset=utf-8');
        echo json_encode($row);
    }
}
