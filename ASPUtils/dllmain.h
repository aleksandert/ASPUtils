// dllmain.h : Declaration of module class.

class CASPUtilsModule : public ATL::CAtlDllModuleT< CASPUtilsModule >
{
public :
	DECLARE_LIBID(LIBID_ASPUtilsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ASPUTILS, "{0693F233-A399-47D7-9A96-A944EE41D864}")
};

extern class CASPUtilsModule _AtlModule;
