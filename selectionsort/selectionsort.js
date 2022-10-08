function selectionsort(arr,len){
  for (let i = 0; i < len; i++) {
    let lowest = i
    for (let j = i + 1; j < len; j++) {
      if (arr[j] < arr[lowest]) {
        lowest = j
      }
    }
    if (lowest !== i) {
      [arr[i], arr[lowest]] = [arr[lowest], arr[i]];
    }
  }
}


times = []

for (i = 0; i < 1000; ++i) {
	nums = Array.from({length: 100000}, () => Math.floor(Math.random() * 100000));
	now = Date.now();
	selectionsort(nums,100000);
	later = Date.now();
	times.push(later - now);
}
console.log(times.reduce((a,b) =>   a+b) / times.length)
