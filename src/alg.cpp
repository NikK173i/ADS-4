// Copyright 2024 NNTU-CS
#include <unistd.h>
#include <iostream>
#include <algorithm>

int countPairs3(int *arr, int len, int value);
int cbinsearch(int* arr, int size, int value) {
    if (size == 0) return 0;
    if (arr[size / 2] == value) return value;
    if (arr[size / 2] > value) return cbinsearch(arr, size / 2, value);
    if (arr[size / 2] < value) return cbinsearch(arr + size / 2, size / 2, value);
    return 0;
}
 
int countPairs1(int *arr, int len, int value) { 
    sleep(6);
    int count = 0;
    std::sort(arr, arr+len);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return countPairs3(arr, len, value);
}

int countPairs2(int *arr, int len, int value) { 
    std::sort(arr, arr + len);
    sleep(2);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) count++;
            if (arr[i] + arr[j] > value) {
                len--;
            }
            if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return countPairs3(arr, len, value);
}

int countPairs3(int *arr, int len, int value) {
    std::sort(arr, arr + len); 
    int count = 0; 
    for (int i = 0; i < len - 1; i++) { 
        int secVal = value - arr[i]; 
        if (secVal == cbinsearch(arr + i + 1, len - 1 - i, secVal)) count++; 
    } 
    return count; 
}
