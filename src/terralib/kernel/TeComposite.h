/*
 * (C) Copyright 1996-2016 ECMWF & INPE.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file TeComposite.h
    \brief This file contains definition of composite structures in TerraLib
*/

#ifndef __TERRALIB_INTERNAL_COMPOSITE_H
#define __TERRALIB_INTERNAL_COMPOSITE_H

#include "TeCounted.h"

#include <algorithm>
#include <vector>
using namespace std;

//!  Defines a templated class for handling an object built of one single atomic element
template <class T>
class TeSingle {
public:
    //! Constructor
    TeSingle<T>() {}

    //! Destructor
    virtual ~TeSingle<T>() {}

    //! Copy constructor
    TeSingle<T>(T& elem) : elem_(elem) {}

    //! Adds the single element
    void add(T& elem) { elem_ = elem; }

    //! Returns a referency to the single element
    T& location() { return elem_; }

    //! Returns a constant reference to the single element
    const T& location() const { return elem_; }

    //! Returns a referency to the single element
    T& elem() { return elem_; }

protected:
    T elem_;  //!< the single element
};

//! Defines a template for handling a composite object
/*!
    Provides a vector for storing components and ensures
    proper destruction of them, by means of a handle/body idiom.
    Provide a handle to an implementation and thus allow efficient
    copying of derived objects

    \note This is a specialised example of the "Composite"
    design pattern, with support for the "Bridge" pattern
    (also known as the handle/body idiom).
*/
template <class T>
class TeComposite : public TeCounted {
public:
    using TeCounted::attach;
    using TeCounted::detach;

    //! An iterator to the composite elements
    typedef typename vector<T>::iterator iterator;
    typedef typename vector<T>::const_iterator const_iterator;

    //! Adds a new component
    void add(const T& elem) { components_.push_back(elem); }

    //! Removes the i-th component
    bool erase(unsigned int i) {
        if (components_.size() < i)
            return false;
        return !(components_.erase(components_.begin() + i) == components_.end());
    }

    //! Removes a specific element
    /*!
        \param elem the element to be removed
    */
    bool erase(T& elem) {
        typename vector<T>::iterator location = find(components_.begin(), components_.end(), elem);
        if (location != components_.end()) {
            components_.erase(location);
            return true;
        }
        else
            return false;
    }

    //! Removes an element pointed by an iterator
    iterator erase(iterator it) { return components_.erase(it); }

    //! Removes all elements
    void clear() { components_.clear(); }

    //! Returns the size of the composite
    size_t size() const { return components_.size(); }

    //! Returns the i-th element
    T& operator[](int i) { return components_[i]; }

    //! Returns TRUE if the composite is empty
    bool empty() const { return components_.empty(); }

    //! Reserves space for n elements (reserve is available for vectors)
    void reserve(int nelem) { components_.reserve(nelem); }

    //! Returns an iterator to the composite first element
    iterator begin(void) { return components_.begin(); }

    //! Returns a iterator to the composite last plus one element
    iterator end(void) { return components_.end(); }

    //! A reverse iterator to the composite elements
    typedef typename vector<T>::reverse_iterator reverse_iterator;

    //! The iterator to the first position in the TeComposite in reverse order
    reverse_iterator rbegin(void) { return components_.rbegin(); }

    //! The iterator to the last plus one position in the TeComposite in reverse order
    reverse_iterator rend(void) { return components_.rend(); }


protected:
    vector<T> components_;  //!< a vector of components
};

#endif
