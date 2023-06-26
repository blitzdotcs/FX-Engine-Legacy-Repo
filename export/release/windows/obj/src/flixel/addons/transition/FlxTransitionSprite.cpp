// Generated by Haxe 4.2.1+bf9ff69
#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionSprite
#include <flixel/addons/transition/FlxTransitionSprite.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_GraphicTransTileDiamond
#include <flixel/addons/transition/GraphicTransTileDiamond.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_graphics_FlxGraphic
#include <flixel/graphics/FlxGraphic.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_c4312f005b5b0457_25_new,"flixel.addons.transition.FlxTransitionSprite","new",0x32c8330e,"flixel.addons.transition.FlxTransitionSprite.new","flixel/addons/transition/FlxTransitionSprite.hx",25,0xd14f1ac3)
static const int _hx_array_data_b71a541c_2[] = {
	(int)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_70_start,"flixel.addons.transition.FlxTransitionSprite","start",0x86605e90,"flixel.addons.transition.FlxTransitionSprite.start","flixel/addons/transition/FlxTransitionSprite.hx",70,0xd14f1ac3)
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_79_startStatus,"flixel.addons.transition.FlxTransitionSprite","startStatus",0x0e9e05e2,"flixel.addons.transition.FlxTransitionSprite.startStatus","flixel/addons/transition/FlxTransitionSprite.hx",79,0xd14f1ac3)
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_83_setStatus,"flixel.addons.transition.FlxTransitionSprite","setStatus",0x6223f5a2,"flixel.addons.transition.FlxTransitionSprite.setStatus","flixel/addons/transition/FlxTransitionSprite.hx",83,0xd14f1ac3)
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_99_onFinishAnim,"flixel.addons.transition.FlxTransitionSprite","onFinishAnim",0xb87c9195,"flixel.addons.transition.FlxTransitionSprite.onFinishAnim","flixel/addons/transition/FlxTransitionSprite.hx",99,0xd14f1ac3)
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_114_update,"flixel.addons.transition.FlxTransitionSprite","update",0x8efd841b,"flixel.addons.transition.FlxTransitionSprite.update","flixel/addons/transition/FlxTransitionSprite.hx",114,0xd14f1ac3)
HX_LOCAL_STACK_FRAME(_hx_pos_c4312f005b5b0457_127_onTime,"flixel.addons.transition.FlxTransitionSprite","onTime",0xf77ed2de,"flixel.addons.transition.FlxTransitionSprite.onTime","flixel/addons/transition/FlxTransitionSprite.hx",127,0xd14f1ac3)
namespace flixel{
namespace addons{
namespace transition{

void FlxTransitionSprite_obj::__construct(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,Float Delay, ::Dynamic Graphic,::hx::Null< int >  __o_GraphicWidth,::hx::Null< int >  __o_GraphicHeight,::hx::Null< int >  __o_FrameRate){
            		Float X = __o_X.Default(0);
            		Float Y = __o_Y.Default(0);
            		int GraphicWidth = __o_GraphicWidth.Default(32);
            		int GraphicHeight = __o_GraphicHeight.Default(32);
            		int FrameRate = __o_FrameRate.Default(40);
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_25_new)
HXLINE(  34)		this->_newStatus = -1;
HXLINE(  32)		this->status = 0;
HXLINE(  30)		this->_finished = false;
HXLINE(  29)		this->_starting = true;
HXLINE(  39)		super::__construct(X,Y,null());
HXLINE(  40)		if (::hx::IsNull( Graphic )) {
HXLINE(  42)			Graphic = ::flixel::graphics::FlxGraphic_obj::fromClass(::hx::ClassOf< ::flixel::addons::transition::GraphicTransTileDiamond >(),null(),null(),null());
HXLINE(  43)			GraphicWidth = 32;
HXLINE(  44)			GraphicHeight = 32;
            		}
HXLINE(  46)		this->_delay = Delay;
HXLINE(  47)		this->loadGraphic(Graphic,true,GraphicWidth,GraphicHeight,null(),null());
HXLINE(  49)		this->graphic->persist = true;
HXLINE(  50)		this->graphic->set_destroyOnNoUse(false);
HXLINE(  52)		::Array< int > inArray = ::Array_obj< int >::__new(0);
HXLINE(  53)		::Array< int > outArray = ::Array_obj< int >::__new(0);
HXLINE(  54)		{
HXLINE(  54)			int _g = 1;
HXDLIN(  54)			int _g1 = (this->numFrames - 1);
HXDLIN(  54)			while((_g < _g1)){
HXLINE(  54)				_g = (_g + 1);
HXDLIN(  54)				int i = (_g - 1);
HXLINE(  56)				inArray->push(i);
            			}
            		}
HXLINE(  58)		outArray = inArray->copy();
HXLINE(  59)		outArray->reverse();
HXLINE(  61)		this->animation->add(HX_("empty",8d,3a,da,6f),::Array_obj< int >::fromData( _hx_array_data_b71a541c_2,1),0,false,null(),null());
HXLINE(  62)		this->animation->add(HX_("in",e5,5b,00,00),inArray,FrameRate,false,null(),null());
HXLINE(  63)		this->animation->add(HX_("full",8f,e9,c4,43),::Array_obj< int >::__new(1)->init(0,(this->numFrames - 1)),0,false,null(),null());
HXLINE(  64)		this->animation->add(HX_("out",8e,a0,54,00),outArray,FrameRate,false,null(),null());
HXLINE(  66)		this->setStatus(3);
            	}

Dynamic FlxTransitionSprite_obj::__CreateEmpty() { return new FlxTransitionSprite_obj; }

void *FlxTransitionSprite_obj::_hx_vtable = 0;

Dynamic FlxTransitionSprite_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< FlxTransitionSprite_obj > _hx_result = new FlxTransitionSprite_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return _hx_result;
}

bool FlxTransitionSprite_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x3cb08108) {
		if (inClassId<=(int)0x2c01639b) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x2c01639b;
		} else {
			return inClassId==(int)0x3cb08108;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

void FlxTransitionSprite_obj::start(int NewStatus){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_70_start)
HXLINE(  71)		this->_starting = true;
HXLINE(  72)		this->_finished = false;
HXLINE(  73)		this->_count = ( (Float)(0) );
HXLINE(  74)		this->_newStatus = NewStatus;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxTransitionSprite_obj,start,(void))

