/*
 * lftp and utils
 *
 * Copyright (c) 1996-2000 by Alexander V. Lukyanov (lav@yars.free.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* $Id$ */

#ifndef MISC_H
#define MISC_H

// expands tilde; returns pointer to static data
const char *expand_home_relative(const char *);

// returns ptr to last path element
const char *basename_ptr(const char *);
static inline
char *basename_ptr(char *f)
{
   return (char*)basename_ptr((const char *)f);
}

// glues file to dir; returns pointer to static storage
const char *dir_file(const char *dir,const char *file);

// glues file to given url; returns pointer to static storage
const char *url_file(const char *url,const char *file);

const char *output_file_name(const char *src,const char *dst,bool dst_local,
			     const char *dst_base,bool make_dirs);

const char *squeeze_file_name(const char *name,int w);

// mkdir -p
int   create_directories(char *);

// rm -rf
void  truncate_file_tree(const char *dir);

// returns malloc'ed cwd no matter how long it is
// returns 0 on error.
char *xgetcwd();

int percent(long offset,long size);

#define find_char(buf,len,ch) ((const char *)memchr(buf,ch,len))

#define MINUTE (60)
#define HOUR   (60*MINUTE)
#define DAY    (24*HOUR)

extern const char month_names[][4];

int parse_month(const char *);
int parse_perms(const char *);
const char *format_perms(int p);
int parse_year_or_time(const char *year_or_time,int *year,int *hour,int *minute);
int guess_year(int month,int day,int hour=0,int minute=0);

#endif // MISC_H
