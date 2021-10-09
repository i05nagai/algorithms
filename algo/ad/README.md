Automatic Differentiation
====

## Description

## Demo

## VS. 

## Requirement

## Usage

```cpp
typedef ad::dual<boost::numeric::ublas::vector<double>> dual_type;
boost::numeric::ublas::vector<double> values(2, 1.0);
boost::numeric::ublas::vector<dual_type> x = ad::make_dual(values);

//case 1
dual_type y = ad::sqrt(x(0) + x(1));
//getDerivative(x(0) + x(1)) == (1, 1)
//getDerivative(x(0) + x(1)) == (sqrt(1), sqrt(1))

//case 2


```

## Install

## Contribution

## Licence

[MIT](https://opensource.org/licenses/MIT)

## Author

[i05nagai](https://github.com/i05nagai)
