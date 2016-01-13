#include "SharedLibrary.h"

#ifdef _WIN32
#include "SharedLibrary_Win32.cpp"
#else
#include "SharedLibrary_UNIX.cpp"
#endif

namespace hellbender {

SharedLibrary::SharedLibrary()
{
}

SharedLibrary::SharedLibrary(const std::string& path)
{
    loadImpl(path);
}

SharedLibrary::~SharedLibrary()
{
}

void SharedLibrary::load(const std::string& path)
{
    loadImpl(path);
}

void SharedLibrary::unload()
{
    unloadImpl();
}

bool SharedLibrary::isLoaded() const
{
    return isLoadedImpl();
}

bool SharedLibrary::hasSymbol(const std::string& name)
{
    return findSymbolImpl(name) != 0;
}

void* SharedLibrary::getSymbol(const std::string& name)
{
    void* result = findSymbolImpl(name);
    if(result)
        return result;
    else
        throw 1;
}

const std::string& SharedLibrary::getPath() const
{
    return getPathImpl();
}

std::string SharedLibrary::prefix()
{
    return prefixImpl();
}

std::string SharedLibrary::getOSName(const std::string& name)
{
    return prefix() + name + suffix();
}

}
