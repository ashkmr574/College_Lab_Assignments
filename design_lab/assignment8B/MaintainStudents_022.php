<!--
Name: Student Data Maintenance
Author:- Ashish Kumar
Purpose:- To Develop PHP script(s) for maintaining student details (roll no, first name, last name, department, email, geneder) in a small engineering college.
 To maintenance following operations: add, modify, delete and query. Student records can be added with manual entries as well as file uploads, however roll no
 should be automatically generated. Roll no must be with 11 characters: CSE2013-nnn where nnn is  a running serial number starting from 1 (start) to 30 (max).
 To save records either in file or in MySQL database.
-->
<?php
/*
This piece of code is used to create the database of students if not already created and also includes code for connecting to
the mysql database.
*/

session_start();                              // session start
$server="localhost";                          //server name
$user="root";                                 //user name
$pass="";                                     // password
$conn= new mysqli($server,$user,$pass);        //connecting to the mysql server
if($conn->connect_error)
{
	die("Connection Failed: ".$conn->connect_error);
}
$sql="CREATE DATABASE IF NOT EXISTS student_022";        // creating database
$stat=$conn->query($sql);
$dbname="student_022";
$conn=mysqli_connect($server,$user,$pass,$dbname);       // connecting to the database created
$sql="CREATE TABLE IF NOT EXISTS Records( roll VARCHAR(30) PRIMARY KEY, first VARCHAR(30), last VARCHAR(30),dept VARCHAR(50), email VARCHAR(50), gender VARCHAR(10)) ";                             // table creation for record storage
$stat=$conn->query($sql);
?>
<html>
<head>
	<title>Student Maintenance</title>
</head>
<body bgcolor="#FFEEDD">
<center>
	<h1>STUDENT RECORD MAINTENANCE SYSTEM</h1>
	<form method='post'  enctype="multipart/form-data">
	<table>
	<tr>
		<td><input type="submit" name="Add_Record" value="Add Record"></td>
		<td><input type="submit" name="Query_Record" value="Query Record"></td>
		<td><input type="submit" name="Delete_Record" value="Delete Record"></td>   <!-- User interface showing diffrenet options -->
		<td><input type="submit" name="Modify_Record" value="Modify Record"></td>
		<td><input type="submit" name="Show_Record" value="View All Records"></td>
	</tr>
	<table>
	</form>
	</center>
