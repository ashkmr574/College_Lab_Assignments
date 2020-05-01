<?php
/*Name: Uploading PHP files
Author: Ashish Kumar
 Purpose:  Uploading csv file and showing details
 */
session_start();
$file=$_SESSION['name'];   //retrieving filename from session variable
$file=fopen($file,'r');
echo"<center><table border='1' bgcolor='red'><tr><th>First Name</th><th>Last Name</th><th>Email Id</th><th>Gender</th></tr>";
while(!feof($file))
{
	$detail=array();
	$detail=fgetcsv($file);  //taking one row of csv file at a time
	echo"<tr><td><a href='details_022.php?first=$detail[0]&last=$detail[1]&email=$detail[2]&gender=$detail[3]'>$detail[0]</a></td><td>$detail[1]</td><td>$detail[2]</td><td>$detail[3]</td></tr>"; //printing details
}
echo"</table></center>"
?>
<html>
	<body bgcolor="blue">
	</body>
</html>