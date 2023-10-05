<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>KP Smart home</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css" type="text/css">

</head>

<body>
    <div class="container">
        <br>
            <h2>กรอกหมายเลขอุปกรณ์เพื่อเชื่อมต่อ และควบคุมบ้านของท่าน</h2>
        <br>
        <form action="addLed.php" method="post">
            <div class="form-group">
                <label for="exampleInputDeviceNumber">กรอกหมายเลขอุปกรณ์</label>
                <input type="text" name="id" class="form-control">
            </div>
            <br>
            <div class="form-group">
                <label for="exampleInputDeviceNumber">กรอกชื่ออุปกรณ์</label>
                <input type="text" name="detail" class="form-control">
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