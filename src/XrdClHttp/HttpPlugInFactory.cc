/**
 * This file is part of XrdClHttp
 */

#include "HttpPlugInFactory.hh"

#include "XrdVersion.hh"

#include "HttpFilePlugIn.hh"

XrdVERSIONINFO(XrdClGetPlugIn, XrdClGetPlugIn)

extern "C"
{
  void *XrdClGetPlugIn( const void* /*arg*/ )
  {
    return static_cast<void*>( new HttpPlugInFactory());
  }
}

HttpPlugInFactory::~HttpPlugInFactory() {
}

XrdCl::FilePlugIn* HttpPlugInFactory::CreateFile( const std::string &/*url*/ ) {
  return new HttpFilePlugIn();
}

XrdCl::FileSystemPlugIn* HttpPlugInFactory::CreateFileSystem( const std::string &/*url*/ ) { return nullptr; }
