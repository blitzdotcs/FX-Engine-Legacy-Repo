// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_openfl_text__TextFieldType_TextFieldType_Impl_
#define INCLUDED_openfl_text__TextFieldType_TextFieldType_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(openfl,text,_TextFieldType,TextFieldType_Impl_)

namespace openfl{
namespace text{
namespace _TextFieldType{


class HXCPP_CLASS_ATTRIBUTES TextFieldType_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef TextFieldType_Impl__obj OBJ_;
		TextFieldType_Impl__obj();

	public:
		enum { _hx_ClassId = 0x76221a7a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="openfl.text._TextFieldType.TextFieldType_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"openfl.text._TextFieldType.TextFieldType_Impl_"); }

		inline static ::hx::ObjectPtr< TextFieldType_Impl__obj > __new() {
			::hx::ObjectPtr< TextFieldType_Impl__obj > __this = new TextFieldType_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< TextFieldType_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			TextFieldType_Impl__obj *__this = (TextFieldType_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TextFieldType_Impl__obj), false, "openfl.text._TextFieldType.TextFieldType_Impl_"));
			*(void **)__this = TextFieldType_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TextFieldType_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TextFieldType_Impl_",e7,79,6c,43); }

		static void __boot();
		static  ::Dynamic DYNAMIC;
		static  ::Dynamic INPUT;
		static  ::Dynamic fromString(::String value);
		static ::Dynamic fromString_dyn();

		static ::String toString( ::Dynamic this1);
		static ::Dynamic toString_dyn();

};

} // end namespace openfl
} // end namespace text
} // end namespace _TextFieldType

#endif /* INCLUDED_openfl_text__TextFieldType_TextFieldType_Impl_ */ 
