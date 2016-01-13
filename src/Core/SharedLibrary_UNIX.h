#ifndef HB_CORE_SHAREDLIBRARY_UNIX_H
#define HB_CORE_SHAREDLIBRARY_UNIX_H

#include "Core.h"

#include <string>
#include <mutex>

namespace hellbender {

class HB_API SharedLibraryImpl
{
protected:
    SharedLibraryImpl();
    ~SharedLibraryImpl();

    void loadImpl(const std::string& path);
    void unloadImpl();
    bool isLoadedImpl() const;
    void* findSymbolImpl(const std::string& name);
    const std::string& getPathImpl() const;

    static std::string prefixImpl();
    static std::string suffixImpl();

private:
    std::string path_;
    void* handle_;
    static std::mutex mutex_;
};

}

#endif // HB_CORE_SHAREDLIBRARY_UNIX_H
