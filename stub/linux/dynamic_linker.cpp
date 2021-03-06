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

#include "msos/dynamic_linker/dynamic_linker.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>

#include <dlfcn.h>

#include <eul/utils/unused.hpp>

#include "msos/dynamic_linker/loaded_module.hpp"
#include "msos/dynamic_linker/symbol.hpp"

namespace msos::dl
{

namespace
{

static std::map<const void *, void *> deps;

} // namespace

DynamicLinker::DynamicLinker()
{
}

const Symbol *DynamicLinker::find_symbol(const std::size_t address,
                                         const uint32_t number_of_symbols, uint32_t symbol_code)
{
    UNUSED3(address, number_of_symbols, symbol_code);
    return nullptr;
}

const LoadedModule *DynamicLinker::load_module(const void *module_address, const std::size_t size,
                                               const int mode, const SymbolEntry *entries,
                                               std::size_t number_of_entries,
                                               eul::error::error_code &ec)
{
    static int library_number = 0;

    std::string filename = "lib";
    filename += std::to_string(library_number++);

    std::ofstream out;
    out.open(filename, std::ios::binary | std::ios::out);
    out.write(static_cast<const char *>(module_address), size);
    out.close();

    std::filesystem::path p = std::filesystem::absolute(std::filesystem::path(filename));
    deps[module_address]    = dlopen(p.c_str(), RTLD_NOW | RTLD_GLOBAL);
    if (!deps[module_address])
    {
        std::cerr << "Can't load: " << dlerror() << std::endl;
    }

    modules_.emplace_back();
    auto &lm = modules_.back();
    auto &m  = lm.get_module();

    m.set_text(Module::DataSpan(reinterpret_cast<uint8_t *>(deps[module_address]), 0));
    lm.set_start_address(reinterpret_cast<std::size_t>(module_address));
    UNUSED5(module_address, mode, entries, number_of_entries, ec);
    return &lm;
}

void *DynamicLinker::find_symbol(const char *name)
{
}

} // namespace msos::dl
