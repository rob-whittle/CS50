// wait for entire page to be loaded before proceeding
$(document).ready(function() {  

    // load data via ajax when form is submitted
    $('#form-password').on('submit', function() {
    
        // determine symbol typed in input box
        var oldpassword = $('#form-password input[name=oldpassword]').val();
        var newpassword = $('#form-password input[name=newpassword]').val();
        var confirmation = $('#form-password input[name=confirmation]').val();
        
        //send request to password.php
        $.ajax({
            url: 'password.php',
            type: 'POST',
            data: {
                oldpassword: oldpassword,
                newpassword: newpassword,
                confirmation: confirmation
            },
            success: function(response) {
                $('#message').text(response);
            }
        });
        
        //since we're overriding form submission, make sure it doesn't submit 
        return false;
    });
});