void FlxTransitionSprite_obj::startStatus(int NewStatus){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_79_startStatus)
HXDLIN(  79)		this->setStatus(NewStatus);
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxTransitionSprite_obj,startStatus,(void))

void FlxTransitionSprite_obj::setStatus(int Status){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_83_setStatus)
HXLINE(  84)		::String anim;
HXDLIN(  84)		switch((int)(Status)){
            			case (int)-1: case (int)2: {
HXLINE(  84)				anim = HX_("empty",8d,3a,da,6f);
            			}
            			break;
            			case (int)0: {
HXLINE(  84)				anim = HX_("in",e5,5b,00,00);
            			}
            			break;
            			case (int)1: {
HXLINE(  84)				anim = HX_("out",8e,a0,54,00);
            			}
            			break;
            			case (int)3: {
HXLINE(  84)				anim = HX_("full",8f,e9,c4,43);
            			}
            			break;
            		}
HXLINE(  92)		this->animation->play(anim,null(),null(),null());
HXLINE(  93)		this->animation->finishCallback = this->onFinishAnim_dyn();
HXLINE(  94)		this->status = Status;
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxTransitionSprite_obj,setStatus,(void))

void FlxTransitionSprite_obj::onFinishAnim(::String str){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_99_onFinishAnim)
HXDLIN(  99)		if (!(this->_finished)) {
HXLINE( 101)			this->_finished = true;
HXLINE( 102)			switch((int)(this->status)){
            				case (int)0: {
HXLINE( 105)					this->setStatus(3);
            				}
            				break;
            				case (int)1: {
HXLINE( 107)					this->setStatus(2);
            				}
            				break;
            				default:{
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(FlxTransitionSprite_obj,onFinishAnim,(void))

void FlxTransitionSprite_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_114_update)
HXLINE( 115)		this->super::update(elapsed);
HXLINE( 116)		if (this->_starting) {
HXLINE( 118)			 ::flixel::addons::transition::FlxTransitionSprite _hx_tmp = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN( 118)			_hx_tmp->_count = (_hx_tmp->_count + elapsed);
HXLINE( 119)			if ((this->_count >= this->_delay)) {
HXLINE( 121)				this->onTime();
            			}
            		}
            	}


void FlxTransitionSprite_obj::onTime(){
            	HX_STACKFRAME(&_hx_pos_c4312f005b5b0457_127_onTime)
HXLINE( 128)		this->_starting = false;
HXLINE( 129)		this->_count = ( (Float)(0) );
HXLINE( 130)		this->setStatus(this->_newStatus);
HXLINE( 131)		this->_newStatus = -1;
            	}


HX_DEFINE_DYNAMIC_FUNC0(FlxTransitionSprite_obj,onTime,(void))


::hx::ObjectPtr< FlxTransitionSprite_obj > FlxTransitionSprite_obj::__new(::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,Float Delay, ::Dynamic Graphic,::hx::Null< int >  __o_GraphicWidth,::hx::Null< int >  __o_GraphicHeight,::hx::Null< int >  __o_FrameRate) {
	::hx::ObjectPtr< FlxTransitionSprite_obj > __this = new FlxTransitionSprite_obj();
	__this->__construct(__o_X,__o_Y,Delay,Graphic,__o_GraphicWidth,__o_GraphicHeight,__o_FrameRate);
	return __this;
}

::hx::ObjectPtr< FlxTransitionSprite_obj > FlxTransitionSprite_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< Float >  __o_X,::hx::Null< Float >  __o_Y,Float Delay, ::Dynamic Graphic,::hx::Null< int >  __o_GraphicWidth,::hx::Null< int >  __o_GraphicHeight,::hx::Null< int >  __o_FrameRate) {
	FlxTransitionSprite_obj *__this = (FlxTransitionSprite_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(FlxTransitionSprite_obj), true, "flixel.addons.transition.FlxTransitionSprite"));
	*(void **)__this = FlxTransitionSprite_obj::_hx_vtable;
	__this->__construct(__o_X,__o_Y,Delay,Graphic,__o_GraphicWidth,__o_GraphicHeight,__o_FrameRate);
	return __this;
}

