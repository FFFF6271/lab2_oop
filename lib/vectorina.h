#ifndef L2_OOP_VECTORINA_H
#define L2_OOP_VECTORINA_H

/* import c lib */
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#include <assert.h>
/****************/

#include <iostream>
#include <stdexcept>

#define _NEED_ASSERT_LIB
#define _NEED_VECTORINA

#ifdef _NEED_ASSERT_LIB
#include "lib_mem.h"
#endif

#ifdef _NEED_VECTORINA
#include "vectorina_exception.h"
#include "vectorina_iterbase.h"
#include "vectorina_iter.h"

#include "vectorina_base.h"
#endif

#endif //L2_OOP_VECTORINA_H
