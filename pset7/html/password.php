<?php

    // configuration
    require("../includes/config.php");
    
    // logged in user's id is stored in SESSION
    $id = $_SESSION["id"];

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        
        // check old password entered correctly
        // get existing password hash from database
        $hash = query("SELECT hash FROM users WHERE id = ?", $id);
        
        // compare hash of user's input against hash that's in database
        if (crypt($_POST["oldpassword"], $hash[0]["hash"]) !== $hash[0]["hash"])
        {
            echo "Sorry! Current password is incorrect";
            exit;
        }           
        else if (empty($_POST["oldpassword"]))
        {
            echo "Please enter your current password.";
            exit;
        }       
        else if (empty($_POST["newpassword"]))
        {
            echo "Please provide a new password.";
            exit;
        }
        else if ($_POST["newpassword"] !== $_POST["confirmation"])
        {
            echo "New Password and Confirmation do not match.";
            exit;
        } 
               
        // attempt to change password
        $rows = query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["newpassword"]), $id); 

        // apologize on failure to change password
        if($rows === false)
        {
            echo "Failed to update password. Please try again later!";
            exit;
        }
               
        // redirect to portfolio
        else
        {
        echo "Password succesfully changed!";
        exit;
        }
    
    }   
    else
    {
        // else render form
        render("password_form.php", ["title" => "Change Password"]);
    }

?>
