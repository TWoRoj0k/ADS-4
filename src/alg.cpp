// Copyright 2021 NNTU-CS
static int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value)
                ++count;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int idx = binarySearch(arr, left, right, target);
        if (idx != -1) {
            // Подсчёт всех вхождений target
            int first = idx;
            while (first > left && arr[first - 1] == target)
                --first;
            int last = idx;
            while (last < right && arr[last + 1] == target)
                ++last;
            count += (last - first + 1);
            // Пропускаем дубликаты arr[i]
            while (i + 1 < len && arr[i + 1] == arr[i])
                ++i;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int leftVal = arr[left];
            int rightVal = arr[right];
            if (leftVal == rightVal) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 1;
                while (left + leftCount < right && arr[left + leftCount] == leftVal)
                    ++leftCount;
                int rightCount = 1;
                while (right - rightCount > left && arr[right - rightCount] == rightVal)
                    ++rightCount;
                count += leftCount * rightCount;
                left += leftCount;
                right -= rightCount;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}
