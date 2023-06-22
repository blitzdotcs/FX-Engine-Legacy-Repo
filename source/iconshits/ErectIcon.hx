package iconshits;

import flixel.FlxSprite;

class FreePlayIcon extends FlxSprite
{
    /**
     * Used for FreePlay! If you use it elsewhere, prob gonna annoying
     */
    public var sprTracker:FlxSprite;

    public function new(char:String = 'bf', isPlayer:Bool = false)
    {
        super();
        loadGraphic(Paths.image('icons/erect/icon-' + char), true, 150, 150);

		antialiasing = true;
		animation.add('bf-erect', [0, 1], 0, false, isPlayer);
		animation.add('spooky-erect', [2, 3], 0, false, isPlayer);
		animation.add('daddy-erect', [12, 13], 0, false, isPlayer);
		animation.play(char);
		scrollFactor.set();
    }

    override function update(elapsed:Float)
    {
        super.update(elapsed);

        if (sprTracker != null)
            setPosition(sprTracker.x + sprTracker.width + 10, sprTracker.y - 30);
    }
}
