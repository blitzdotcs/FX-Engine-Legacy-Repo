// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_CreditsMetadata
#define INCLUDED_CreditsMetadata

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_df80221b43dc8719_184_new)
HX_DECLARE_CLASS0(CreditsMetadata)



class HXCPP_CLASS_ATTRIBUTES CreditsMetadata_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CreditsMetadata_obj OBJ_;
		CreditsMetadata_obj();

	public:
		enum { _hx_ClassId = 0x153b361d };

		void __construct(::String name,::String desc);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CreditsMetadata")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CreditsMetadata"); }

		inline static ::hx::ObjectPtr< CreditsMetadata_obj > __new(::String name,::String desc) {
			::hx::ObjectPtr< CreditsMetadata_obj > __this = new CreditsMetadata_obj();
			__this->__construct(name,desc);
			return __this;
		}

		inline static ::hx::ObjectPtr< CreditsMetadata_obj > __alloc(::hx::Ctx *_hx_ctx,::String name,::String desc) {
			CreditsMetadata_obj *__this = (CreditsMetadata_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CreditsMetadata_obj), true, "CreditsMetadata"));
			*(void **)__this = CreditsMetadata_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_df80221b43dc8719_184_new)
HXLINE( 187)		( ( ::CreditsMetadata)(__this) )->desc = HX_("",00,00,00,00);
HXLINE( 186)		( ( ::CreditsMetadata)(__this) )->modderName = HX_("",00,00,00,00);
HXLINE( 191)		( ( ::CreditsMetadata)(__this) )->modderName = name;
HXLINE( 192)		( ( ::CreditsMetadata)(__this) )->desc = desc;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CreditsMetadata_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CreditsMetadata",89,63,f8,bb); }

		::String modderName;
		::String desc;
};


#endif /* INCLUDED_CreditsMetadata */ 
