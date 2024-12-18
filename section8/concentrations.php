<select name="concentration">
    <option></option>     
    <?php
        $list = file("concentrations.txt");
        foreach ($list as $key => $subject)
        {
            echo '<option value="' . $key . '">' . $subject . '</option>'; 
        }
    ?>
<select>
