function sort( arr,N)
    { 
        for (var i = Math.floor(N / 2) - 1; i >= 0; i--)
            heapify(arr, N, i);
 
        for (var i = N - 1; i > 0; i--) {
            var temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
 
            heapify(arr, i, 0);
        }
    }
 
    function heapify(arr, N, i)
    {
        var largest = i;
        var l = 2 * i + 1; 
        var r = 2 * i + 2; 
 
        if (l < N && arr[l] > arr[largest])
            largest = l;
 
        if (r < N && arr[r] > arr[largest])
            largest = r;
 
        if (largest != i) {
            var swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
 
            heapify(arr, N, largest);
        }
    }

times = []
for (i = 0; i < 1000; ++i) {
	nums = Array.from({length: 100000}, () => Math.floor(Math.random() * 100000));
	now = Date.now();
    sort(nums, 100000 - 1);
	later = Date.now();
	times.push(later - now);
}
console.log(times.reduce((a,b) => a+b) / times.length)
