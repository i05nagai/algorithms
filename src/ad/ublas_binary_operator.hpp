/**
 * @file ublas_binary_operator.hpp
 * @brief 
 * @author i05nagai
 * @version 0.0.2
 * @date 2016-10-04
 */
#pragma once
#include <boost/numeric/ublas/functional.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>

namespace boost { namespace numeric { namespace ublas {
    /*--------------------------------------------------------------------------
     * vector_binary_scalar1<const double, E2, F>
     *------------------------------------------------------------------------*/
    /**
     * @brief This is specialization of vector_binary_scalar1.
     *  vector_binary_scalar1 denotes expression of `scalar op vector`.
     *  Default implementation of ublas holds const reference of scalar but not copy of scalar. 
     *  When scalar is rvalue, the const reference of scalar is vanished.
     *  
     * @note This implementation is copied from boost::numeric::ublas::vector_expression.hpp.
     *  Major difference of the original code is specialization of template argument T1 as `const double`.
     *  Binary operation for `scalar op vector` in vector_expression.hpp instansiates vector_binary_scalar1 as vector_binary_scalar1<const T1, E2, F>.
     *
     * @TODO Code is not readable and does not follow coding guideline. 
     *
     * @tparam E2
     * @tparam F
     */
    template <typename E2, typename F>
    class vector_binary_scalar1<const double, E2, F>
	: public vector_expression<vector_binary_scalar1<const double, E2, F>> {
    private:
        typedef F functor_type;
        typedef double expression1_type;
        typedef E2 expression2_type;
        typedef vector_binary_scalar1<const double, E2, F> self_type;
    public:
        typedef const double expression1_closure_type;
        typedef typename E2::const_closure_type expression2_closure_type;
#ifdef BOOST_UBLAS_ENABLE_PROXY_SHORTCUTS
        using vector_expression<vector_binary_scalar1<const double, E2, F>>::operator();
#endif
        typedef typename E2::size_type size_type;
        typedef typename E2::difference_type difference_type;
        typedef typename F::result_type value_type;
        typedef value_type const_reference;
        typedef const_reference reference;
        typedef const self_type const_closure_type;
        typedef const_closure_type closure_type;
        typedef unknown_storage_tag storage_category;
    public:
        // Construction and destruction
        BOOST_UBLAS_INLINE
        vector_binary_scalar1(
            const expression1_type &e1, 
            const expression2_type &e2)
        : e1_(e1), 
            e2_ (e2) 
        {
        }

        // Accessors
        BOOST_UBLAS_INLINE
        size_type size() const 
        {
            return e2_.size();
        }

        // Element access
        BOOST_UBLAS_INLINE
        const_reference operator()(size_type i) const 
        {
            return functor_type::apply(e1_, e2_(i));
        }

        BOOST_UBLAS_INLINE
        const_reference operator[](size_type i) const 
        {
            return functor_type::apply(e1_, e2_[i]);
        }

        // Closure comparison
        BOOST_UBLAS_INLINE
        bool same_closure(const vector_binary_scalar1 &vbs1) const 
        {
            return &e1_ == &(vbs1.e1_) 
                && (*this).e2_.same_closure(vbs1.e2_);
        }

        // Iterator types
    private:
        typedef expression1_type const_subiterator1_type;
        typedef typename expression2_type::const_iterator const_subiterator2_type;
        typedef const value_type *const_pointer;

    public:
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        typedef indexed_const_iterator<
            const_closure_type, 
            typename const_subiterator2_type::iterator_category
        > const_iterator;
        typedef const_iterator iterator;
#else
        class const_iterator;
        typedef const_iterator iterator;
#endif

        // Element lookup
        BOOST_UBLAS_INLINE
        const_iterator find(size_type i) const 
        {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
            const_subiterator2_type it(e2_.find(i));
            return const_iterator(*this, it.index());
#else
            return const_iterator(
                *this, 
                const_subiterator1_type(e1_), e2_.find(i));
#endif
        }

        // Iterator enhances the iterator of the referenced vector expression
        // with the binary functor.

#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
        class const_iterator
        : public container_const_reference<vector_binary_scalar1>,
            public iterator_base_traits<
                typename E2::const_iterator::iterator_category
            >::template iterator_base<const_iterator, value_type>::type {
        public:
            typedef typename E2::const_iterator::iterator_category iterator_category;
            typedef typename vector_binary_scalar1::difference_type difference_type;
            typedef typename vector_binary_scalar1::value_type value_type;
            typedef typename vector_binary_scalar1::const_reference reference;
            typedef typename vector_binary_scalar1::const_pointer pointer;
        public:
            // Construction and destruction
            BOOST_UBLAS_INLINE
            const_iterator()
            : container_const_reference<self_type>(), 
                it1_(), 
                it2_() 
            {
            }

            BOOST_UBLAS_INLINE
            const_iterator(
                const self_type& vbs, 
                const const_subiterator1_type& it1, 
                const const_subiterator2_type& it2)
            : container_const_reference<self_type>(vbs), 
                it1_(it1), 
                it2_(it2) 
            {
            }

            // Arithmetic
            BOOST_UBLAS_INLINE
            const_iterator& operator++() 
            {
                ++it2_;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator--() 
            {
                --it2_;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator+=(difference_type n) 
            {
                it2_ += n;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator-=(difference_type n) 
            {
                it2_ -= n;
                return *this;
            }

            BOOST_UBLAS_INLINE
            difference_type operator -(const const_iterator& it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic ());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it1_ == it.it1_, external_logic ());
                return it2_ - it.it2_;
            }

            // Dereference
            BOOST_UBLAS_INLINE
            const_reference operator *() const 
            {
                return functor_type::apply(it1_, *it2_);
            }
            BOOST_UBLAS_INLINE
            const_reference operator[](difference_type n) const 
            {
                return *(*this + n);
            }

            // Index
            BOOST_UBLAS_INLINE
            size_type index () const 
            {
                return it2_.index();
            }

            // Assignment 
            BOOST_UBLAS_INLINE
            const_iterator& operator =(const const_iterator &it) 
            {
                container_const_reference<self_type>::assign(&it());
                it1_ = it.it1_;
                it2_ = it.it2_;
                return *this;
            }

            // Comparison
            BOOST_UBLAS_INLINE
            bool operator==(const const_iterator& it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it1_ == it.it1_, external_logic ());
                return it2_ == it.it2_;
            }

            BOOST_UBLAS_INLINE
            bool operator <(const const_iterator& it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it1_ == it.it1_, external_logic ());
                return it2_ < it.it2_;
            }

        private:
            const_subiterator1_type it1_;
            const_subiterator2_type it2_;
        };
#endif

