# Sorting Algorithm Time Comparison in WebAssembly, C++, and JavaScript 🕒🔍

## What This Is About

🌟 Ever wondered how different technologies stack up when it comes to sorting algorithms? This project is a deep dive into the time performance of classic sorting algorithms, implemented in **WebAssembly, C++, and JavaScript**. 🌟

## Technical Details 🛠

- **Languages Used**: Python for orchestration, C++ for native code, JavaScript for browser-based code, and WebAssembly for low-level web code.
- **Libraries and Frameworks**: Matplotlib and Seaborn for Python-based visualization, Node.js for running JavaScript.
- **Tools**: GCC for C++ compilation, Emscripten for WebAssembly compilation.
- **System Configuration**: 
    - OS: Windows
    - OS Version: 10
    - Architecture: 64-bit, WindowsPE
    - Machine: AMD64
    - Processor: Intel64 Family 6 Model 158 Stepping 10, GenuineIntel
    - Python Version: 3.10.4

## Visual Snapshots 📊

### QuickSort Performance
![extracted_image_1](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/7b8070e9-cbeb-4fa8-b0ad-be42a08d2933)


### SelectionSort Performance
![extracted_image_2](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/18398177-a7b7-44e8-bf30-117f7343d7fd)


### MergeSort Performance
![extracted_image_3](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/0cb9a436-c4d9-4f62-873d-9aab008393ed)

### BubbleSort Performance
![extracted_image_4](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/0e528e5d-b5b9-4581-b3f6-00f7e1f88ddb)

### InsertionSort Performance
![extracted_image_5](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/7212780a-5b00-414e-a6c1-960f36c7a4a3)

### HeapSort Performance
![extracted_image_6](https://github.com/shreyash-sharma/wasm-cpp-js-timeComparison/assets/14334982/f172900a-5e5f-41b3-ba72-c081217bb1a2)

## Key Highlights 🌟

- **Multiple Technologies**: WebAssembly, C++, JavaScript
- **Algorithms Covered**: QuickSort, MergeSort, SelectionSort
- **Dynamic Visualization**: Beautiful graphs made using Matplotlib and Seaborn
- **System Information**: Insight into the system where these algorithms were run

## Quick Look at the Code 📜

Here's how we gather the data for QuickSort in C++ (unoptimized):

```python
type_opt="_unoptimized"
command_unoptimized = "g++ quicksort.cpp -o quicksort" + type_opt + " -std=c++17 && " + "quicksort" + type_opt
res = calculate_time("quicksort", type_opt, command_unoptimized)
```

## Insights 📊

- WebAssembly implementations tend to be faster for larger datasets.
- C++ with optimization flags gives WebAssembly a run for its money!
- JavaScript is surprisingly efficient for smaller datasets.

## Check It Out Yourself 👀

Feel free to clone this repository and play around with the code. Let's see if you can come up with some insights of your own!
