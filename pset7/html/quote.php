<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
                
        // validate submission
        if (empty($_POST["symbol"]))
        {
           echo "Please enter a valid stock symbol!";
           exit;
        }
        
        // look up the symbol
        $stock = lookup($_POST["symbol"]);
        
        // apologize if failed to locate stock
        if($stock === false)
        {
            echo "Could not locate stock.  Please check symbol is valid and try again!";
            exit;
        }
        
        // else render quote          
            
        $price = number_format($stock['price'],2);
        
        echo $stock["symbol"] .":  " .$price;

             
           
    }   
    else
    {
        render("quote_form.php", ["title" => "Get a quote"]);
    }
?>
