<?php

    // configuration
    require("../includes/config.php");

    // logged in user's id is stored in SESSION
    $id = $_SESSION["id"];
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
           exit;
        }
        
        // look up the symbol
        $symbol = strtoupper($_POST["symbol"]);
        $stock = lookup($_POST["symbol"]);
        
        // extract stock price
        $price = $stock['price'];
        
        // Get number of shares owned from portfolio
        $shares = query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?", $id, $_POST["symbol"]);
        //dump($shares[0]["shares"]);
        
        // calculate value of shares
        $value = $price * $shares[0]["shares"];
        
        // update portfolio
        query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $id, $symbol);
        
        
        // update balance
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $id);
        
        // update history
        query("INSERT INTO history (id, symbol, shares, price, transaction) VALUES(?, ?, ?, ?, ?)", $id, $symbol, $shares[0]["shares"], $price, 0);
        
        // redirect to portfolio
        redirect("/");
    
    }
            
    // else get portfolio to populate drop down list
    else
    {   
        // query users portfolio
        $portfolio = query("SELECT symbol FROM portfolio WHERE id = ?", $id); 

        // render sell list
        render("sell_form.php", ["positions" => $portfolio, "title" => "Sell"]);
    }
?>
