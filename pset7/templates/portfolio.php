<div class="navbar">
  <div class="navbar-inner">
    <ul class="nav">
      <li><a href="index.php">Home</a></li>
      <li><a href="quote.php">Geat a quote</a></li>
      <li><a href="buy.php">Buy</a></li>
      <li><a href="sell.php">Sell</a></li>
      <li><a href="history.php">History</a></li>
      <li><a href="logout.php">Log Out</a></li>
      <li><a href="password.php">My Account</a></li>
    </ul>
  </div>
</div>
<div class="row-fluid">
    <div class="span2"></div>
    <div class="span8">
        <?php if (empty($positions)):  // don't print table if portfolio is empty?>
        <b>Your portfolio is empty!  Buy something!</b>      
        <?php else:?>
        <table class="table table-striped">
            <thead>
                <tr>                
                <?php foreach ($positions[0] as $key => $value): //print headers?>
                    <th><?= $key?></th>
                <? endforeach ?>
                </tr>
            </thead>
            <tbody>            
            <?php foreach ($positions as $position): //iterate over positions rows?>
                <tr>
                    <?php foreach ($position as $column): //print values in row?>
                    <td><?= $column ?></td>
                    <? endforeach ?>
                </tr>
            <? endforeach ?>
            </tbody>
        </table>
        <? endif ?>
    </div>
</div>
<div class="row-fluid">
    Available funds:  <b><?= "$".$cash ?></b>
</div>

