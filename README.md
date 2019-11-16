# editline-tabcomp

This an implementation of a tab-completion algorithm for BSD editline.

## Motivation

While the editline readline compatibility layer supports tab
completions, editline itself does not. When I started using editline in
[input][input github] I implemented tab completions using the code in
this repository. However, nowadays input uses the readline compatibility
layer and I just wanted to archive this code somewhere in case it is
useful for someone else.

## Features

* Simple API.
* Supports wide characters.
* Supports cycling through multiple completions.

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
