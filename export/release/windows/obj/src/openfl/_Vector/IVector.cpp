// Generated by Haxe 4.2.1+bf9ff69
#include <hxcpp.h>

#ifndef INCLUDED_openfl__Vector_IVector
#include <openfl/_Vector/IVector.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_d7693ed8053d108e_1969_boot,"openfl._Vector.IVector","boot",0x499ba4fe,"openfl._Vector.IVector.boot","openfl/Vector.hx",1969,0x4a01873c)
namespace openfl{
namespace _Vector{


static ::String IVector_obj_sMemberFields[] = {
	HX_("get_length",af,04,8f,8f),
	HX_("set_length",23,a3,0c,93),
	HX_("fixed",74,f9,a1,00),
	HX_("concat",14,09,d0,c7),
	HX_("copy",b5,bb,c4,41),
	HX_("filter",b8,1f,35,85),
	HX_("get",96,80,4e,00),
	HX_("indexOf",c9,48,bf,e0),
	HX_("insertAt",8c,7c,1f,c2),
	HX_("iterator",ee,49,9a,93),
	HX_("join",ea,33,65,46),
	HX_("lastIndexOf",13,fd,6a,95),
	HX_("pop",91,5d,55,00),
	HX_("push",da,11,61,4a),
	HX_("removeAt",57,6e,1b,ad),
	HX_("reverse",22,39,fc,1a),
	HX_("set",a2,9b,57,00),
	HX_("shift",82,ec,22,7c),
	HX_("slice",52,c4,c7,7e),
	HX_("sort",5e,27,58,4c),
	HX_("splice",7c,85,9e,bf),
	HX_("toString",ac,d0,6e,38),
	HX_("unshift",89,e3,b3,78),
	HX_("__tempIndex",3e,e8,54,22),
	::String(null()) };

::hx::Class IVector_obj::__mClass;

void IVector_obj::__register()
{
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl._Vector.IVector",22,f3,5f,8c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(IVector_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TIsInterface< (int)0x45e7caba >;
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void IVector_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_d7693ed8053d108e_1969_boot)
HXDLIN(1969)		__mClass->__meta__ =  ::Dynamic(::hx::Anon_obj::Create(1)
            			->setFixed(0,HX_("obj",f7,8f,54,00), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("SuppressWarnings",0c,d3,d2,00),::cpp::VirtualArray_obj::__new(1)->init(0,HX_("checkstyle:FieldDocComment",70,56,1b,20))))));
            	}
}

} // end namespace openfl
} // end namespace _Vector
