package scripting.hscript;

import tea.SScript;
import Character;
import flixel.util.FlxColor;

#if (SScript >= "3.0.0")
class HScript extends SScript
{	
	public static function initHaxeModule(parent)
	{
		#if (SScript >= "3.0.0")
		if(parent.hscript == null)
		{
			trace('initializing haxe interp for: ${parent.scriptName}');
			parent.hscript = new HScript(parent);
		}
		#end
	}

	override public function new(parent)
	{
		super("", true);
	}

	override function preset()
	{
		#if (SScript >= "3.0.0")
		super.preset();

		set('FlxG', flixel.FlxG);
		set('FlxSprite', flixel.FlxSprite);
		set('FlxCamera', flixel.FlxCamera);
		set('FlxTimer', flixel.util.FlxTimer);
		set('FlxTween', flixel.tweens.FlxTween);
		set('FlxEase', flixel.tweens.FlxEase);
		set('PlayState', PlayState);
		set('game', PlayState.instance);
		set('Paths', Paths);
		set('Conductor', Conductor);
		set('ClientPrefs', ClientPrefs);
		set('FXEngineData', FXEngineData);
		set('Character', Character);
		set('Alphabet', Alphabet);
		set('ShaderFilter', openfl.filters.ShaderFilter);

		set('setVar', function(name:String, value:Dynamic)
		{
			PlayState.instance.variables.set(name, value);
		});
		set('getVar', function(name:String)
		{
			var result:Dynamic = null;
			if(PlayState.instance.variables.exists(name)) result = PlayState.instance.variables.get(name);
			return result;
		});
		set('removeVar', function(name:String)
		{
			if(PlayState.instance.variables.exists(name))
			{
				PlayState.instance.variables.remove(name);
				return true;
			}
			return false;
		});
		set('debugPrint', function(text:String, ?color:FlxColor = null) {
			if(color == null) color = FlxColor.WHITE;
		});

		// For adding your own callbacks

		// not very tested but should work
		set('createGlobalCallback', function(name:String, func:Dynamic)
		{
			#if LUA_ALLOWED
			for (script in PlayState.instance.luaArray)
				if(script != null && script.lua != null && !script.closed)
					Lua_helper.add_callback(script.lua, name, func);
			#end
		});

		// tested
		set('addHaxeLibrary', function(libName:String, ?libPackage:String = '') {
			try {
				var str:String = '';
				if(libPackage.length > 0)
					str = libPackage + '.';

				set(libName, Type.resolveClass(str + libName));
			}
		});
		#end
	}

	public function executeCode(codeToRun:String, ?funcToRun:String = null, ?funcArgs:Array<Dynamic>):SCall
	{
		doString(codeToRun);

		if (funcToRun != null)
		{
			var callValue = call(funcToRun, funcArgs);
			if (callValue.succeeded)
				return callValue.returnValue;
			else
			{
				var e = callValue.exceptions[0];
				return null;
			}
		}
		return null;
	}

	public function executeFunction(funcToRun:String = null, funcArgs:Array<Dynamic>):SCall
	{
		if (funcToRun == null)
			return null;

		return call(funcToRun, funcArgs);
	}
}
#end