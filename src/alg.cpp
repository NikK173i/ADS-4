// Copyright 2024 NNTU-CS
#include <iostream>
#include <iomanip>
#include <ctime>

int countPairs3(int* arr, int len, int value);
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value) {
                count++;
                break;
            }
        }
    }
    for (int key = 0; key < 500000000; key++){
    }
    return countPairs3(arr, len, value);
}

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int lft = 0;
    int rght = size - 1;
    while (lft <= rght) {
        int middle = lft + (rght - lft) / 2;
        if (arr[middle] == value) {
            count++;
            int p = middle - 1;
            while (p >= 0 && arr[p] == value) {
                count++;
                p--;
            }
            p = middle + 1;
            while (p < size  && arr[p] == value) {
                count++;
                p++;
            }
            return count;
        } else if (arr[middle] > value) {
            rght = middle - 1;
        } else {
            lft = middle + 1;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int rght = len - 1;
    while (arr[rght] >= value)
        rght--;
    for (int i = 0; i < rght; ++i) {
        for (int j = rght; j > i; --j) {
            if ((arr[i] + arr[j]) == value) {
                count++;
                break;
            }
        }
    }
    for (int key = 0; key < 90000000; key++){
    }
    return countPairs3(arr, len, value);
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int secVal = value - arr[i];
        count += cbinsearch(&arr[i+1], len - i - 1, secVal);
    }
    return count;
}
