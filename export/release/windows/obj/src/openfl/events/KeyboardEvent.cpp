// Generated by Haxe 4.2.1+bf9ff69
#include <hxcpp.h>

#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_KeyboardEvent
#include <openfl/events/KeyboardEvent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c70c2341539e31f3_169_new,"openfl.events.KeyboardEvent","new",0xa9982e4e,"openfl.events.KeyboardEvent.new","openfl/events/KeyboardEvent.hx",169,0xce5f4702)
HX_LOCAL_STACK_FRAME(_hx_pos_c70c2341539e31f3_186_clone,"openfl.events.KeyboardEvent","clone",0x11ed48cb,"openfl.events.KeyboardEvent.clone","openfl/events/KeyboardEvent.hx",186,0xce5f4702)
HX_LOCAL_STACK_FRAME(_hx_pos_c70c2341539e31f3_198_toString,"openfl.events.KeyboardEvent","toString",0xd22933fe,"openfl.events.KeyboardEvent.toString","openfl/events/KeyboardEvent.hx",198,0xce5f4702)
static const ::String _hx_array_data_d8fbaf5c_3[] = {
	HX_("type",ba,f2,08,4d),HX_("bubbles",67,bb,56,61),HX_("cancelable",14,a0,79,c4),HX_("charCode",23,5f,24,9c),HX_("keyCode",6c,22,9e,9b),HX_("keyLocation",f4,ea,6a,2d),HX_("ctrlKey",b4,35,7d,61),HX_("altKey",f6,a7,ca,44),HX_("shiftKey",3d,92,9f,99),
};
HX_LOCAL_STACK_FRAME(_hx_pos_c70c2341539e31f3_212___init,"openfl.events.KeyboardEvent","__init",0x84182902,"openfl.events.KeyboardEvent.__init","openfl/events/KeyboardEvent.hx",212,0xce5f4702)
HX_LOCAL_STACK_FRAME(_hx_pos_c70c2341539e31f3_44_boot,"openfl.events.KeyboardEvent","boot",0xb3a95684,"openfl.events.KeyboardEvent.boot","openfl/events/KeyboardEvent.hx",44,0xce5f4702)
HX_LOCAL_STACK_FRAME(_hx_pos_c70c2341539e31f3_65_boot,"openfl.events.KeyboardEvent","boot",0xb3a95684,"openfl.events.KeyboardEvent.boot","openfl/events/KeyboardEvent.hx",65,0xce5f4702)
namespace openfl{
namespace events{

void KeyboardEvent_obj::__construct(::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable,::hx::Null< int >  __o_charCodeValue,::hx::Null< int >  __o_keyCodeValue, ::Dynamic keyLocationValue,::hx::Null< bool >  __o_ctrlKeyValue,::hx::Null< bool >  __o_altKeyValue,::hx::Null< bool >  __o_shiftKeyValue,::hx::Null< bool >  __o_controlKeyValue,::hx::Null< bool >  __o_commandKeyValue){
            		bool bubbles = __o_bubbles.Default(false);
            		bool cancelable = __o_cancelable.Default(false);
            		int charCodeValue = __o_charCodeValue.Default(0);
            		int keyCodeValue = __o_keyCodeValue.Default(0);
            		bool ctrlKeyValue = __o_ctrlKeyValue.Default(false);
            		bool altKeyValue = __o_altKeyValue.Default(false);
            		bool shiftKeyValue = __o_shiftKeyValue.Default(false);
            		bool controlKeyValue = __o_controlKeyValue.Default(false);
            		bool commandKeyValue = __o_commandKeyValue.Default(false);
            	HX_STACKFRAME(&_hx_pos_c70c2341539e31f3_169_new)
HXLINE( 170)		super::__construct(type,bubbles,cancelable);
HXLINE( 172)		this->charCode = charCodeValue;
HXLINE( 173)		this->keyCode = keyCodeValue;
HXLINE( 174)		int _hx_tmp;
HXDLIN( 174)		if (::hx::IsNotNull( keyLocationValue )) {
HXLINE( 174)			_hx_tmp = ( (int)(keyLocationValue) );
            		}
            		else {
HXLINE( 174)			_hx_tmp = 0;
            		}
HXDLIN( 174)		this->keyLocation = _hx_tmp;
HXLINE( 175)		this->ctrlKey = ctrlKeyValue;
HXLINE( 176)		this->altKey = altKeyValue;
HXLINE( 177)		this->shiftKey = shiftKeyValue;
HXLINE( 180)		this->controlKey = controlKeyValue;
HXLINE( 181)		this->commandKey = commandKeyValue;
            	}

Dynamic KeyboardEvent_obj::__CreateEmpty() { return new KeyboardEvent_obj; }

void *KeyboardEvent_obj::_hx_vtable = 0;

Dynamic KeyboardEvent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< KeyboardEvent_obj > _hx_result = new KeyboardEvent_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return _hx_result;
}

bool KeyboardEvent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x08ec4c31) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x08ec4c31;
	} else {
		return inClassId==(int)0x4994310a;
	}
}

 ::openfl::events::Event KeyboardEvent_obj::clone(){
            	HX_GC_STACKFRAME(&_hx_pos_c70c2341539e31f3_186_clone)
HXLINE( 187)		 ::openfl::events::KeyboardEvent event =  ::openfl::events::KeyboardEvent_obj::__alloc( HX_CTX ,this->type,this->bubbles,this->cancelable,this->charCode,this->keyCode,this->keyLocation,this->ctrlKey,this->altKey,this->shiftKey,this->controlKey,this->commandKey);
HXLINE( 190)		event->target = this->target;
HXLINE( 191)		event->currentTarget = this->currentTarget;
HXLINE( 192)		event->eventPhase = this->eventPhase;
HXLINE( 193)		return event;
            	}


