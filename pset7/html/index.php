<?php

    // configuration
    require("../includes/config.php"); 
    
    // logged in user's id is stored in SESSION
    $id = $_SESSION["id"];
    
    // query users balance
    $balance = query("SELECT cash FROM users where id = ?", $id);
    // format number and extract value to single variable
    $cash = number_format($balance[0]['cash'],2); 
    
    // query users portfolio
    $portfolio = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $id); 
     
    // iterate over each row of portfolio and get the price from lookup
    $positions = [];
    foreach ($portfolio as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"], 
                "symbol" => strtoupper($row["symbol"]),                               
                "shares" => $row["shares"],
                "price" => $stock["price"]              
            ];
        }
    }
    //dump($positions); 

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);

?>
