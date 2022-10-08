# wasm-cpp-js-timeComparison
C++ (optimized)
g++ heapsort.cpp -O3 -o test -std=c++17 && test.exe

JavaScript
Copy file into browser (tests were done in Firefox)

WebAssembly (optimized)
emcc selectionsort.cpp -O3 -o test.html -std=c++17 --emrun && emrun test.html 