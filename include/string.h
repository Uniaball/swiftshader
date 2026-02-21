/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>
#include <stddef.h>
#include <xlocale.h>
#include <bits/strcasecmp.h>

__BEGIN_DECLS

#if defined(__USE_BSD) || defined(__USE_GNU)
#include <strings.h>
#endif

/* Basic memory and string functions */
void*   memccpy(void* __dst, const void* __src, int __stop_char, size_t __n);
void*   memchr(const void* __s, int __ch, size_t __n);
void*   memrchr(const void* __s, int __ch, size_t __n);
int     memcmp(const void* __lhs, const void* __rhs, size_t __n);
void*   memcpy(void* __dst, const void* __src, size_t __n);
void*   memmove(void* __dst, const void* __src, size_t __n);
void*   memset(void* __dst, int __ch, size_t __n);
void*   memmem(const void* __haystack, size_t __haystack_size, const void* __needle, size_t __needle_size);

char*   strchr(const char* __s, int __ch);
char*   strrchr(const char* __s, int __ch);
size_t  strlen(const char* __s);
int     strcmp(const char* __lhs, const char* __rhs);
char*   stpcpy(char* __dst, const char* __src);
char*   strcpy(char* __dst, const char* __src);
char*   strcat(char* __dst, const char* __src);
char*   strdup(const char* __s);
char*   strstr(const char* __haystack, const char* __needle);
char*   strcasestr(const char* __haystack, const char* __needle);
char*   strtok(char* __s, const char* __delimiter);
char*   strtok_r(char* __s, const char* __delimiter, char** __pos_ptr);

char*   strerror(int __errno_value);
char*   strerror_l(int __errno_value, locale_t __l);
#if defined(__USE_GNU) && __ANDROID_API__ >= 23
char*   strerror_r(int __errno_value, char* __buf, size_t __n);
#else
int     strerror_r(int __errno_value, char* __buf, size_t __n);
#endif
#if defined(__USE_GNU) && __ANDROID_API__ >= 35
const char* strerrorname_np(int __errno_value);
#endif
#if defined(__USE_GNU)
const char* strerrordesc_np(int __errno_value);
#endif

size_t  strnlen(const char* __s, size_t __n);
char*   strncat(char* __dst, const char* __src, size_t __n);
char*   strndup(const char* __s, size_t __n);
int     strncmp(const char* __lhs, const char* __rhs, size_t __n);
char*   stpncpy(char* __dst, const char* __src, size_t __n);
char*   strncpy(char* __dst, const char* __src, size_t __n);
size_t  strlcat(char* __dst, const char* __src, size_t __n);
size_t  strlcpy(char* __dst, const char* __src, size_t __n);

size_t  strcspn(const char* __s, const char* __reject);
char*   strpbrk(const char* __s, const char* __accept);
char*   strsep(char** __s_ptr, const char* __delimiter);
size_t  strspn(const char* __s, const char* __accept);
char*   strsignal(int __signal);
int     strcoll(const char* __lhs, const char* __rhs);
size_t  strxfrm(char* __dst, const char* __src, size_t __n);
int     strcoll_l(const char* __lhs, const char* __rhs, locale_t __l);
size_t  strxfrm_l(char* __dst, const char* __src, size_t __n, locale_t __l);

#if defined(__USE_GNU) && !defined(basename)
#if __ANDROID_API__ >= 23
char*   basename(const char* __path);
#endif
#endif

/* The following block contains the problematic fortify-related overloads and has been removed. */
/* #if defined(__BIONIC_INCLUDE_FORTIFY_HEADERS) ... */

/* All fortify-related code has been removed to avoid __pass_object_size errors. */

__END_DECLS

#endif /* _STRING_H */