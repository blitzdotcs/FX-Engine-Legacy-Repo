// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_openfl_text__internal_TextLayout
#define INCLUDED_openfl_text__internal_TextLayout

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(lime,text,Font)
HX_DECLARE_CLASS3(openfl,text,_internal,GlyphPosition)
HX_DECLARE_CLASS3(openfl,text,_internal,TextLayout)

namespace openfl{
namespace text{
namespace _internal{


class HXCPP_CLASS_ATTRIBUTES TextLayout_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef TextLayout_obj OBJ_;
		TextLayout_obj();

	public:
		enum { _hx_ClassId = 0x26f4040e };

		void __construct(::String __o_text, ::lime::text::Font font,::hx::Null< int >  __o_size,::hx::Null< int >  __o_direction,::String __o_script,::String __o_language);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.text._internal.TextLayout")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"openfl.text._internal.TextLayout"); }
		static ::hx::ObjectPtr< TextLayout_obj > __new(::String __o_text, ::lime::text::Font font,::hx::Null< int >  __o_size,::hx::Null< int >  __o_direction,::String __o_script,::String __o_language);
		static ::hx::ObjectPtr< TextLayout_obj > __alloc(::hx::Ctx *_hx_ctx,::String __o_text, ::lime::text::Font font,::hx::Null< int >  __o_size,::hx::Null< int >  __o_direction,::String __o_script,::String __o_language);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TextLayout_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TextLayout",57,33,5a,86); }

		static void __boot();
		static  ::Dynamic __meta__;
		static int FT_LOAD_DEFAULT;
		static int FT_LOAD_NO_SCALE;
		static int FT_LOAD_NO_HINTING;
		static int FT_LOAD_RENDER;
		static int FT_LOAD_NO_BITMAP;
		static int FT_LOAD_VERTICAL_LAYOUT;
		static int FT_LOAD_FORCE_AUTOHINT;
		static int FT_LOAD_CROP_BITMAP;
		static int FT_LOAD_PEDANTIC;
		static int FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH;
		static int FT_LOAD_NO_RECURSE;
		static int FT_LOAD_IGNORE_TRANSFORM;
		static int FT_LOAD_MONOCHROME;
		static int FT_LOAD_LINEAR_DESIGN;
		static int FT_LOAD_NO_AUTOHINT;
		static int FT_LOAD_COLOR;
		static int FT_LOAD_COMPUTE_METRICS;
		static int FT_LOAD_BITMAP_METRICS_ONLY;
		static int FT_LOAD_TARGET_NORMAL;
		static int FT_LOAD_TARGET_LIGHT;
		bool autoHint;
		 ::lime::text::Font font;
		::Array< int > glyphs;
		Float letterSpacing;
		::Array< ::Dynamic> positions;
		int size;
		::String text;
		 ::haxe::io::Bytes _hx___buffer;
		int _hx___direction;
		bool _hx___dirty;
		 ::Dynamic _hx___handle;
		::String _hx___language;
		::String _hx___script;
		 ::lime::text::Font _hx___font;
		 ::Dynamic _hx___hbBuffer;
		 ::Dynamic _hx___hbFont;
		void _hx___create(int direction,::String script,::String language);
		::Dynamic _hx___create_dyn();

		void _hx___position();
		::Dynamic _hx___position_dyn();

		::Array< ::Dynamic> get_positions();
		::Dynamic get_positions_dyn();

		int get_direction();
		::Dynamic get_direction_dyn();

		int set_direction(int value);
		::Dynamic set_direction_dyn();

		 ::lime::text::Font set_font( ::lime::text::Font value);
		::Dynamic set_font_dyn();

		::Array< int > get_glyphs();
		::Dynamic get_glyphs_dyn();

		::String get_language();
		::Dynamic get_language_dyn();

		::String set_language(::String value);
		::Dynamic set_language_dyn();

		::String get_script();
		::Dynamic get_script_dyn();

		::String set_script(::String value);
		::Dynamic set_script_dyn();

		int set_size(int value);
		::Dynamic set_size_dyn();

		::String set_text(::String value);
		::Dynamic set_text_dyn();

};

} // end namespace openfl
} // end namespace text
} // end namespace _internal

#endif /* INCLUDED_openfl_text__internal_TextLayout */ 
