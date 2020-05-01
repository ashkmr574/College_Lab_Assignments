<?php
/*Name: Uploading PHP files
Author: Ashish Kumar
 Purpose:  Uploading csv file and showing details
 */
	session_start();
?>
<html>
<body bgcolor='blue'>
<center>
<table border='1' bgcolor='red'>    <!--table for printing details --> 
	<tr>
	<th>FIRST NAME</th> 
	<td><?php echo $_GET['first']; ?></td>
	</tr>
	<tr>
	<th>LAST NAME</th> 
	<td><?php echo $_GET['last']; ?></td>
	</tr>
	<tr>
	<th>EMAIL</th> 
	<td><?php echo $_GET['email']; ?></td>
	</tr>
	<tr>
	<th>GENDER</th> 
	<td><?php echo $_GET['gender']; ?></td>
	</tr>
	<table>
	</center>
</body>
</html>