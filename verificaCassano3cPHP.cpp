//
// Created by Federico Cassano on 28/04/2020.
//
//<!DOCTYPE html>
//<html>
//<body>
//
//<?php
//        $stringa="Hello world!";
//$lun=strlen($stringa);
//echo "La stringa '$stringa' e' lunga $lun caratteri\n";
//?>

//</body>
//</html>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string stringa = "Hello world!";
    int lun = stringa.length();
    cout << "La stringa 'stringa' e' lunga " << lun << " caratteri\n";
}