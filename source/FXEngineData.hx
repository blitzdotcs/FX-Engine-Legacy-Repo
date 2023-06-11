// Stolen from KE LOL!
import flixel.FlxG;
import flixel.input.gamepad.FlxGamepad;

class FXEngineData
{   
    public static function initSave()
    {	
		if (FlxG.save.data.zxnm == null)
			FlxG.save.data.zxnm = false;

        if (FlxG.save.data.midscroll == null)
			FlxG.save.data.midscroll = false;

	    if (FlxG.save.data.downscroll == null)
		   FlxG.save.data.downscroll = false;

        if (FlxG.save.data.iconbops == null)
            FlxG.save.data.iconbops = false;     

        if (FlxG.save.data.quaverbar == null)
            FlxG.save.data.quaverbar = false; 

        if (FlxG.save.data.icons == null)
            FlxG.save.data.icons = false; 

        if (FlxG.save.data.songPosition == null)
            FlxG.save.data.songPosition = false;
    }

	@:keep public static inline function framerateAdjust(input:Float):Float 
    {
		return FlxG.elapsed * 60 * input;
	}

}