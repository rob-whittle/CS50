<form id="form-quote" action="quote.php" method="post">
    <fieldset>
        <div class="control-group">
            <input autofocus name="symbol" placeholder="Symbol" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Get Quote</button>
        </div>
    </fieldset>
    <div id="price"></div>
    <div id="sugestions"></div>
</form>
<div>
       
       <?php if (isset($quote)): ?>
       <b>$<?= htmlspecialchars($quote["price"]) ?></b>
       <?php else: ?>
       <?= htmlspecialchars($message) ?>
       <?php endif ?>
</div>

<script type="text/javascript" src="/js/symbols.js"></script>
<script type="text/javascript" src="/js/quote.js"></script>
