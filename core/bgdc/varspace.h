/*
 *  Copyright (C) SplinterGU (Fenix/BennuGD) (Since 2006)
 *  Copyright (C) 2002-2006 Fenix Team (Fenix)
 *  Copyright (C) 1999-2002 José Luis Cebrián Pagüe (Fenix)
 *
 *  This file is part of Bennu Game Development
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 *
 */

#ifndef __VARSPACE_H
#define __VARSPACE_H

#include <stdint.h>

#include "typedef.h"

/* A VARSPACE is a variable definition zone */

typedef struct _varspace {
    struct _variable * vars; 	// variables
    int64_t size; 				// size in bytes of the data in the varspace (variable data)
    int64_t count; 				// number of variables
    int64_t reserved; 			// number of allocated variables (may be less than or equal to count)
    int64_t last_offset; 		// last offset of variable data
    int64_t * stringvars; 		// offsets of string-type variables
    int64_t stringvar_reserved; // number of allocated string offsets
    int64_t stringvar_count; 	// number of string offsets
} VARSPACE;

typedef struct _variable {
    TYPEDEF type; 				// variable type
    int64_t code; 				// variable identifier
    int64_t offset; 			// variable offset within the data segment
} VARIABLE;

extern VARSPACE * varspace_new();
extern void       varspace_alloc(VARSPACE * n, int64_t count);
extern void       varspace_init(VARSPACE * n);
extern void       varspace_add(VARSPACE * n, VARIABLE v);
extern VARIABLE * varspace_search(VARSPACE * n, int64_t code);
extern void       varspace_dump(VARSPACE * n, int64_t indent);
extern void       varspace_destroy(VARSPACE * n);
extern void	      varspace_varstring(VARSPACE * n, int64_t offset);

/* Global and local data */

extern VARSPACE global;
extern VARSPACE local;

#endif
