<div class="navbar">
  <div class="navbar-inner">
    <ul class="nav">
      <li class="active"><a href="index.php">Home</a></li>
      <li><a href="quote.php">Geat a quote</a></li>
      <li><a href="logout.php">Log Out</a></li>
    </ul>
  </div>
</div>
<div class="row-fluid">
    <div class="span2"></div>
    <div class="span8">
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
    </div>
</div>
<div class="row-fluid">
    Available funds:  <b><?= "$".$cash ?></b>
</div>

