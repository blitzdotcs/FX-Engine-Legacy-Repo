// Generated by Haxe 4.2.1+bf9ff69
#include <hxcpp.h>

#ifndef INCLUDED_openfl_net_IDynamicPropertyOutput
#include <openfl/net/IDynamicPropertyOutput.h>
#endif
#ifndef INCLUDED_openfl_net_IDynamicPropertyWriter
#include <openfl/net/IDynamicPropertyWriter.h>
#endif

namespace openfl{
namespace net{


static ::String IDynamicPropertyWriter_obj_sMemberFields[] = {
	HX_("writeDynamicProperties",73,7c,e9,f7),
	::String(null()) };

::hx::Class IDynamicPropertyWriter_obj::__mClass;

void IDynamicPropertyWriter_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.net.IDynamicPropertyWriter",cd,cf,5a,16);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(IDynamicPropertyWriter_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0xe9c9e38b >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace net
