// Generated by Haxe 4.2.1+bf9ff69
#ifndef INCLUDED_Debug
#define INCLUDED_Debug

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Debug)
HX_DECLARE_CLASS0(DebugLogWriter)
HX_DECLARE_CLASS4(flixel,_hx_system,debug,log,LogStyle)



class HXCPP_CLASS_ATTRIBUTES Debug_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Debug_obj OBJ_;
		Debug_obj();

	public:
		enum { _hx_ClassId = 0x06dc9773 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Debug")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Debug"); }

		inline static ::hx::ObjectPtr< Debug_obj > __new() {
			::hx::ObjectPtr< Debug_obj > __this = new Debug_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Debug_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Debug_obj *__this = (Debug_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Debug_obj), false, "Debug"));
			*(void **)__this = Debug_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Debug_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Debug",33,c2,4c,6a); }

		static void __boot();
		static  ::flixel::_hx_system::debug::log::LogStyle LOG_STYLE_ERROR;
		static  ::flixel::_hx_system::debug::log::LogStyle LOG_STYLE_WARN;
		static  ::flixel::_hx_system::debug::log::LogStyle LOG_STYLE_INFO;
		static  ::flixel::_hx_system::debug::log::LogStyle LOG_STYLE_TRACE;
		static  ::DebugLogWriter logFileWriter;
		static void logError( ::Dynamic input, ::Dynamic pos);
		static ::Dynamic logError_dyn();

		static void logWarn( ::Dynamic input, ::Dynamic pos);
		static ::Dynamic logWarn_dyn();

		static void logInfo( ::Dynamic input, ::Dynamic pos);
		static ::Dynamic logInfo_dyn();

		static void logTrace( ::Dynamic input, ::Dynamic pos);
		static ::Dynamic logTrace_dyn();

		static void displayAlert(::String title,::String description);
		static ::Dynamic displayAlert_dyn();

		static void watchVariable( ::Dynamic object,::String field,::String name);
		static ::Dynamic watchVariable_dyn();

		static void quickWatch( ::Dynamic value,::String name);
		static ::Dynamic quickWatch_dyn();

		static void addConsoleCommand(::String name, ::Dynamic callbackFn);
		static ::Dynamic addConsoleCommand_dyn();

		static void addObject(::String name, ::Dynamic object);
		static ::Dynamic addObject_dyn();

		static void trackObject( ::Dynamic obj);
		static ::Dynamic trackObject_dyn();

		static void onInitProgram();
		static ::Dynamic onInitProgram_dyn();

		static void onGameStart();
		static ::Dynamic onGameStart_dyn();

		static void writeToFlxGLog(::cpp::VirtualArray data, ::flixel::_hx_system::debug::log::LogStyle logStyle);
		static ::Dynamic writeToFlxGLog_dyn();

		static void writeToLogFile(::cpp::VirtualArray data,::String logLevel);
		static ::Dynamic writeToLogFile_dyn();

		static void defineTrackerProfiles();
		static ::Dynamic defineTrackerProfiles_dyn();

		static void defineConsoleCommands();
		static ::Dynamic defineConsoleCommands_dyn();

		static ::cpp::VirtualArray formatOutput( ::Dynamic input, ::Dynamic pos);
		static ::Dynamic formatOutput_dyn();

};


#endif /* INCLUDED_Debug */ 
