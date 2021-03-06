// This file is part of msos project.
// Copyright (C) 2021 Mateusz Stadnik
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once 

#ifdef MSOS_DYNAMIC_LINKER_ENABLE_LOGGING
#include <cstdio>
#endif 

#ifdef MSOS_DYNAMIC_LINKER_SEVERITY_DEBUG
#define log_debug(...) printf("DBG/"); printf(__VA_ARGS__)
#else
#define log_debug(...)
#endif 

#ifdef MSOS_DYNAMIC_LINKER_SEVERITY_INFO 
#define log_info(...) printf("INF/"); printf(__VA_ARGS__)
#else 
#define log_info(...)
#endif 

#ifdef MSOS_DYNAMIC_LINKER_SEVERITY_WARNING
#define log_warning(...) printf("WRN/"); printf(__VA_ARGS__)
#else 
#define log_warning(...)
#endif 

#ifdef MSOS_DYNAMIC_LINKER_SEVERITY_ERROR 
#define log_error(...) printf("ERR/"); printf(__VA_ARGS__)
#else 
#define log_error(...)
#endif


