<div class="navbar">
  <div class="navbar-inner">
    <ul class="nav">
      <li><a href="index.php">Home</a></li>
      <li><a href="quote.php">Geat a quote</a></li>
      <li><a href="buy.php">Buy</a></li>
      <li><a href="sell.php">Sell</a></li>
      <li><a href="logout.php">Log Out</a></li>
      <li><a href="password.php">My Account</a></li>
    </ul>
  </div>
</div>
<div class="row-fluid">
    <div class="span1"></div>
    <div class="span10">
        <?php if (empty($transactions)):  // don't print table if history is empty?>
        <b>Your history is empty!</b>      
        <?php else:?>
        <table class="table table-striped">
            <thead>
                <tr>                
                <?php foreach ($transactions[0] as $key => $value): //print headers?>
                    <th><?= $key?></th>
                <? endforeach ?>
                </tr>
            </thead>
            <tbody>            
            <?php foreach ($transactions as $transaction): //iterate over positions rows?>
                <tr>
                    <?php foreach ($transaction as $column): //print values in row?>
                    <td><?= $column ?></td>
                    <? endforeach ?>
                </tr>
            <? endforeach ?>
            </tbody>
        </table>
        <? endif ?>
    </div>
</div>


