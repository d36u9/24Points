# TwentyFourSolver
[[MIT]](https://opensource.org/licenses/MIT)


## Welcome
This is a simple naive calculator for classic childhood math game:
Find all proper math expressions with combinations of 4 numbers and operators "+,-,*,/,^" to get a final result 24.

## example
```
vector<int> a={1,2,4,6};
TwentyFourSolver solver;
auto fs = solver.Solve24(a);

for(auto const &f : fs) {
    cout<< f<<endl;
}
```

results:
```
(4/(6^(1-2)))
((4-1)*(2+6))
(6/(4^(1-2)))
(6*(4*(1^2)))
((1^2)*(4*6))
((4*6)/(1^2))
(6*(4^(1^2)))
(4*(6/(2-1)))
((4*6)^(1^2))
(4*(6/(1^2)))
(6*(4/(1^2)))
(4*(6*(1^2)))
((4*6)/(2-1))
(4*(6^(1^2)))
(4/((1^2)/6))
(6/((1^2)/4))
((2-1)*(4*6))
((4*6)^(2-1))
(6*(4/(2-1)))
(6*(4*(2-1)))
(6*(4^(2-1)))
(4*(6*(2-1)))
(4*(6^(2-1)))
(4/((2-1)/6))
(6/((2-1)/4))
((2+6)*(4-1))
((4*6)*(1^2))
((4*6)*(2-1))
```