#include "lib_source.h"

#include <boost/assert.hpp>

namespace MyLibrary {
    int getFortyTwo (){
        auto val = 42;
        BOOST_ASSERT_MSG(val == 42, "Value should be 42");
        return val;
    };
}