# This file is part of MSOS project.
# Copyright (C) 2021 Mateusz Stadnik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

add_library(msos_dynamic_linker_arch)

target_sources(msos_dynamic_linker_arch
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/call_external.S
)

target_compile_options(msos_dynamic_linker_arch
    PUBLIC
        $<$<COMPILE_LANGUAGE:ASM>:-fno-exceptions -ffunction-sections -fdata-sections -fno-unwind-tables -fno-rtti
        -fno-use-cxa-atexit>
)