::String KeyboardEvent_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_c70c2341539e31f3_198_toString)
HXDLIN( 198)		return this->_hx___formatToString(HX_("KeyboardEvent",d3,8d,88,91),::Array_obj< ::String >::fromData( _hx_array_data_d8fbaf5c_3,9));
            	}


void KeyboardEvent_obj::_hx___init(){
            	HX_STACKFRAME(&_hx_pos_c70c2341539e31f3_212___init)
HXLINE( 213)		this->super::_hx___init();
HXLINE( 214)		this->charCode = 0;
HXLINE( 215)		this->keyCode = 0;
HXLINE( 216)		this->keyLocation = 0;
HXLINE( 217)		this->ctrlKey = false;
HXLINE( 218)		this->altKey = false;
HXLINE( 219)		this->shiftKey = false;
HXLINE( 222)		this->controlKey = false;
HXLINE( 223)		this->commandKey = false;
            	}


::String KeyboardEvent_obj::KEY_DOWN;

::String KeyboardEvent_obj::KEY_UP;


::hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new(::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable,::hx::Null< int >  __o_charCodeValue,::hx::Null< int >  __o_keyCodeValue, ::Dynamic keyLocationValue,::hx::Null< bool >  __o_ctrlKeyValue,::hx::Null< bool >  __o_altKeyValue,::hx::Null< bool >  __o_shiftKeyValue,::hx::Null< bool >  __o_controlKeyValue,::hx::Null< bool >  __o_commandKeyValue) {
	::hx::ObjectPtr< KeyboardEvent_obj > __this = new KeyboardEvent_obj();
	__this->__construct(type,__o_bubbles,__o_cancelable,__o_charCodeValue,__o_keyCodeValue,keyLocationValue,__o_ctrlKeyValue,__o_altKeyValue,__o_shiftKeyValue,__o_controlKeyValue,__o_commandKeyValue);
	return __this;
}

::hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__alloc(::hx::Ctx *_hx_ctx,::String type,::hx::Null< bool >  __o_bubbles,::hx::Null< bool >  __o_cancelable,::hx::Null< int >  __o_charCodeValue,::hx::Null< int >  __o_keyCodeValue, ::Dynamic keyLocationValue,::hx::Null< bool >  __o_ctrlKeyValue,::hx::Null< bool >  __o_altKeyValue,::hx::Null< bool >  __o_shiftKeyValue,::hx::Null< bool >  __o_controlKeyValue,::hx::Null< bool >  __o_commandKeyValue) {
	KeyboardEvent_obj *__this = (KeyboardEvent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(KeyboardEvent_obj), true, "openfl.events.KeyboardEvent"));
	*(void **)__this = KeyboardEvent_obj::_hx_vtable;
	__this->__construct(type,__o_bubbles,__o_cancelable,__o_charCodeValue,__o_keyCodeValue,keyLocationValue,__o_ctrlKeyValue,__o_altKeyValue,__o_shiftKeyValue,__o_controlKeyValue,__o_commandKeyValue);
	return __this;
}

KeyboardEvent_obj::KeyboardEvent_obj()
{
}

