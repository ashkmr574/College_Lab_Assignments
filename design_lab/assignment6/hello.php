<!--
Author :- Ashish Kumar
Program Name: Hello.php
Purpose :- Get a name as input and print Hello <name>
Assignment Number :- 6

Instruction:- Download the file and put in C://xampp/htdocs folder. Now run the xampp server and in browser type localhost:port_number/filename.php.
where port_number is the port in which your apache server is running and filename is name of the file. Here it will be hello.php
-->
<html>
<head>
	<title>Greeting</title>
</head>
<body bgcolor="blue">
	<center>
	<form method='post'>
	<table>
	<tr>
	<th>Enter your Name:</th> 
	<td><input type="text" name="nm"></td>      <!-- text-box for input -->
	</tr>
	<tr>
	<td></td>
	<td><input type="submit" name="submit" value="submit"></td>   <!-- Submit Button -->
	</tr>
	<table>
	</form>
	</center>
</body>
</html>
<?php
	if(isset($_POST['submit']))
	{
		$name=$_POST['nm'];
		if($name)
			echo '<b>Hello,'.($_POST['nm']).'!</b>';
		else
			echo '<b>Please Enter Your Name and Submit Again!</b>';
	}
?>