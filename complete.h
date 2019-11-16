/* Copyright (C) 2019 Sören Tempel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef EDITLINE_TABCOMP
#define EDITLINE_TABCOMP

#include <histedit.h>

/* Completion functions, receives the input prefix and its length. */
typedef void (*compfn)(const char *, size_t);

/* Can be called from the completion function, adds a completion to the
 * list of suggested completions, performs memory allocations */
void addcomp(char *);

/* Initializes the completion API with the given completion function.
 * The second argument indicates what kind of completions should be
 * performed. If zero lines are completed, otherwise individual words. */
void initcomp(compfn, int);

/* Editline completion function which needs to be added using EL_ADDFN
 * and bound to the completion key (e.g. tab) using EL_BIND. */
unsigned char complete(EditLine *, int);

#endif