</body>
</html>
<?php
	function insert($arr)             // function to insert data
	{
		$roll="";
		$first=$arr[0];
		$last=$arr[1];
		$dept=$arr[2];
		$email=$arr[3];
		$gender=$arr[4];
		$sql="select count(*) as count from Records";     // getting count of total records for auto roll number generation
		$conn1=$GLOBALS['conn'];
		$result=$conn1->query($sql);                      // query execution
		$row=$result->fetch_assoc();                       // result fetching
		$num=$row['count'];
		if($num>0)
		{
			$sql="select * from Records order by roll";
			$result=$conn1->query($sql);
			$i=0;
			while($i<$num)
			{
				$row=$result->fetch_assoc();
				$i=$i+1;
			}
			$str=substr($row['roll'],8,3);
			$num=intval($str);
			$num=$num+1;
			if($num<10)
				$roll="CSE2013-00".$num;            // logic for roll number generation
			elseif($num<100)
				$roll="CSE2013-0".$num;
			else
				$roll="CSE2013-".$num;
		}
		else
			$roll="CSE2013-001";
		$sql="INSERT into Records values('$roll','$first','$last','$dept','$email','$gender')";  //inserting values to database
		$conn1->query($sql);
		echo"Record Added with Roll Number ".$roll."<br/>";
		return $roll;
	}
	function view($arr,$roll)     // function to view single record
	{
		echo"<center><form><table border='1' bgcolor='blue'><tr><th>Roll No</th><td>".$roll."</td></tr>";
		echo"<tr><th>First Name</th><td>".$arr[0]."</td></tr>";
		echo"<tr><th>Last Name</th><td>".$arr[1]."</td></tr>";
		echo"<tr><th>Department</th><td>".$arr[2]."</td></tr>";  //printing records in html table
		echo"<tr><th>Email</th><td>".$arr[3]."</tr>";
		echo"<tr><th>Gender</th><td>".$arr[4]."</td></tr>";
		echo"</table></center>";
	}
	function viewall($result)          // function to view all the records
	{
		if($result->num_rows >0)
		{
			$i=1;
			echo "<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Serial No</th><th>Roll No".
			"</th><th>First Name</th><th>Last Name</th><th>Department</th><th>Email</th><th>Gender</th><th>Option</th></tr>";
			while($row=$result->fetch_assoc())   // printing records in html table
			{
				 echo"<tr><td><input type='text' name='serial'  readonly='true' value='".$i."'</td>".
				     "<td><input type='text' name='rno".$i."'  readonly='true' value='".$row['roll']."'</td>".
				     "<td><input type='text' name='fname'  readonly='true' value='".$row['first']."'</td>".
				     "<td><input type='text' name='lname'  readonly='true' value='".$row['last']."'</td>".
				     "<td><input type='text' name='dept'  readonly='true' value='".$row['dept']."'</td>".
				     "<td><input type='text' name='email'  readonly='true' value='".$row['email']."'</td>".
				     "<td><input type='text' name='gen'  readonly='true' value='".$row['gender']."'</td>".
				     "<td align='center'><input type='submit' name='Modify".$i."' value='Modify'></td></tr>";
				     $i+=1;

			}
			echo"</table></form></center>";
			
		}
		else
			echo "No records Found";
	}
	if(isset($_POST['Add_Record']))  // user interface for getting details to be inserted.
	{
		echo"<center><form method='post'><table border='1' bgcolor='red'>".
		    "<tr><th>First Name</th><td><input type='text' name='fname' required='true'></td></tr>";
		echo"<tr><th>Last Name</th><td><input type='text' name='lname' required='true'></td></tr>";
		echo"<tr><th>Department</th><td><select name='dept' required='true'><option>CSE</option><option>IT</option><option>ECE</option><option>EE</option></td></tr>";
		echo"<tr><th>Email</th><td><input type='email' name='email' required='true'></td></tr>";
		echo"<tr><th>Gender</th><td><input type='radio' name='gen' value='Male'>Male".
		    "<input type='radio' name='gen' value='Female'>Female</td></tr>";
		echo"<tr><td></td><td align='center'><input type='submit' name='Save' value='Add Record'></td></tr>";
		echo"</table></form>";
		echo"<h1>OR</h1>";
		echo"<center><fieldset><legend>File Upload</legend><form method='post' enctype='multipart/form-data'>".  // file upload UI
		    "<table bgcolor='blue'><tr><th>Upload a File :</th><td><input type='file' name='fil' required='true'></td>"
		    ."<td><input type='submit' name='Upload' value='Upload'></td></tr></table></form><p><b>Note:</b>".
		    "The csv file should have first name,last name,department,email and gender in order.</p></fieldset></center>";
	}
	if(isset($_POST['Query_Record']))    // user interface for Query Record
	{
		echo"<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Roll Number</th>".
		    "<td><input type='text' name='rno' required='true'></td></tr>";
		echo"<tr><td></td><td><input type='submit' name='Query' value='Query Record'></td></tr>";
		echo"</table></form></center>";
		echo"<center><h1>OR</h1></center>";
		echo"<center><fieldset><form method='post'>".
		    "<table bgcolor='blue' border='1'><tr><th>First Name</th><td><input type='text' name='fname' required='true'></td></tr>"
		    ."<tr><td></td><td align='center'><input type='submit' name='Query_A' value='Query Record'></td></tr></table></form>".
		    "</fieldset></center>";
		
	}
	if(isset($_POST['Delete_Record']))  // User Interface for Delete Record
	{
		echo"<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Roll Number</th>".
                    "<td><input type='text' name='rno' required='true'></td></tr>";
		echo"<tr><td></td><td><input type='submit' name='Delete' value='Next'></td></tr>";
		echo"</table></form></center>";
		
	}
	if(isset($_POST['Modify_Record']))   // User Interface for Modify Record
	{
		echo"<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Roll Number</th><td>".
		    "<input type='text' name='rno' required='true'></td></tr>";
		echo"<tr><td></td><td><input type='submit' name='Modify' value='Modify Record'></td></tr>";
		echo"</table></form></center>";
	}
	if(isset($_POST['Save']))    // intermediate step of data insertion
	{
		$arr=array();
		$arr[0]=$_POST['fname'];
		$arr[1]=$_POST['lname'];
		$arr[2]=$_POST['dept'];
		$arr[3]=$_POST['email'];
		$arr[4]=$_POST['gen'];
		$roll=insert($arr);     // calling insert function
		view($arr,$roll);
	}
	if(isset($_POST['Query']))      // intermediate step for query record
	{
		$roll=$_POST['rno'];
		$sql="select * from Records where roll='".$roll."'";
		$result=$conn->query($sql);
		if($result->num_rows >0)
		{
			$arr=array();
			$row=$result->fetch_assoc();   // fetching data from database
			$roll=$row['roll'];
			$arr[0]=$row['first'];
			$arr[1]=$row['last'];
			$arr[2]=$row['dept'];
			$arr[3]=$row['email'];
			$arr[4]=$row['gender'];
			view($arr,$roll);      // calling view function to show the record
		}
		else
			echo "No results found for the Roll No. ".$roll;
		
	}
	if(isset($_POST['Query_A']))           // Intermediate step for Query by First Name
	{
		$fname=$_POST['fname'];
		$sql="select * from Records where first='".$fname."'";
		$result=$conn->query($sql);
		if($result->num_rows >0)
		{
			$i=1;
			while($row=$result->fetch_assoc())   // fetching data from tables
			{
				$arr=array();
				echo "<center>Record ".$i;
				$roll=$row['roll'];
				$arr[0]=$row['first'];
				$arr[1]=$row['last'];
				$arr[2]=$row['dept'];
				$arr[3]=$row['email'];
				$arr[4]=$row['gender'];
				view($arr,$roll);        // calling view function to show the record
				$i+=1;
			}
		
		}
		else
				echo "No results found for the First Name. ".$fname;
	}
	if(isset($_POST['Delete']))  // this will show the details before deleting the record
	{
		$roll=$_POST['rno'];
		$sql="select * from Records where roll='".$roll."'";
		$result=$conn->query($sql);
		if($result->num_rows >0)
		{	
			$row=$result->fetch_assoc();
			echo"<center><form method='post'><table border='1' bgcolor='blue'>".
			    "<tr><th>Roll No</th><td><input type='text' name='rno'  readonly='true' value='".$row['roll']."'</td></tr>";
			echo"<tr><th>First Name</th><td><input type='text' name='first'  readonly='true' value='".$row['first']."'</td></tr>";
			echo"<tr><th>Last Name</th><td><input type='text' name='last'  readonly='true' value='".$row['last']."'</td></tr>";
			echo"<tr><th>Department</th><td><input type='text' name='dept'  readonly='true' value='".$row['dept']."'</td></tr>";
			echo"<tr><th>Email</th><td><input type='text' name='email'  readonly='true' value='".$row['email']."'</td></tr>";
			echo"<tr><th>Gender</th><td><input type='text' name='gen'  readonly='true' value='".$row['gender']."'</td></tr>";
			echo"<tr><td></td><td><input type='submit' name='Delete1' value='Delete Record'></td></tr>";
			echo"</table></form></center>";		
		}
		else

			echo "Record not Found";
	}
	if(isset($_POST['Delete1']))   // Actual Detele operation will be performed 
	{
		$roll=$_POST['rno'];
		$sql="select * from Records where roll='".$roll."'";
		$result=$conn->query($sql);
		if($result->num_rows >0)
		{	
				$sql="delete from Records where roll='".$roll."'";  //delete query for database
				$result=$conn->query($sql);
				if($stat==TRUE)
				{
					echo "Record Deleted for roll no ".$roll;
					$sql="select * from Records";
					$result=$conn->query($sql);
					viewall($result);
					echo"<center><form method='post'><input type='submit' name='Update_roll' value='Update Roll Numbers'></form></center>";  // UI for roll number update after record deletion
				}
				
		}
		else
			echo "Record not Found";
		
	}
	if(isset($_POST['Update_roll']))   // this will update the roll numbers after a record deletion
	{
		$y=1;
		$num=1;
		$sql="select count(*) as count from Records";
		$result=$conn->query($sql);
		$row=$result->fetch_assoc();
		$numb=$row['count'];
		for($i=0;$i<$numb;$i+=1)
		{
			$sql="select roll from Records LIMIT ".$i.",".$y;
			$result=$conn->query($sql);
			$row=$result->fetch_assoc();
			$roll_old=$row['roll'];
			if($num<10)
				$roll="CSE2013-00".$num;
			elseif($num<100)
				$roll="CSE2013-0".$num;
			else
				$roll="CSE2013-".$num;
			$sql="UPDATE Records SET roll='".$roll."' WHERE roll='".$roll_old."'";
			$result=$conn->query($sql);
			$num+=1;
		}
		$sql="select * from Records";
		$result=$conn->query($sql);
		viewall($result);
		echo"<center>Roll Numbers Updated<center>";
		
	}
	if(isset($_POST['Modify']))   // UI for Modify record
	{
		$roll=$_POST['rno'];
		$sql="select * from Records where roll='".$roll."'";
		$result=$conn->query($sql);
		if($result->num_rows >0)
		{
		$row=$result->fetch_assoc();	
		echo"<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Roll No</th><td><input type='text' name='roll'  readonly='true' value='".$row['roll']."'</td></tr><tr><th>First Name</th><td><input type='text' name='fname' required='true' value='".$row['first']."'></td></tr>";
		echo"<tr><th>Last Name</th><td><input type='text' name='lname' required='true' value='".$row['last']."'></td></tr>";
		echo"<tr><th>Department</th><td><input type='text' name='dept' required='true' value='".$row['dept']."'></td></tr>";
		echo"<tr><th>Email</th><td><input type='email' name='email' required='true' value='".$row['email']."'></td></tr>";
		if(strcmp($row['gender'],"Male")==0)
		echo"<tr><th>Gender</th><td><input type='radio' name='gen' value='Male' checked='true'>Male<input type='radio' name='gen' value='Female'>Female</td></tr>";
		else
		echo"<tr><th>Gender</th><td><input type='radio' name='gen' value='Male' >Male<input type='radio' name='gen' value='Female' checked='true'>Female</td></tr>";
		echo"<tr><td></td><td align='center'><input type='submit' name='Save2' value='Modify'></td></tr>";
		echo"</table></form></center>";
		}
		else
			echo "Record not Found";
	}
	if(isset($_POST['Save2']))  // THis will actually perform update operation for modifying record
	{
		$roll=$_POST['roll'];
		$first=$_POST['fname'];
		$last=$_POST['lname'];
		$dept=$_POST['dept'];
		$email=$_POST['email'];
		$gender=$_POST['gen'];
$sql="UPDATE Records SET first='".$first."', last='".$last."', dept='".$dept."', email='".$email."', gender='".$gender."' WHERE roll='".$roll."'";  // Query for Update record
		$stat=$conn->query($sql);
		if($stat==TRUE)
		{
			echo"Record Modified for the Roll No ".$roll;
			$arr=array();
			$arr[0]=$first;
			$arr[1]=$last;
			$arr[2]=$dept;
			$arr[3]=$email;
			$arr[4]=$gender;
			view($arr,$roll);
		}
		else
		{
			echo "Error in modification: ".$conn->error;
		}
		
	}
	if(isset($_POST['Show_Record']))   // it will call the showall fuction to show all records
	{
		$sql="select * from Records";
		$result=$conn->query($sql);
		viewall($result);
	}
	/*
		Below lines of codes are are addtional modify option while showing all the records.
	*/
	$sql="select count(*) as count from Records";
	$result=$conn->query($sql);
	$row=$result->fetch_assoc();
	$num=$row['count'];
	for($j=1;$j<=$num;$j+=1)
	{
		$v="Modify".$j;
		if(isset($_POST[$v]))
		{
			$k="rno".$j;
			$roll=$_POST[$k];
			$sql="select * from Records where roll='".$roll."'";
			$result=$conn->query($sql);
			if($result->num_rows >0)
			{
				$row=$result->fetch_assoc();	
				echo"<center><form method='post'><table border='1' bgcolor='blue'><tr><th>Roll No</th><td><input type='text' name='roll'  readonly='true' value='".$row['roll']."'</td></tr><tr><th>First Name</th><td><input type='text' name='fname' required='true' value='".$row['first']."'></td></tr>";
				echo"<tr><th>Last Name</th><td><input type='text' name='lname' required='true' value='".$row['last']."'></td></tr>";
				echo"<tr><th>Department</th><td><input type='text' name='dept' required='true' value='".$row['dept']."'></td></tr>";
				echo"<tr><th>Email</th><td><input type='email' name='email' required='true' value='".$row['email']."'></td></tr>";
				if(strcmp($row['gender'],"Male")==0)
					echo"<tr><th>Gender</th><td><input type='radio' name='gen' value='Male' checked='true'>Male<input type='radio' name='gen' value='Female'>Female</td></tr>";
				else
					echo"<tr><th>Gender</th><td><input type='radio' name='gen' value='Male' >Male<input type='radio' name='gen' value='Female' checked='true'>Female</td></tr>";
				echo"<tr><td></td><td align='center'><input type='submit' name='Save2' value='Modify'></td></tr>";
		echo"</table></form></center>";
			}
			else
				echo "Record not Found";
		}
	}
	if(isset($_POST['Upload']))  // Record insertion through file Upload
	{ 
		$c=0;
		$c1=0;
		$name=$_FILES["fil"]["name"];
    		$type=$_FILES['fil']['type'];
    		$size=$_FILES['fil']['size'];
    		$error=$_FILES['fil']['error'];
    		$tmp_name=$_FILES['fil']['tmp_name'];
		if(strpos($name,'.csv'))  // checking if file is csv file or not
    		{
			move_uploaded_file($tmp_name,$name);  // file upload
			$file=fopen($name,"r");
			while(!feof($file))
			{
				$arr=fgetcsv($file);  // getting a row from csv file
				if(!empty($arr))
				{
					if(sizeof($arr)>=5)
					{
						if(strpos($arr[3],'@')or $arr[3]=="")  // validation of email
						{
							if((strcasecmp($arr[4],'Male')==0) or (strcasecmp($arr[4],'Female')==0)) // validation of gender
							{
								insert($arr);
								$c+=1;
							}
							else
								$c1+=1;
						}
						else
							$c1+=1;
					}
					else
					$c1+=1;
				}
			}
			echo "<p>Add Record Summary:<br/>Total Records = ".($c+$c1)."<br/>Inserted Records = ".
			     $c."<br/>Records Not Inserted =".$c1."<br/><b>Note:</b>Not inserted records are those".
			     " having less than required fileds or email id does not contain @ symbol or gender is not in the set (Male,Female).</p>";
			$sql="select count(*) as count from Records";  // showing insertion summary
			$result=$conn->query($sql);
			$row=$result->fetch_assoc();
			$num=$row['count'];
			$t=($c1+$c);
			$num=$num-$c;
			$sql="select * from Records LIMIT ".$t." OFFSET ".$num ;
			$result=$conn->query($sql);
			viewall($result);    // showing newly inserted record
		}
		else
			echo "File Format is not supported..Try uploading CSV file only";
	}
?>
