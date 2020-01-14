#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <limits>

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override {
      return b*b - 4*a*c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override {
      double res = b*b - 4*a*c;

      if(res < 0) {
        return numeric_limits<double>::quiet_NaN();
      }

      return res;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    std::tuple<std::complex<double>, std::complex<double>> solve(double a, double b, double c)
    {
      std::complex<double> disc{strategy.calculate_discriminant(a,b,c), 0};
      auto root_disc = sqrt(disc);
      return {
          (-b+root_disc) / (2*a),
          (-b-root_disc) / (2*a) };
    }
};
