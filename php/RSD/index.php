<?php

////////////////////////////////////////////////////////////
//
//  Rhapsody for the scarlet devil
// Copyright (C) 2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
//
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


require("db.php.inc");

if(isset($_GET['action'])){
	if($_GET['action'] = 'ping'){
		if(isset($_GET['n']) AND isset($_GET['p']) AND is_numeric($_GET['p'])){
			$sql = "
				SELECT lastUp
					FROM RSD_users
					WHERE
						name = '".addslashes($_GET['n'])."'
				;
			";
			$search = mysql_query($sql);
			$data  	= mysql_fetch_row($search);
			if(isset($data[0])){
				$sql = "
					UPDATE RSD_users
						SET
							lastUp = ".time().",
							IP = '".$_SERVER["REMOTE_ADDR"]."',
							port = '".$_GET['p']."'
						WHERE
							name = '".addslashes($_GET['n'])."'
					;
				";
				
				mysql_query($sql);
			}
			else{
				$sql = "
					INSERT INTO RSD_users
						(`IP`,`name`,`port`,`lastUp`)
						VALUE(
							'".$_SERVER["REMOTE_ADDR"]."',
							'".addslashes($_GET['n'])."',
							'".$_GET['p']."',
							".time()."
						)	
					;
				";
				
				mysql_query($sql);
			}
		}
		echo 'pong';
	}
	elseif($_GET['action'] == 'view'){
		Header("content-type: application/xml");
		$sql = "
				SELECT name,IP,port,lastUp
					FROM RSD_users
					WHERE
						name = '".addslashes($_GET['n'])."'
				;
			";
			$search = mysql_query($sql);
			echo '
<list>';
			while($data = mysql_fetch_row($search)){
				echo '
	<user name="',$data[0],'" IP="',$data[1],'" port="',$data[2],'" last="',$data[3],'"/>';
			}
			echo '
</list>';
	}
}
?>
