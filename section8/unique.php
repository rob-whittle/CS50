#include usr/bin/php

<?php


// open a file
if ($argc !== 2)
    exit(1);

// read in file line by line
//$lines = file($argv[1]);

$lines = file('http://www.bbc.co.uk');

// prep a new array to store unique lines from file
$arr = [];

// for each line in file store in the array the lines of the file
// such that the array key is the line and therefore duplicates
// will overwrite exisiting data at that index
// $aar's keys are the unique lines from the file
foreach ($lines as $line)
{
    $arr[$line] = $line;
}

// sort the array
sort($arr);

// print the sorted array
foreach ($arr as $line)
{
    echo $line;
}

// foreach ($array as $key => $value)

    
    
    
