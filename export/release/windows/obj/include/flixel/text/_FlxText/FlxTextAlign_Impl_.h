// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_flixel_text__FlxText_FlxTextAlign_Impl_
#define INCLUDED_flixel_text__FlxText_FlxTextAlign_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(flixel,text,_FlxText,FlxTextAlign_Impl_)

namespace flixel{
namespace text{
namespace _FlxText{


class HXCPP_CLASS_ATTRIBUTES FlxTextAlign_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef FlxTextAlign_Impl__obj OBJ_;
		FlxTextAlign_Impl__obj();

	public:
		enum { _hx_ClassId = 0x20f90a13 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="flixel.text._FlxText.FlxTextAlign_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"flixel.text._FlxText.FlxTextAlign_Impl_"); }

		inline static ::hx::ObjectPtr< FlxTextAlign_Impl__obj > __new() {
			::hx::ObjectPtr< FlxTextAlign_Impl__obj > __this = new FlxTextAlign_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< FlxTextAlign_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			FlxTextAlign_Impl__obj *__this = (FlxTextAlign_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxTextAlign_Impl__obj), false, "flixel.text._FlxText.FlxTextAlign_Impl_"));
			*(void **)__this = FlxTextAlign_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FlxTextAlign_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FlxTextAlign_Impl_",46,0d,a4,5d); }

		static void __boot();
		static ::String LEFT;
		static ::String CENTER;
		static ::String RIGHT;
		static ::String JUSTIFY;
		static ::String fromOpenFL( ::Dynamic align);
		static ::Dynamic fromOpenFL_dyn();

		static  ::Dynamic toOpenFL(::String align);
		static ::Dynamic toOpenFL_dyn();

};

} // end namespace flixel
} // end namespace text
} // end namespace _FlxText

#endif /* INCLUDED_flixel_text__FlxText_FlxTextAlign_Impl_ */ 
