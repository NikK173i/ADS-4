// Copyright 2024 NNTU-CS
#include <iostream>
#include <iomanip>
#include <ctime>

int countPairs3(int* arr, int len, int value);
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count)
        return count;
    return 0;
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
            }
        }
    }
    if (count)
        return count;
    return 0;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int lft = 0;
    int rght = len - 1;
    for (int i = 0; i < len; ++i) {
        int SecVal = value - arr[i];
        while (lft <= rght) {
            int middle = (lft + rght) / 2;
            if (arr[middle] == SecVal) {
                count++;
                int p = middle - 1;
                while (p >= 0 && arr[p] == value) {
                    count++;
                    p--;
                }
                p = middle + 1;
                while (p < len && arr[p] == value) {
                    count++;
                    p++;
                }
                break;
            } else if (arr[middle] > value) {
                rght = middle - 1;
            } else {
                lft = middle + 1;
            }
        }
    }
    if (count)
        return count;
    return 0;
}