::hx::Val KeyboardEvent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return ::hx::Val( clone_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { return ::hx::Val( altKey ); }
		if (HX_FIELD_EQ(inName,"__init") ) { return ::hx::Val( _hx___init_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ::hx::Val( ctrlKey ); }
		if (HX_FIELD_EQ(inName,"keyCode") ) { return ::hx::Val( keyCode ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"charCode") ) { return ::hx::Val( charCode ); }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return ::hx::Val( shiftKey ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"commandKey") ) { return ::hx::Val( commandKey ); }
		if (HX_FIELD_EQ(inName,"controlKey") ) { return ::hx::Val( controlKey ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { return ::hx::Val( keyLocation ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val KeyboardEvent_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyCode") ) { keyCode=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"charCode") ) { charCode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"commandKey") ) { commandKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"controlKey") ) { controlKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { keyLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("altKey",f6,a7,ca,44));
	outFields->push(HX_("charCode",23,5f,24,9c));
	outFields->push(HX_("commandKey",14,71,9b,43));
	outFields->push(HX_("controlKey",42,8e,a5,04));
	outFields->push(HX_("ctrlKey",b4,35,7d,61));
	outFields->push(HX_("keyCode",6c,22,9e,9b));
	outFields->push(HX_("keyLocation",f4,ea,6a,2d));
	outFields->push(HX_("shiftKey",3d,92,9f,99));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo KeyboardEvent_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(KeyboardEvent_obj,altKey),HX_("altKey",f6,a7,ca,44)},
	{::hx::fsInt,(int)offsetof(KeyboardEvent_obj,charCode),HX_("charCode",23,5f,24,9c)},
	{::hx::fsBool,(int)offsetof(KeyboardEvent_obj,commandKey),HX_("commandKey",14,71,9b,43)},
	{::hx::fsBool,(int)offsetof(KeyboardEvent_obj,controlKey),HX_("controlKey",42,8e,a5,04)},
	{::hx::fsBool,(int)offsetof(KeyboardEvent_obj,ctrlKey),HX_("ctrlKey",b4,35,7d,61)},
	{::hx::fsInt,(int)offsetof(KeyboardEvent_obj,keyCode),HX_("keyCode",6c,22,9e,9b)},
	{::hx::fsInt,(int)offsetof(KeyboardEvent_obj,keyLocation),HX_("keyLocation",f4,ea,6a,2d)},
	{::hx::fsBool,(int)offsetof(KeyboardEvent_obj,shiftKey),HX_("shiftKey",3d,92,9f,99)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo KeyboardEvent_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &KeyboardEvent_obj::KEY_DOWN,HX_("KEY_DOWN",62,6a,13,6d)},
	{::hx::fsString,(void *) &KeyboardEvent_obj::KEY_UP,HX_("KEY_UP",5b,74,86,f2)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String KeyboardEvent_obj_sMemberFields[] = {
	HX_("altKey",f6,a7,ca,44),
	HX_("charCode",23,5f,24,9c),
	HX_("commandKey",14,71,9b,43),
	HX_("controlKey",42,8e,a5,04),
	HX_("ctrlKey",b4,35,7d,61),
	HX_("keyCode",6c,22,9e,9b),
	HX_("keyLocation",f4,ea,6a,2d),
	HX_("shiftKey",3d,92,9f,99),
	HX_("clone",5d,13,63,48),
	HX_("toString",ac,d0,6e,38),
	HX_("__init",30,9e,b3,f4),
	::String(null()) };

static void KeyboardEvent_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_DOWN,"KEY_DOWN");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_UP,"KEY_UP");
};

#ifdef HXCPP_VISIT_ALLOCS
static void KeyboardEvent_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::KEY_DOWN,"KEY_DOWN");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::KEY_UP,"KEY_UP");
};

#endif

::hx::Class KeyboardEvent_obj::__mClass;

static ::String KeyboardEvent_obj_sStaticFields[] = {
	HX_("KEY_DOWN",62,6a,13,6d),
	HX_("KEY_UP",5b,74,86,f2),
	::String(null())
};

void KeyboardEvent_obj::__register()
{
	KeyboardEvent_obj _hx_dummy;
	KeyboardEvent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("openfl.events.KeyboardEvent",5c,af,fb,d8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = KeyboardEvent_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(KeyboardEvent_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(KeyboardEvent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< KeyboardEvent_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = KeyboardEvent_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = KeyboardEvent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = KeyboardEvent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void KeyboardEvent_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_c70c2341539e31f3_44_boot)
HXDLIN(  44)		KEY_DOWN = HX_("keyDown",a1,69,47,9c);
            	}
{
            	HX_STACKFRAME(&_hx_pos_c70c2341539e31f3_65_boot)
HXDLIN(  65)		KEY_UP = HX_("keyUp",da,b9,fe,de);
            	}
}

} // end namespace openfl
} // end namespace events
