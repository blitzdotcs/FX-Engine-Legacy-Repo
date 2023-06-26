// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_lime_graphics_opengl_ext_EXT_texture_compression_s3tc
#define INCLUDED_lime_graphics_opengl_ext_EXT_texture_compression_s3tc

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_65773d6de4f580f8_4_new)
HX_DECLARE_CLASS4(lime,graphics,opengl,ext,EXT_texture_compression_s3tc)

namespace lime{
namespace graphics{
namespace opengl{
namespace ext{


class HXCPP_CLASS_ATTRIBUTES EXT_texture_compression_s3tc_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef EXT_texture_compression_s3tc_obj OBJ_;
		EXT_texture_compression_s3tc_obj();

	public:
		enum { _hx_ClassId = 0x0c694f94 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="lime.graphics.opengl.ext.EXT_texture_compression_s3tc")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"lime.graphics.opengl.ext.EXT_texture_compression_s3tc"); }

		inline static ::hx::ObjectPtr< EXT_texture_compression_s3tc_obj > __new() {
			::hx::ObjectPtr< EXT_texture_compression_s3tc_obj > __this = new EXT_texture_compression_s3tc_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< EXT_texture_compression_s3tc_obj > __alloc(::hx::Ctx *_hx_ctx) {
			EXT_texture_compression_s3tc_obj *__this = (EXT_texture_compression_s3tc_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EXT_texture_compression_s3tc_obj), false, "lime.graphics.opengl.ext.EXT_texture_compression_s3tc"));
			*(void **)__this = EXT_texture_compression_s3tc_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_65773d6de4f580f8_4_new)
HXLINE(   9)		( ( ::lime::graphics::opengl::ext::EXT_texture_compression_s3tc)(__this) )->COMPRESSED_RGBA_S3TC_DXT5_EXT = 33779;
HXLINE(   8)		( ( ::lime::graphics::opengl::ext::EXT_texture_compression_s3tc)(__this) )->COMPRESSED_RGBA_S3TC_DXT3_EXT = 33778;
HXLINE(   7)		( ( ::lime::graphics::opengl::ext::EXT_texture_compression_s3tc)(__this) )->COMPRESSED_RGBA_S3TC_DXT1_EXT = 33777;
HXLINE(   6)		( ( ::lime::graphics::opengl::ext::EXT_texture_compression_s3tc)(__this) )->COMPRESSED_RGB_S3TC_DXT1_EXT = 33776;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~EXT_texture_compression_s3tc_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("EXT_texture_compression_s3tc",6a,86,aa,80); }

		int COMPRESSED_RGB_S3TC_DXT1_EXT;
		int COMPRESSED_RGBA_S3TC_DXT1_EXT;
		int COMPRESSED_RGBA_S3TC_DXT3_EXT;
		int COMPRESSED_RGBA_S3TC_DXT5_EXT;
};

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext

#endif /* INCLUDED_lime_graphics_opengl_ext_EXT_texture_compression_s3tc */ 