FlxTransitionSprite_obj::FlxTransitionSprite_obj()
{
}

::hx::Val FlxTransitionSprite_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return ::hx::Val( start_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_delay") ) { return ::hx::Val( _delay ); }
		if (HX_FIELD_EQ(inName,"_count") ) { return ::hx::Val( _count ); }
		if (HX_FIELD_EQ(inName,"status") ) { return ::hx::Val( status ); }
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		if (HX_FIELD_EQ(inName,"onTime") ) { return ::hx::Val( onTime_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_starting") ) { return ::hx::Val( _starting ); }
		if (HX_FIELD_EQ(inName,"_finished") ) { return ::hx::Val( _finished ); }
		if (HX_FIELD_EQ(inName,"setStatus") ) { return ::hx::Val( setStatus_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_newStatus") ) { return ::hx::Val( _newStatus ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"startStatus") ) { return ::hx::Val( startStatus_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onFinishAnim") ) { return ::hx::Val( onFinishAnim_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val FlxTransitionSprite_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_delay") ) { _delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_count") ) { _count=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_starting") ) { _starting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_finished") ) { _finished=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_newStatus") ) { _newStatus=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTransitionSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_delay",c4,1e,0e,d3));
	outFields->push(HX_("_count",10,8c,4a,46));
	outFields->push(HX_("_starting",1f,f9,41,8a));
	outFields->push(HX_("_finished",d1,8a,a4,dc));
	outFields->push(HX_("status",32,e7,fb,05));
	outFields->push(HX_("_newStatus",73,2f,4f,1f));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo FlxTransitionSprite_obj_sMemberStorageInfo[] = {
	{::hx::fsFloat,(int)offsetof(FlxTransitionSprite_obj,_delay),HX_("_delay",c4,1e,0e,d3)},
	{::hx::fsFloat,(int)offsetof(FlxTransitionSprite_obj,_count),HX_("_count",10,8c,4a,46)},
	{::hx::fsBool,(int)offsetof(FlxTransitionSprite_obj,_starting),HX_("_starting",1f,f9,41,8a)},
	{::hx::fsBool,(int)offsetof(FlxTransitionSprite_obj,_finished),HX_("_finished",d1,8a,a4,dc)},
	{::hx::fsInt,(int)offsetof(FlxTransitionSprite_obj,status),HX_("status",32,e7,fb,05)},
	{::hx::fsInt,(int)offsetof(FlxTransitionSprite_obj,_newStatus),HX_("_newStatus",73,2f,4f,1f)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *FlxTransitionSprite_obj_sStaticStorageInfo = 0;
#endif

static ::String FlxTransitionSprite_obj_sMemberFields[] = {
	HX_("_delay",c4,1e,0e,d3),
	HX_("_count",10,8c,4a,46),
	HX_("_starting",1f,f9,41,8a),
	HX_("_finished",d1,8a,a4,dc),
	HX_("status",32,e7,fb,05),
	HX_("_newStatus",73,2f,4f,1f),
	HX_("start",62,74,0b,84),
	HX_("startStatus",34,45,e2,7d),
	HX_("setStatus",74,5c,a3,65),
	HX_("onFinishAnim",03,ba,ef,a4),
	HX_("update",09,86,05,87),
	HX_("onTime",cc,d4,86,ef),
	::String(null()) };

::hx::Class FlxTransitionSprite_obj::__mClass;

void FlxTransitionSprite_obj::__register()
{
	FlxTransitionSprite_obj _hx_dummy;
	FlxTransitionSprite_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("flixel.addons.transition.FlxTransitionSprite",1c,54,1a,b7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(FlxTransitionSprite_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< FlxTransitionSprite_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = FlxTransitionSprite_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = FlxTransitionSprite_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace flixel
} // end namespace addons
} // end namespace transition
