<?php

    // configuration
    require("../includes/config.php"); 
    
    // logged in user's id is stored in SESSION
    $id = $_SESSION["id"];
    
    // query users history
    $history = query("SELECT date, symbol, shares, price, transaction FROM history WHERE id = ?", $id);        
            
    // iterate over each row of history and get the price from lookup
    $transactions = [];
    foreach ($history as $row)
    {
        $transactions[] = [
            "date" => $row["date"], 
            "symbol" => $row["symbol"],                               
            "shares" => $row["shares"],
            "price" => "$".$row["price"],
            "type" => $row["transaction"] == 1 ? "BUY" : "SELL"           
        ];

    }
    
    
    // render portfolio
    render("history_form.php", ["transactions" => array_reverse($transactions), "title" => "Portfolio"]);

?>
