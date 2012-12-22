/* --------------------------------------------------------------------------
 *  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
 *    Copyright (C) 2012 Ciengis
 *
 *  CppADCodeGen is distributed under multiple licenses:
 *
 *   - Common Public License Version 1.0 (CPL1), and
 *   - GNU General Public License Version 2 (GPL2).
 *
 * CPL1 terms and conditions can be found in the file "epl-v10.txt", while
 * terms and conditions for the GPL2 can be found in the file "gpl2.txt".
 * ----------------------------------------------------------------------------
 * Author: Joao Leal
 */
#include <cmath>

#include <cppadcg/cg.hpp>

#include "test_solve.hpp"

bool SolveSqrt() {
    using namespace CppAD;
    using namespace std;

    typedef CG<double> CGD;

    // independent variable vector
    std::vector<AD<CGD> > u(2);
    u[0] = 81.0;
    u[1] = 1.0;

    Independent(u);

    // dependent variable vector
    std::vector< AD<CGD> > Z(2);

    // dependent variables
    Z[0] = sqrt(u[0]);
    Z[1] = sqrt(Z[0]) - u[1] * 3;

    // create f: U -> Z
    ADFun<CGD> fun(u, Z);

    bool ok = test_solve(fun, 1, 0, u);

    return ok;
}

