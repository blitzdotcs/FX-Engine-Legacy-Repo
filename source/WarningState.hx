package;

import openfl.ui.Keyboard;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import lime.app.Application;

class WarningState extends MusicBeatState
{
	public static var leftState:Bool = false;

	override function create()
	{
		super.create();
		var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		add(bg);
		var txt:FlxText = new FlxText(0, 0, FlxG.width,
			"Yo what's up, TyDev here! Thanks for using FX Engine! Anyways I hope you have a great time using this engine lolz."
			+ "\nAlso week 6 is broken sorry mates\n"
			+ "\nAlso also, sorry that this shows up every time lolz\n"
            + "\nAlso also also, modding support is almost done, just gotta make the songs load when you select them in the Story Menu\n"
			+ "press any key to continue!",
			32);
		txt.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER);
		txt.screenCenter();
		add(txt);
	}

	override function update(elapsed:Float)
	{
		if (FlxG.keys.anyPressed([ANY]))
		{
			leftState = true;
			FlxG.switchState(new MainMenuState());
		}
		super.update(elapsed);
	}
}