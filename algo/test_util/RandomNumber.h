#pragma once
#include <boost/random.hpp>

namespace algo { namespace test_util {
    class RandomNumber {
    //private typedef
    private:
    //public typedef
    public:
    //public function
    public:
        RandomNumber(const std::size_t seed = 3252352)
        : _engine(), _distribution()
        {
        }
        /**
         * @brief random value in [0, 1). 
         *
         * @return random value in [0, 1).
         */
        double operator()()
        {
            return _distribution(_engine);
        }
        /**
         * @brief [min, max)
         *
         * @param min
         * @param max
         *
         * @return [min, max) 
         */
        double operator()(const double min, const double max)
        {
            const int diff = max - min;
            return (*this)() * diff + min;
        }
    //private function
    private:
    //private members
    private:
        boost::random::mt19937 _engine;
        boost::random::uniform_01<double> _distribution;
    }; // class RandomNumber {
} } // namespace algo { namespace test_util {
