function insertionsort (nums,size) {
  for (let i = 1; i < size; i++) {
    let j = i - 1
    let temp = nums[i]
    while (j >= 0 && nums[j] > temp) {
      nums[j + 1] = nums[j]
      j--
    }
    nums[j+1] = temp
  }
  return nums
}

times = []

for (i = 0; i < 1000; ++i) {
	nums = Array.from({length: 100000}, () => Math.floor(Math.random() * 100000));
	now = Date.now();
	insertionsort(nums,100000);
	later = Date.now();
	times.push(later - now);
}
console.log(times.reduce((a,b) =>   a+b) / times.length)
