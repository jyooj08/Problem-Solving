function solution(nums) {
    let n = nums.length/2;
    const set = [...new Set(nums)];
    return n > set.length ? set.length : n;
}