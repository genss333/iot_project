<?php
include 'db.php';

$sql = "SELECT * FROM `tbdevices`";

$result = $conn->query($sql);

$arrLed

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css" type="text/css">
</head>

<body>
    <div class="container">
        <form action="update.php" method="post">
            <table class="table">
                <thead>
                    <tr>
                        <th scope="col"># id</th>
                        <th scope="col">Device Name</th>
                        <th scope="col">Status</th>
                        <th scope="col"></th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    if ($result->num_rows > 0) {
                        while ($row = $result->fetch_assoc()) { ?>
                            <tr>
                                <td><?php echo $row["id"] ?></td>
                                <td>
                                    <a href="clock.php?id=<?php echo $row["id"] ?>"><?php echo $row["detail"] ?></a>
                                </td>
                                <td>
                                    <span class="badge rounded-pill <?php
                                                                    if ($row["status"] == "ON") {
                                                                        echo "bg-info";
                                                                    } else {
                                                                        echo "bg-danger";
                                                                    }
                                                                    ?>"><?php echo $row["status"] ?>
                                    </span>
                                </td>
                                <td>
                                    <input class="form-check-input" name="id[]" type="checkbox" value="<?php echo $row["id"] ?>" id="flexCheckChecked">
                                </td>
                            </tr>
                    <?php    }
                    }
                    ?>
                </tbody>
            </table>
            <br>
            <div class="footer">
                <div class="container">
                    <div class="row p-3">
                        <a class="btn btn-success" href="add.php">เพิ่มอุปกรณ์</a>
                    </div>
                    <div class="row p-3">
                        <input type="submit" value="Submit" class="btn btn-primary">
                    </div>
                </div>
            </div>
        </form>
    </div>
</body>

</html>