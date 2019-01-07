# C Implentation of Scaled Partial Pivoting 
Scaled Partial Pivoting is a method in Numerical Linear Algebra used to minimize error in the Gaussian Elimination process.
It involves swapping the rows of a matrix in such a way that the pivots are the largest ratios relative to the max entry in
each row. The program solves any linear independent nxn matrix via Gaussian Elimination. 
For more information regarding the mathematics, see http://www.math.usm.edu/lambers/mat461/lecture11.pdf as a great
source. 

## Usage

To use, compile the source code (ex in linux environment) 

```
gcc Main.c Function.c -o foo 
```
and excecute with size of matrix n: 

```
./foo n
```

## Sample Output 

Wtih ./foo 4: 


1.190 2.110 -100.000 1.000 | 1.12<br/>
14.200 -0.122 12.200 -1.000 | 3.44<br/>
0.000 100.000 -99.900 1.000 | 2.15<br/>
15.300 0.110 -13.100 -1.000 | 0.00<br/>
<br/>
Enter value for b(4): 4.16<br/>
<br/>
<br/>
1.190 2.110 -100.000 1.000 | 1.12<br/>
14.200 -0.122 12.200 -1.000 | 3.44<br/>
0.000 100.000 -99.900 1.000 | 2.15<br/>
15.300 0.110 -13.100 -1.000 | 0.00<br/>
<br/>
<br/>
<br/>
14.200 -0.122 12.200 -1.000 | 3.44<br/>
0.000 100.000 -99.900 1.000 | 2.15<br/>
0.000 0.000 -98.904 1.063 | 0.79<br/>
0.000 -0.000 -26.004 0.075 | 0.45<br/>
<br/>
<br/>
<br/>
14.200 -0.122 12.200 -1.000 | 3.44<br/>
0.000 100.000 -99.900 1.000 | 2.15<br/>
0.000 0.000 -98.904 1.063 | 0.79<br/>
0.000 -0.000 -0.000 -0.204 | 0.24<br/>
<br/>
<br/>
<br/>
x(1) = 0.177<br/>
x(2) = 0.013<br/>
x(3) = -0.021<br/>
x(4) = -1.183<br/>


## License 

Copyright 2018 Brandon Ferencik

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Sources/References

http://www.math.usm.edu/lambers/mat461/lecture11.pdf
https://fac.ksu.edu.sa/sites/default/files/numerical_analysis_9th.pdf, Ch 6.2

