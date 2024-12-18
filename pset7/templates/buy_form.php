<form id="form-buy" action="buy.php" method="post">
    <fieldset>
        <div class="control-group">
            <input autofocus autocomplete="off" name="symbol" placeholder="Symbol" type="text"/>
        </div>
        <div class="control-group">
            <input autocomplete="off" name="quantity" placeholder="Quantity" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Buy</button>
        </div>
    </fieldset>
    <div id="message"></div>
</form>

<script type="text/javascript" src="/js/buy.js"></script>
