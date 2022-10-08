function bubbleSort (inputArr,len) {
  for (let i = 0; i < len; i++) {
      for (let j = 0; j < len; j++) {
          if (inputArr[j] > inputArr[j + 1]) {
              let tmp = inputArr[j];
              inputArr[j] = inputArr[j + 1];
              inputArr[j + 1] = tmp;
          }
      }
  }
}

times = []

for (i = 0; i < 1000; ++i) {
	nums = Array.from({length: 100000}, () => Math.floor(Math.random() * 100000));
	now = Date.now();
	bubbleSort(nums,100000);
	later = Date.now();
	times.push(later - now);
}
console.log(times.reduce((a,b) =>   a+b) / times.length)
