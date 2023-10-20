<?php
include 'db.php';

$id = $_GET['id'];

$sql = "SELECT * FROM tbdevices WHERE id = '$id' LIMIT 1";

$result = $conn->query($sql);
$item = $result->fetch_assoc();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <title>Document</title>
    <link rel="stylesheet" href="style.css" type="text/css">
</head>

<body>
    <div class="container">
        <br>
        <div class="card" style="width: 18rem;">
            <div class="card-body">
                <h5 class="card-title">
                    <?php echo $item['detail']; ?>
                </h5>
                <span class="badge rounded-pill <?php
                                                if ($item["status"] == "ON") {
                                                    echo "bg-info";
                                                } else {
                                                    echo "bg-danger";
                                                }
                                                ?>"><?php echo $item["status"] ?>
                </span>
            </div>
        </div>
        <br>
        <form action="clockled.php?id=<?php echo $id ?>" method="post">
            <div class="form-group">
                <label for="exampleInputDateTime">ตั้งเวลาปิด</label>
                <input type="time" name ="close" class="form-control">
            </div>
            <div class="footer">
                <div class="container">
                    <div class="row p-3">
                        <input type="submit" value="Submit" class="btn btn-primary">
                    </div>
                </div>
            </div>
        </form>
    </div>
</body>

</html>