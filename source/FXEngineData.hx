// Stolen from KE LOL!
import flixel.FlxG;

class FXEngineData
{
    public static function initSave()
    {
		if (FlxG.save.data.zxnm == null)
			FlxG.save.data.zxnm = false;

		if (FlxG.save.data.offset == null)
			FlxG.save.data.offset = 0;

        if (FlxG.save.data.offset == null)
			FlxG.save.data.offset = 0;

        if (FlxG.save.data.songPosition == null)
            FlxG.save.data.songPosition = false;
    }
}