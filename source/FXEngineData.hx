// Stolen from KE LOL!
import flixel.FlxG;
import flixel.input.gamepad.FlxGamepad;

class FXEngineData
{
    public static function initSave()
    {	
		if (FlxG.save.data.zxnm == null)
			FlxG.save.data.zxnm = false;

		if (FlxG.save.data.timeBarType == null)
			FlxG.save.data.timeBarType = timeBarType;

        if (FlxG.save.data.songPosition == null)
            FlxG.save.data.songPosition = false;
    }
}