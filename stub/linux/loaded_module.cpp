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

#include "msos/dynamic_linker/loaded_module.hpp"

#include <dlfcn.h>

namespace msos::dl 
{

LoadedModule::LoadedModule() 
{
}

int LoadedModule::execute() const
{
    int(*main)();
    *(void**)(&main) = dlsym(static_cast<void*>(module_.get_text().data()), "main");
    return main();
}

void LoadedModule::set_start_address(const std::size_t start_address)
{
    start_address_ = start_address;
}

const Module& LoadedModule::get_module() const 
{
    return module_;
}

Module& LoadedModule::get_module()
{
    return module_;
}

} // namespace msos::dl
