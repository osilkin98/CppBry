//
// Created by oleg on 9/18/18.
//


#ifndef LBRY_NAMESPACE_H
#define LBRY_NAMESPACE_H

namespace lbry {

    /* This is going to be the struct that will be created and passed to BaseApi */
    struct Request;

    // declare that the base class exists
    class BaseApi;

    /* These two inherit from the BaseApi */
    class LbryApi;
    class LbryCrdApi;

};

#endif //CPPBRY_NAMESPACE_H
