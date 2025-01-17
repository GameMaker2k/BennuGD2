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

#ifndef __FRAME_H
#define __FRAME_H

/* --------------------------------------------------------------------------- */

extern uint64_t frames_count ;
extern int64_t last_frame_ticks ;
extern int64_t next_frame_ticks ;
extern double frame_ms ;
extern int64_t max_jump ;
extern int64_t current_jump ;
extern int64_t jump ;
extern int64_t FPS_count ;
extern int64_t FPS_init ;

/* --------------------------------------------------------------------------- */

extern void frame_init();
extern void frame_exit();

extern void gr_set_fps( int64_t fps, int64_t jump );
extern void gr_wait_frame();
extern void gr_draw_frame();

//extern void gr_refresh_palette();

/* --------------------------------------------------------------------------- */

#endif
