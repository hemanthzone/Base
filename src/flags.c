/*
 * This file is part of Foreign Linux.
 *
 * Copyright (C) 2014, 2015 Xiangyan Sun <wishstudio@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <syscall/mm.h>
#include <flags.h>

struct _flags *cmdline_flags;

void flags_init()
{
	cmdline_flags = (struct _flags *)mm_static_alloc(sizeof(struct _flags));
	strcpy(cmdline_flags->global_session_id, DEFAULT_SESSION_ID);
}

void flags_afterfork_parent()
{
}

void flags_afterfork_child()
{
	cmdline_flags = (struct _flags *)mm_static_alloc(sizeof(struct _flags));
}
