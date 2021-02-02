<?php
$servername = "localhost";
$username = "root";
$password = "";
try {
$connection = new PDO("mysql:host=$servername;dbname=karasu", 
$username, $password, array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
// set the PDO error mode to exception
$connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch(PDOException $e)
{
echo "Connection failed: " . $e->getMessage();
}
?>





