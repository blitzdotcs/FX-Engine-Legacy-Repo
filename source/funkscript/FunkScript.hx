// Literally just HScript but for funkin
package funkscript;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.text.FlxText;
import flixel.system.FlxSound;
import flixel.math.FlxMath;
import hscript.Parser;
import hscript.Interp;
import StringTools;
#if MODS_ALLOWED
import sys.FileSystem;
#end

class SongScript {
    public var interp = new Interp();
	public var parser = new Parser();
	public var script:hscript.Expr;

	public function new()
	{
		parser.allowTypes = true;
		parser.allowJSON = true;
		parser.allowMetadata = true;
		interp.variables.set("create", FlxG.state.create);
		interp.variables.set("update", FlxG.state.update);
		interp.variables.set("Int", Int);
		interp.variables.set("String", String);
		interp.variables.set("Float", Float);
		interp.variables.set("Array", Array);
		interp.variables.set("Bool", Bool);
		interp.variables.set("Dynamic", Dynamic);
		interp.variables.set("Math", Math);
		interp.variables.set("Main", Main);
		interp.variables.set("FlxMath", FlxMath);
		interp.variables.set("Std", Std);
		interp.variables.set("StringTools", StringTools);
		interp.variables.set("FlxG",FlxG);
		interp.variables.set("FlxSound",FlxSound);
		interp.variables.set("FlxSprite",FlxSprite);
		interp.variables.set("FlxText",FlxText);
		interp.variables.set("Paths",Paths);
		interp.variables.set("CoolUtil",CoolUtil);
	}

	public function call(funcName:String, ?args:Array<Dynamic>):Dynamic
	{
		if (args == null)
			args = [];
		// if(!running) return true;
		try
		{
			var func:Dynamic = interp.variables.get(funcName);
			if (func != null && Reflect.isFunction(func))
				return Reflect.callMethod(null, func, args);
		}
		catch (e)
		{
			// scriptType = EmptyScript;
			FlxG.log.add(e.details());
			// running = false;
		}
		return true;
	}

	public function loadScript(file:String)
	{
		script = parser.parseString(openfl.Assets.getText(Paths.getSongScript('$file')));
		interp.execute(script);
	}

    #if MODS_ALLOWED
	public function loadModScript(file:String)
    {
        script = parser.parseString(openfl.Assets.getText(Paths.getmodSongScript('$file')));
        interp.execute(script);
    }
    #end    
}

class ModchartAPI {
	public static function triggerEvent(event:String, ?arg1:Dynamic, ?arg2:Dynamic) {
		switch(event) {
			case "Camera Zoom":
				FlxG.camera.zoom += arg1;
		}
	}
}