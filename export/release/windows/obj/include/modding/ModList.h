// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_modding_ModList
#define INCLUDED_modding_ModList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(modding,ModList)

namespace modding{


class HXCPP_CLASS_ATTRIBUTES ModList_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ModList_obj OBJ_;
		ModList_obj();

	public:
		enum { _hx_ClassId = 0x7f6685b8 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="modding.ModList")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"modding.ModList"); }

		inline static ::hx::ObjectPtr< ModList_obj > __new() {
			::hx::ObjectPtr< ModList_obj > __this = new ModList_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< ModList_obj > __alloc(::hx::Ctx *_hx_ctx) {
			ModList_obj *__this = (ModList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ModList_obj), false, "modding.ModList"));
			*(void **)__this = ModList_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ModList_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ModList",20,10,30,aa); }

		static void __boot();
		static  ::haxe::ds::StringMap modList;
		static  ::haxe::ds::StringMap modMetadatas;
		static void setModEnabled(::String mod,bool enabled);
		static ::Dynamic setModEnabled_dyn();

		static bool getModEnabled(::String mod);
		static ::Dynamic getModEnabled_dyn();

		static ::Array< ::String > getActiveMods(::Array< ::String > modsToCheck);
		static ::Dynamic getActiveMods_dyn();

		static void load();
		static ::Dynamic load_dyn();

};

} // end namespace modding

#endif /* INCLUDED_modding_ModList */ 
