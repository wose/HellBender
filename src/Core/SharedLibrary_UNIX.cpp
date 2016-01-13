#include "SharedLibrary_UNIX.h"
#include <dlfcn.h>

namespace hellbender {

std::mutex SharedLibraryImpl::mutex_;

SharedLibraryImpl::SharedLibraryImpl() :
    handle_(nullptr)
{
}

SharedLibraryImpl::~SharedLibraryImpl()
{
}

void SharedLibraryImpl::loadImpl(const std::string& path)
{
    std::lock_guard<std::mutex> lock(mutex_);

    if(handle_)
        throw 1;

    handle_ = dlopen(path.c_str(), RTLD_LAZY);
    if(!handle_)
    {
        const char* err = dlerror();
        throw 1;
    }
    path_ = path;
}

void SharedLibraryImpl::unloadImpl()
{
    std::lock_guard<std::mutex> lock(mutex_);

    if(handle_)
    {
        dlclose(handle_);
        handle_ = nullptr;
    }
}

bool SharedLibraryImpl::isLoadedImpl() const
{
    return handle_ != nullptr;
}

void* SharedLibraryImpl::findSymbolImpl(const std::string& name)
{
    std::lock_guard<std::mutex> lock(mutex_);

    void* result = nullptr;
    if(handle_)
    {
        result = dlsym(handle_, name.c_str());
    }
    return result;
}

const std::string& SharedLibraryImpl::getPathImpl() const
{
    return path_;
}

std::string SharedLibraryImpl::prefixImpl()
{
    return "lib";
}

std::string SharedLibraryImpl::suffixImpl()
{
#if defined(_WIN32)
    #if defined(_DEBUG)
        return "d.dll";
    #else
        return ".dll";
    #endif
#else
    #if defined(_DEBUG)
        return "d.so";
    #else
        return ".so";
    #endif
#endif
}

}
