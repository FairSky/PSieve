/* app.h -- (C) Geoffrey Reynolds, April 2009.
 * and Ken Brazier October 2009.

   Proth Prime Search sieve.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#ifndef _APP_H
#define _APP_H 1

#include <stdio.h>
#include <stdint.h>


#define APP_VERSION "0.3.6a"

/* Number of primes to buffer between calls to app_thread_fun()
 */
#define APP_BUFLEN 6
#define MIN_MULMOD_NSTEP 2

#define CHECKPOINT_FILENAME "ppcheck%s.txt"
#define OLD_CHECKPOINT_FILENAME "ppcheckpoint.txt"

#define CONFIG_FILENAME "ppconfig.txt"

#define FACTORS_FILENAME_DEFAULT "ppfactors.txt"

#define APP_SHORT_OPTS "k:K:n:N:i:f:qa:s:"
#define APP_LONG_OPTS \
  {"kmin",          required_argument, 0, 'k'}, \
  {"kmax",          required_argument, 0, 'K'}, \
  {"nmin",          required_argument, 0, 'n'}, \
  {"nmax",          required_argument, 0, 'N'}, \
  {"input",         required_argument, 0, 'i'}, \
  {"factors",       required_argument, 0, 'f'}, \
  {"riesel",        no_argument,       0, 'R'}, \
  {"alt",           required_argument, 0, 'a'}, \
  {"sse2",          required_argument, 0, 's'},

void app_banner(void);
int app_parse_option(int opt, char *arg, const char *source);
void app_help(void);
void app_init(void);
void app_thread_init(int th);
void app_thread_fun(int th, uint64_t *__attribute__((aligned(16))) P);
void app_thread_fun1(int th, uint64_t *P, unsigned int len);
void app_thread_fini(int th);
int app_read_checkpoint(FILE *f);
void app_write_checkpoint(FILE *f);
void app_fini(void);
void test_factor(uint64_t p, uint64_t k, unsigned int n, int c);

#endif /* _APP_H */
