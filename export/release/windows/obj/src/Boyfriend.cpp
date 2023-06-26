// Generated by Haxe 4.2.1+bf9ff69
#include <hxcpp.h>

#ifndef INCLUDED_Boyfriend
#include <Boyfriend.h>
#endif
#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_86c0a8e48d33a6ef_10_new,"Boyfriend","new",0x7fa6173c,"Boyfriend.new","Boyfriend.hx",10,0x444da3b4)
HX_LOCAL_STACK_FRAME(_hx_pos_86c0a8e48d33a6ef_24_update,"Boyfriend","update",0xbd4df0ad,"Boyfriend.update","Boyfriend.hx",24,0x444da3b4)

void Boyfriend_obj::__construct(Float x,Float y,::String __o__hx_char){
            		::String _hx_char = __o__hx_char;
            		if (::hx::IsNull(__o__hx_char)) _hx_char = HX_("bf",c4,55,00,00);
            	HX_STACKFRAME(&_hx_pos_86c0a8e48d33a6ef_10_new)
HXLINE(  21)		this->startedDeath = false;
HXLINE(  12)		this->stunned = false;
HXLINE(  18)		super::__construct(x,y,_hx_char,true);
            	}

Dynamic Boyfriend_obj::__CreateEmpty() { return new Boyfriend_obj; }

void *Boyfriend_obj::_hx_vtable = 0;

Dynamic Boyfriend_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Boyfriend_obj > _hx_result = new Boyfriend_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool Boyfriend_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x55af02e5) {
		if (inClassId<=(int)0x4bce7e8a) {
			if (inClassId<=(int)0x2c01639b) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x2c01639b;
			} else {
				return inClassId==(int)0x4bce7e8a;
			}
		} else {
			return inClassId==(int)0x55af02e5;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void Boyfriend_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_86c0a8e48d33a6ef_24_update)
HXLINE(  25)		if (!(this->debugMode)) {
HXLINE(  27)			if (::StringTools_obj::startsWith(this->animation->_curAnim->name,HX_("sing",4f,96,53,4c))) {
HXLINE(  29)				 ::Boyfriend _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  29)				_hx_tmp->holdTimer = (_hx_tmp->holdTimer + elapsed);
            			}
            			else {
HXLINE(  32)				this->holdTimer = ( (Float)(0) );
            			}
HXLINE(  34)			bool _hx_tmp;
HXDLIN(  34)			bool _hx_tmp1;
HXDLIN(  34)			if (::StringTools_obj::endsWith(this->animation->_curAnim->name,HX_("miss",fc,52,5c,48))) {
HXLINE(  34)				_hx_tmp1 = this->animation->_curAnim->finished;
            			}
            			else {
HXLINE(  34)				_hx_tmp1 = false;
            			}
HXDLIN(  34)			if (_hx_tmp1) {
HXLINE(  34)				_hx_tmp = !(this->debugMode);
            			}
            			else {
HXLINE(  34)				_hx_tmp = false;
            			}
HXDLIN(  34)			if (_hx_tmp) {
HXLINE(  36)				this->playAnim(HX_("idle",14,a7,b3,45),true,false,10);
            			}
HXLINE(  39)			bool _hx_tmp2;
HXDLIN(  39)			bool _hx_tmp3;
HXDLIN(  39)			if ((this->animation->_curAnim->name == HX_("firstDeath",e4,d8,fc,14))) {
HXLINE(  39)				_hx_tmp3 = this->animation->_curAnim->finished;
            			}
            			else {
HXLINE(  39)				_hx_tmp3 = false;
            			}
HXDLIN(  39)			if (_hx_tmp3) {
HXLINE(  39)				_hx_tmp2 = this->startedDeath;
            			}
            			else {
HXLINE(  39)				_hx_tmp2 = false;
            			}
HXDLIN(  39)			if (_hx_tmp2) {
HXLINE(  41)				this->playAnim(HX_("deathLoop",b8,0b,79,2e),null(),null(),null());
            			}
            		}
HXLINE(  45)		this->super::update(elapsed);
HXLINE(  47)		if (::hx::IsNotNull( this->sprTracker )) {
HXLINE(  49)			this->set_x((((this->sprTracker->y * ( (Float)(2) )) + 90) - ( (Float)(350) )));
HXLINE(  50)			this->set_y(((( (Float)(::flixel::FlxG_obj::height) ) / ( (Float)(3) )) - ( (Float)(68) )));
            		}
            	}



::hx::ObjectPtr< Boyfriend_obj > Boyfriend_obj::__new(Float x,Float y,::String __o__hx_char) {
	::hx::ObjectPtr< Boyfriend_obj > __this = new Boyfriend_obj();
	__this->__construct(x,y,__o__hx_char);
	return __this;
}

::hx::ObjectPtr< Boyfriend_obj > Boyfriend_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y,::String __o__hx_char) {
	Boyfriend_obj *__this = (Boyfriend_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Boyfriend_obj), true, "Boyfriend"));
	*(void **)__this = Boyfriend_obj::_hx_vtable;
	__this->__construct(x,y,__o__hx_char);
	return __this;
}

Boyfriend_obj::Boyfriend_obj()
{
}

void Boyfriend_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Boyfriend);
	HX_MARK_MEMBER_NAME(stunned,"stunned");
	HX_MARK_MEMBER_NAME(sprTracker,"sprTracker");
	HX_MARK_MEMBER_NAME(startedDeath,"startedDeath");
	 ::Character_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Boyfriend_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(stunned,"stunned");
	HX_VISIT_MEMBER_NAME(sprTracker,"sprTracker");
	HX_VISIT_MEMBER_NAME(startedDeath,"startedDeath");
	 ::Character_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Boyfriend_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"stunned") ) { return ::hx::Val( stunned ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sprTracker") ) { return ::hx::Val( sprTracker ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startedDeath") ) { return ::hx::Val( startedDeath ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Boyfriend_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"stunned") ) { stunned=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sprTracker") ) { sprTracker=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startedDeath") ) { startedDeath=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Boyfriend_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("stunned",53,5b,75,b6));
	outFields->push(HX_("sprTracker",03,a3,e2,78));
	outFields->push(HX_("startedDeath",33,aa,4e,72));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Boyfriend_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(Boyfriend_obj,stunned),HX_("stunned",53,5b,75,b6)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(Boyfriend_obj,sprTracker),HX_("sprTracker",03,a3,e2,78)},
	{::hx::fsBool,(int)offsetof(Boyfriend_obj,startedDeath),HX_("startedDeath",33,aa,4e,72)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Boyfriend_obj_sStaticStorageInfo = 0;
#endif

static ::String Boyfriend_obj_sMemberFields[] = {
	HX_("stunned",53,5b,75,b6),
	HX_("sprTracker",03,a3,e2,78),
	HX_("startedDeath",33,aa,4e,72),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class Boyfriend_obj::__mClass;

void Boyfriend_obj::__register()
{
	Boyfriend_obj _hx_dummy;
	Boyfriend_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Boyfriend",4a,09,8b,88);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Boyfriend_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Boyfriend_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Boyfriend_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Boyfriend_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

