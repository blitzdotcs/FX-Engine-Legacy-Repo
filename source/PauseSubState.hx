package;

import flixel.util.FlxTimer;
import Controls.Control;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.addons.transition.FlxTransitionableState;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.input.keyboard.FlxKey;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;

using StringTools;

class PauseSubState extends MusicBeatSubstate
{
	var grpMenuShit:FlxTypedGroup<Alphabet>;
	var grpOptionShit:FlxTypedGroup<FlxText>;

	var menuItems:Array<String> = ['Resume', 'Restart Song', 'Toggle practice mode', 'Options', 'Exit to menu'];
	var curSelected:Int = 0;

	var pauseMusic:FlxSound;

	var practice:FlxText;

	public function new(x:Float, y:Float)
	{
		super();

		pauseMusic = new FlxSound().loadEmbedded(Paths.music('breakfast'), true, true);
		pauseMusic.volume = 0;
		pauseMusic.play(false, FlxG.random.int(0, Std.int(pauseMusic.length / 2)));

		FlxG.sound.list.add(pauseMusic);

		var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bg.alpha = 0;
		bg.scrollFactor.set();
		add(bg);

		grpOptionShit = new FlxTypedGroup<FlxText>();
		add(grpOptionShit);

		var levelInfo:FlxText = new FlxText(20, 15, 0, "", 32);
		levelInfo.text += PlayState.SONG.song;
		levelInfo.scrollFactor.set();
		levelInfo.setFormat(Paths.font("vcr.ttf"), 32);
		levelInfo.updateHitbox();
		grpOptionShit.add(levelInfo);

		var levelDifficulty:FlxText = new FlxText(20, 15 + 32, 0, "", 32);
		levelDifficulty.text += CoolUtil.difficultyString();
		levelDifficulty.scrollFactor.set();
		levelDifficulty.setFormat(Paths.font('vcr.ttf'), 32);
		levelDifficulty.updateHitbox();
		grpOptionShit.add(levelDifficulty);

		var blueBalled:FlxText = new FlxText(20, 32 + 48, 0, "Blue-balled: 0", 32);
		blueBalled.text = "Blue-balled: " + PlayState.deaths;
		blueBalled.scrollFactor.set();
		blueBalled.setFormat(Paths.font('vcr.ttf'), 32);
		blueBalled.updateHitbox();
		grpOptionShit.add(blueBalled);

		practice = new FlxText(20, blueBalled.y + 32, 0, "PRACTICE MODE", 32);
		practice.scrollFactor.set();
		practice.setFormat(Paths.font('vcr.ttf'), 32);
		practice.updateHitbox();
		grpOptionShit.add(practice);

		practice.visible = PlayState.practiceMode;
		blueBalled.alpha = 0;
		levelDifficulty.alpha = 0;
		levelInfo.alpha = 0;

		levelInfo.x = FlxG.width - (levelInfo.width + 20);
		levelDifficulty.x = FlxG.width - (levelDifficulty.width + 20);
		blueBalled.x = FlxG.width - (blueBalled.width + 20);
		practice.x = FlxG.width - (practice.width + 20);

		FlxTween.tween(bg, {alpha: 0.6}, 0.4, {ease: FlxEase.quartInOut});
		FlxTween.tween(levelInfo, {alpha: 1, y: 20}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0.3});
		FlxTween.tween(levelDifficulty, {alpha: 1, y: levelDifficulty.y + 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0.5});
		FlxTween.tween(blueBalled, {alpha: 1, y: blueBalled.y + 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0.7});

		grpMenuShit = new FlxTypedGroup<Alphabet>();
		add(grpMenuShit);

		for (i in 0...menuItems.length)
		{
			var songText:Alphabet = new Alphabet(0, (70 * i) + 30, menuItems[i], true, false);
			songText.isMenuItem = true;
			songText.targetY = i;
			grpMenuShit.add(songText);
		}

		changeSelection();

		cameras = [FlxG.cameras.list[FlxG.cameras.list.length - 1]];
	}

	var antiSpam:Bool = false;

	override function update(elapsed:Float)
	{
		if (pauseMusic.volume < 0.5)
			pauseMusic.volume += 0.01 * elapsed;

		super.update(elapsed);

		var upP = controls.UP_P;
		var downP = controls.DOWN_P;
		var accepted = controls.ACCEPT;

		if (upP)
		{
			changeSelection(-1);
		}
		if (downP)
		{
			changeSelection(1);
		}

		if (accepted && !antiSpam)
		{
			var daSelected:String = menuItems[curSelected];

			switch (daSelected)
			{
				case "Resume":
					antiSpam = true;
					
				case "Restart Song":
					FlxG.resetState();

				case "Toggle practice mode":
					PlayState.practiceMode = !PlayState.practiceMode;
					practice.visible = PlayState.practiceMode;
					trace("PRACTICE MODE: " + PlayState.practiceMode, practice.visible);

//				case 'Botplay':
//					PlayState.instance.cpuControlled = !PlayState.instance.cpuControlled;
//					PlayState.instance.botplayTxt.visible = PlayState.instance.cpuControlled;
//					PlayState.instance.botplayTxt.alpha = 1;
//					PlayState.instance.botplaySine = 0;

				case "Options":
					FlxG.switchState(new InGameOptionsMenu());

				case "Exit to menu":
					FlxG.switchState(new MainMenuState());
			}
		}

		if (FlxG.keys.justPressed.J)
		{
			// for reference later!
			// PlayerSettings.player1.controls.replaceBinding(Control.LEFT, Keys, FlxKey.J, null);
		}
	}

	override function destroy()
	{
		pauseMusic.destroy();

		super.destroy();
	}

	function changeSelection(change:Int = 0):Void
	{
		curSelected += change;

		if (curSelected < 0)
			curSelected = menuItems.length - 1;
		if (curSelected >= menuItems.length)
			curSelected = 0;

		var bullShit:Int = 0;

		for (item in grpMenuShit.members)
		{
			item.targetY = bullShit - curSelected;
			bullShit++;

			item.alpha = 0.6;
			// item.setGraphicSize(Std.int(item.width * 0.8));

			if (item.targetY == 0)
			{
				item.alpha = 1;
				// item.setGraphicSize(Std.int(item.width));
			}
		}
	}
}