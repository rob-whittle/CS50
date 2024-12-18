// wait for entire page to be loaded before proceeding
$(document).ready(function() {  

    // load data via ajax when form is submitted
    $('#form-sell').on('click', function() {
    
        // determine symbol typed in input box
        var symbol = $('#form-sell select[name=symbol]').val();
        
        //send request to quote.php
        $.ajax({
            url: 'quote.php',
            type: 'POST',
            data: {
                symbol: symbol
            },
            success: function(response) {
                $('#price').text(response);
            }
        });
        
        //since we're overriding form submission, make sure it doesn't submit 
        //return false;
    });
});

