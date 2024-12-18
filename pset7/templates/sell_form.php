<form id="form-sell" action="sell.php" method="post">
    <fieldset>
        <div class="control-group">
            <select name="symbol">
                <option value=''></option>
                <?php foreach ($positions as $symbol):?>
                <option value="<?= $symbol['symbol']?>"><?= $symbol['symbol']?></option>
                <? endforeach ?>
            </select>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Sell</button>
        </div>
    </fieldset>
    <div id="price"></div>
</form>

<script type="text/javascript" src="/js/sell.js"></script>
