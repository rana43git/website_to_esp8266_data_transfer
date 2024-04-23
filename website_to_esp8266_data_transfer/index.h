// HTML content as a string
const char* htmlContent = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP8266 Input</title>
</head>
<body>
    <form action="/update" method="post">
        <input type="text" name="input">
        <input type="submit" value="Submit">
    </form>
</body>
</html>
)=====";