        BOOST_UBLAS_INLINE
        const_iterator begin() const 
        {
            return find(0); 
        }

        BOOST_UBLAS_INLINE
        const_iterator cbegin() const 
        {
            return begin();
        }

        BOOST_UBLAS_INLINE
        const_iterator end() const 
        {
            return find(size()); 
        }

        BOOST_UBLAS_INLINE
        const_iterator cend() const 
        {
            return end();
        }

        // Reverse iterator
        typedef reverse_iterator_base<const_iterator> const_reverse_iterator;

        BOOST_UBLAS_INLINE
        const_reverse_iterator rbegin() const 
        {
            return const_reverse_iterator(end());
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator crbegin() const 
        {
            return rbegin();
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator rend() const 
        {
            return const_reverse_iterator(begin());
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator crend() const 
        {
            return end();
        }

    private:
        expression1_closure_type e1_;
        expression2_closure_type e2_;
    };
	/*--------------------------------------------------------------------------
     * vector_binary_scalar2<E1, const double, F>
     *------------------------------------------------------------------------*/
    /**
     * @brief This is specialization of vector_binary_scalar1.
     *  vector_binary_scalar1 denotes expression of `vector op scalar`.
     *  Default implementation of ublas holds const reference of scalar but not copy of scalar. 
     *  When scalar is rvalue, the const reference of scalar is vanished.
     *  
     * @note This implementation is copied from boost::numeric::ublas::vector_expression.hpp.
     *  Major difference of the original code is specialization of template argument T2 as `const double`.
     *  Binary operation for `vector op scalar` in vector_expression.hpp instansiates vector_binary_scalar2 as vector_binary_scalar2<E1, const T2, F>.
     *
     * @TODO Code is not readable and does not follow coding guideline. 
     *
     * @tparam E1
     * @tparam F
     */
    template <typename E1, typename F>
    class vector_binary_scalar2<E1, const double, F>
	: public vector_expression<vector_binary_scalar2<E1, const double, F>> {
	private:
        typedef F functor_type;
        typedef E1 expression1_type;
        typedef double expression2_type;
        typedef typename E1::const_closure_type expression1_closure_type;
        typedef const double expression2_closure_type;
        typedef vector_binary_scalar2<E1, const double, F> self_type;
    public:
#ifdef BOOST_UBLAS_ENABLE_PROXY_SHORTCUTS
        using vector_expression<
            vector_binary_scalar2<E1, const double, F>
        >::operator ();
#endif
        typedef typename E1::size_type size_type;
        typedef typename E1::difference_type difference_type;
        typedef typename F::result_type value_type;
        typedef value_type const_reference;
        typedef const_reference reference;
        typedef const self_type const_closure_type;
        typedef const_closure_type closure_type;
        typedef unknown_storage_tag storage_category;
    public:
        // Construction and destruction
        BOOST_UBLAS_INLINE
        vector_binary_scalar2 (
            const expression1_type &e1, 
            const expression2_type &e2)
        : e1_(e1), e2_(e2) 
        {
        }

        // Accessors
        BOOST_UBLAS_INLINE
        size_type size () const 
        {
            return e1_.size(); 
        }

        // Element access
        BOOST_UBLAS_INLINE
        const_reference operator() (size_type i) const 
        {
            return functor_type::apply(e1_(i), e2_);
        }

        BOOST_UBLAS_INLINE
        const_reference operator[] (size_type i) const 
        {
            return functor_type::apply(e1_[i], e2_);
        }

        // Closure comparison
        BOOST_UBLAS_INLINE
        bool same_closure(const vector_binary_scalar2 &vbs2) const 
        {
            return (*this).e1_.same_closure(vbs2.e1_) 
                && &e2_ == &(vbs2.e2_);
        }

        // Iterator types
    private:
        typedef typename expression1_type::const_iterator const_subiterator1_type;
        typedef expression2_type const_subiterator2_type;
        typedef const value_type *const_pointer;

    public:
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
        typedef indexed_const_iterator<
            const_closure_type, 
            typename const_subiterator2_type::iterator_category
        > const_iterator;
        typedef const_iterator iterator;
#else
        class const_iterator;
        typedef const_iterator iterator;
#endif

        // Element lookup
        BOOST_UBLAS_INLINE
        const_iterator find (size_type i) const 
        {
#ifdef BOOST_UBLAS_USE_INDEXED_ITERATOR
            const_subiterator1_type it (e1_.find(i));
            return const_iterator(*this, it.index());
#else
            return const_iterator(
                *this, 
                e1_.find(i), 
                const_subiterator2_type (e2_));
#endif
        }

        // Iterator enhances the iterator of the referenced vector expression
        // with the binary functor.
#ifndef BOOST_UBLAS_USE_INDEXED_ITERATOR
        class const_iterator
        : public container_const_reference<vector_binary_scalar2>,
            public iterator_base_traits<
                typename E1::const_iterator::iterator_category
            >::template iterator_base<const_iterator, value_type>::type {
        public:
            typedef typename E1::const_iterator::iterator_category iterator_category;
            typedef typename vector_binary_scalar2::difference_type difference_type;
            typedef typename vector_binary_scalar2::value_type value_type;
            typedef typename vector_binary_scalar2::const_reference reference;
            typedef typename vector_binary_scalar2::const_pointer pointer;
        public:
            // Construction and destruction
            BOOST_UBLAS_INLINE
            const_iterator()
            : container_const_reference<self_type>(), 
                it1_ (), 
                it2_ () 
            {
            }

            BOOST_UBLAS_INLINE
            const_iterator(
                const self_type &vbs, 
                const const_subiterator1_type &it1, 
                const const_subiterator2_type &it2)
            : container_const_reference<self_type>(vbs), 
                it1_ (it1), 
                it2_ (it2) 
            {
            }

            // Arithmetic
            BOOST_UBLAS_INLINE
            const_iterator& operator++() 
            {
                ++ it1_;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator--() 
            {
                --it1_;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator+=(difference_type n) 
            {
                it1_ += n;
                return *this;
            }

            BOOST_UBLAS_INLINE
            const_iterator& operator-=(difference_type n) 
            {
                it1_ -= n;
                return *this;
            }

            BOOST_UBLAS_INLINE
            difference_type operator -(const const_iterator &it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it2_ == it.it2_, external_logic ());
                return it1_ - it.it1_;
            }

            // Dereference
            BOOST_UBLAS_INLINE
            const_reference operator *() const 
            {
                return functor_type::apply(*it1_, it2_);
            }

            BOOST_UBLAS_INLINE
            const_reference operator[](difference_type n) const 
            {
                return *(*this + n);
            }

            // Index
            BOOST_UBLAS_INLINE
            size_type index () const 
            {
                return it1_.index ();
            }

            // Assignment
            BOOST_UBLAS_INLINE
            const_iterator& operator =(const const_iterator &it) 
            {
                container_const_reference<self_type>::assign(&it());
                it1_ = it.it1_;
                it2_ = it.it2_;
                return *this;
            }

            // Comparison
            BOOST_UBLAS_INLINE
            bool operator==(const const_iterator &it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic ());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it2_ == it.it2_, external_logic ());
                return it1_ == it.it1_;
            }

            BOOST_UBLAS_INLINE
            bool operator <(const const_iterator &it) const 
            {
                BOOST_UBLAS_CHECK(
                    (*this)().same_closure(it()), 
                    external_logic ());
                // FIXME we shouldn't compare floats
                // BOOST_UBLAS_CHECK (it2_ == it.it2_, external_logic ());
                return it1_ < it.it1_;
            }

        private:
            const_subiterator1_type it1_;
            const_subiterator2_type it2_;
        };
#endif

        BOOST_UBLAS_INLINE
        const_iterator begin () const 
        {
            return find(0);
        }

        BOOST_UBLAS_INLINE
        const_iterator cbegin () const 
        {
            return begin();
        }

        BOOST_UBLAS_INLINE
        const_iterator end () const 
        {
            return find(size());
        }

        BOOST_UBLAS_INLINE
        const_iterator cend() const 
        {
            return end();
        }

        // Reverse iterator
        typedef reverse_iterator_base<const_iterator> const_reverse_iterator;

        BOOST_UBLAS_INLINE
        const_reverse_iterator rbegin () const 
        {
            return const_reverse_iterator(end());
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator crbegin() const 
        {
            return rbegin();
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator rend() const 
        {
            return const_reverse_iterator(begin());
        }

        BOOST_UBLAS_INLINE
        const_reverse_iterator crend() const 
        {
            return rend();
        }

    private:
        expression1_closure_type e1_;
        expression2_closure_type e2_;
    };
} } } // namespace boost { namespace numeric { namespace ublas {

