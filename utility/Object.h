#pragma once
#include "pre_compiled_header.h"
#include <boost/shared_ptr.hpp>

namespace utility {
    /**
     * @brief 
     *
     * @tparam T
     */
    template <typename T>
    class Object {
    public: 
        /**
         * @brief 
         *
         * @return 
         */
        const T& cast() {
            return static_cast<const T&>(*this);
        }
        /**
         * @brief 
         *
         * @param o
         *
         * @return 
         */
        bool operator==(const T& o) const {
            return this->doEqual(o);
        }
        /**
         * @brief 
         *
         * @return 
         */
        boost::shared_ptr<T> clone() const {
            return boost::shared_ptr<T>(this->doClone());
        }
    private:
        virtual bool doEqual(const T& o) const = 0;
        virtual T* doClone() const = 0;
    };

} // namespace utility
