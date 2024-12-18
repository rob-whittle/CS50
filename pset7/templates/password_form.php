<form id="form-password" action="password.php" method="post">
    <fieldset>
        <div class="control-group">
            <input autofocus autocomplete="off" name="oldpassword" placeholder="Current password" type="password"/>
        </div>
        <div class="control-group">
            <input autocomplete="off" name="newpassword" placeholder="New password" type="password"/>
        </div>
        <div class="control-group">
            <input autocomplete="off" name="confirmation" placeholder="Confirm new password" type="password"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Confirm</button>
        </div>
    </fieldset>
    <div id="message"></div>
</form>

<script type="text/javascript" src="/js/password.js"></script>
