# editline-tabcomp

Tab-completion implementation for BSD editline (libedit).

## Motivation

While the editline readline compatibility layer supports tab
completions, editline itself does not. When I started using editline in
[input][input github]. I implemented tab completions using the code in
this repository. However, nowadays input uses the readline compatibility
layer and I just wanted to archive this code somewhere in case it is
useful for someone else.

## Status

I don't use this myself anymore but I am not aware of any bugs.

## Features

* Simple API.
* Supports wide characters.
* Supports cycling through multiple completions.
* Easy to integrate (single source file in C99).

## Usage

The implementation is provided in `complete.c` and `complete.h` these
files should just be copied to your repository. The header file contains
some pointers on how to use the provided functions.

A usage example is also provided in `example.c`, compile it using:

	$ make

## License

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <http://www.gnu.org/licenses/>.

[input github]: https://github.com/nmeum/input
