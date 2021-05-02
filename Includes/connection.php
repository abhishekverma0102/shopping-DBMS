<?php
$servername = "localhost";
$username = "elijah";
$password = "123456";
$site_root = "";
//$GLOBALS['a'] = 'localhost';


$dbname = "shopping";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>