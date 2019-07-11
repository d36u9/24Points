#include "TwentyFourPoints.h"
#include <iostream>
using namespace std;
int main() {
    vector<int> a={1,2,4,6};
    TwentyFourSolver solver;
    auto exprs = solver.Solve24(a);

    for(auto const &expr : exprs) {
        cout<< expr<<endl;
    }
}