// wait for entire page to be loaded before proceeding
$(document).ready(function() {  

    // load data via ajax when form is submitted
    $('#form-buy').on('submit', function() {
    
        // determine symbol typed in input box
        var symbol = $('#form-buy input[name=symbol]').val();
        var quantity = $('#form-buy input[name=quantity]').val();
        
        //send request to buy.php
        $.ajax({
            url: 'buy.php',
            type: 'POST',
            data: {
                symbol: symbol,
                quantity: quantity
            },
            success: function(response) {
                $('#message').text(response);
            }
        });
        
        //since we're overriding form submission, make sure it doesn't submit 
        return false;
    });
});

