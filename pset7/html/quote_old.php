<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            render("quote_form.php", ["title" => "Get a quote", "message" => "Please enter a valid stock symbol"]);
            exit;
        }
        
        // look up the symbol
        $stock = lookup($_POST["symbol"]);
        
        // apologize if failed to locate stock
        if($stock === false)
        {
            render("quote_form.php", ["title" => "Get a quote", "message" => "Sorry! Could not find symbol!"]);
            exit;
        }
        
        // else render quote          
        else
        {
            render("quote_form.php", ["title" => "Get a quote", "quote" => $stock]);
            exit;
        }
             
           
    }   
    else
    {
        render("quote_form.php", ["title" => "Get a quote", "message" => "Enter a symbol!"]);
    }
?>
