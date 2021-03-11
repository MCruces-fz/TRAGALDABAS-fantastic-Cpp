
#ifndef UTILITIES_H
#define UTILITIES_H

#include <bits/stdc++.h>

using namespace std;

char* to_char(string str) {

    int n = str.length();
    char char_arr[n + 1];
    
    strcpy(char_arr, str.c_str());

    return &char_arr
}

#endif 
