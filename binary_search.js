function binary_search(low, high, arr, target) {
    while (low <= high) {
        let mid = Math.floor(low + (high - low) / 2);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
             low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return "not in array";
}
let nums = [];
for (let i = 0; i < 100; i++) {
    nums.push(i);
}
let n = nums.length;
console.log(binary_search(0, n-1, nums, 54));
console.log(binary_search(0, n-1, nums, 12));
console.log(binary_search(0, n-1, nums, 78));
console.log(binary_search(0, n-1, nums, 101));