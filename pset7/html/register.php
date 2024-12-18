<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must choose a username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        else if ($_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Password and Confirmation do not match.");
        }
        
        // attempt to add user to database
        $rows = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"])); 
    
        // apologize on failure to register
        if($rows === false)
        {
            apologize("Registration failed - username may already exist. Please try again!");
        }
        
        // else registration succeeded - get the new users id
        $rows = query("SELECT LAST_INSERT_ID() AS id"); 
        $id = $rows[0]["id"];
        
        // store the id in session
        $_SESSION["id"] = $id;
        
        // redirect to portfolio
        redirect("/");
    
    }   
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
