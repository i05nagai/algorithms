#pragma once
#include <iterator>

namespace algo { namespace ad {
    template <typename M>
    class ConstMatrixIterator 
    : public std::iterator<
        std::random_access_iterator_tag,
        typename M::value_type,
        std::ptrdiff_t> {
    //private typedef
    private:
    //public typedef
    public:
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
    //public function
    public:
        explicit ConstMatrixIterator(
            const M& matrix, const std::size_t ri = 0, const std::size_t ci = 0)
        : _matrix(matrix), _ri(ri), _ci(ci)
        {
        }

        explicit ConstMatrixIterator(const ConstMatrixIterator<M>& other)
        : _matrix(other._matrix), _ri(other._ri), _ci(other._ci)
        {
        }

        const ConstMatrixIterator<M>& operator++()
        {
            return *(*this + 1);
        }

        const ConstMatrixIterator<M>& operator--()
        {
            return *(*this - 1);
        }

        const ConstMatrixIterator<M>& operator+=(const difference_type n)
        {
            const size_type colSize = _matrix.size2();
            _ri += static_cast<size_type>(n / colSize);
            _ci += static_cast<size_type>(n % colSize);
            if (_ci >= colSize) {
                _ri += 1;
                _ci -= colSize;
            }
            return *this;
        }

        ConstMatrixIterator<M>& operator-=(const difference_type n)
        {
            const size_type colSize = _matrix.size2();
            _ri -= static_cast<size_type>(n / colSize);
            _ci -= static_cast<size_type>(n % colSize);
            if (_ci < 0) {
                _ri -= 1;
                _ci += colSize;
            }
            return *this;
        }

        difference_type operator -(const ConstMatrixIterator<M>& other) const
        {
            const std::size_t thisLength 
                = this->calculateLength(_ri, _ci);
            const std::size_t otherLength 
                = this->calculateLength(other._ri, other._ci);
            return thisLength - otherLength;
        }
        
        bool operator==(const ConstMatrixIterator<M>& other) const
        {
            return &_matrix == &other._matrix
                && _ri == other._ri
                && _ci == other._ci;
        }

        bool operator!=(const ConstMatrixIterator<M>& other) const
        {
            return !(*this == other);
        }

        bool operator <(const ConstMatrixIterator<M>& other) const
        {
            const std::size_t thisLength 
                = this->calculateLength(_ri, _ci);
            const std::size_t otherLength 
                = this->calculateLength(other._ri, other._ci);
            return thisLength < otherLength;
        }

        const typename M::value_type& operator *() const
        {
            return _matrix(_ri, _ci);
        }

        const typename M::value_type& operator[](const difference_type n) const
        {
            return *(*this + n);
        }

    //private function
    private:
        size_type calculateLength(
            const std::size_t ri, const std::size_t ci) const
        {
            return ri * _matrix.size2() + ci;
        }
    //private members
    private:
        const M& _matrix;
        std::size_t _ri;
        std::size_t _ci;
    };
} } // namespace algo { namespace ad {
