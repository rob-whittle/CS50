<?php

    // configuration
    require("../includes/config.php");

    // logged in user's id is stored in SESSION
    $id = $_SESSION["id"];
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]) )
        {
           echo "Please enter a valid stock symbol!";
           exit;
        }
        
        // validate submission
        if (empty($_POST["quantity"]))
        {
           echo "Please enter a whole number of shares!";
           exit;
        }
        
        // check user entered an integer number of shares
        if (!preg_match("/^\d+$/", $_POST["quantity"]))
        {
            echo "Please enter a valid (whole) number of shares!";
            exit;
        }
        
        // look up the symbol
        $symbol = strtoupper($_POST["symbol"]);
        $stock = lookup($symbol);
        if($stock === false)
        {
            echo "Could not locate stock.  Please check symbol is valid and try again!";
            exit;
        }
        
        // extract stock price
        $price = $stock['price'];
        
        // check available funds
        $balance = query("SELECT cash FROM users where id = ?", $id);
        
        // confirm funds sufficient to buy shares
        $value = $price * $_POST["quantity"];
        if ($value > $balance[0]['cash'])
        {
            echo "Insufficient funds!";
            exit;
        }
        
        // else buy the shares and update portfolio and balance
        else
        {
        
        // Add new shares to portfolio
        query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE 
                shares = shares + VALUES(shares)", $id, $symbol, $_POST["quantity"]);
       
        // update balance
        query("UPDATE users SET cash = cash - ? WHERE id = ?", $value, $id);
        $cash = number_format($balance[0]['cash'] - $value,2); 
        
        // update history
        query("INSERT INTO history (id, symbol, shares, price, transaction) VALUES(?, ?, ?, ?, ?)", $id, $symbol, $_POST["quantity"], $price, 1);
        
        // redirect to portfolio
        echo "Successfully purchased " . $_POST["quantity"] . " share(s) in " . $stock["name"] . " | Your new balance is: $".$cash;
        exit;
        }
    
    }
            
    // else render buy_form
    else
    {   
        render("buy_form.php", ["title" => "Sell"]);
    }
?>
