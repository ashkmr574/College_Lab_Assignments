<?php
/*Name: Uploading PHP files
Author: Ashish Kumar
 Purpose:  Uploading csv file and showing details
 */
session_start();
?>
<html>
<head>
	<title>File Upload</title>
</head>
<body bgcolor="blue">
<center>
	<form method='post'  enctype="multipart/form-data">    <!--Form for getting csv file -->
	<table>
	<tr>
	<th>Upload a File: </th> 
	<td><input type='file' name='myfile'></td>
	</tr>
	<tr>
	<td></td>
	<td><input type="submit" name="submit" value="Upload"></td>
	</tr>
	<table>
	</form>
	</center>
</body>
</html> 
<?php
	if(isset($_POST['submit']))
	{
			$name= $_FILES["myfile"]["name"];        //Storing file variables
			$type= $_FILES["myfile"]["type"];
			$size= $_FILES["myfile"]["size"];
			$temp= $_FILES["myfile"]["tmp_name"];
			$error= $_FILES["myfile"]["error"];
			if ($error > 0)
				die("Error uploading file! code $error.");   // checking error in file upload
			else
			{
				if(($type=="text/csv")||($type=="application/vnd.ms-excel"))   //checking file type
				{
					move_uploaded_file($temp,$name);
					echo "Upload complete!";
					$_SESSION['name']=$name;
					header('Location:table_022.php');  //calling table_022.php
				}
				else
				{
					echo "This File format is not allowed";
				}
			}
	}
?>