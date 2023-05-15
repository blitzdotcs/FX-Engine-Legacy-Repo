package iconshits;

import flixel.FlxSprite;

class CreditsIcon extends FlxSprite
{
    /**
     * Used for Credits! If you use it elsewhere, prob gonna annoying
     */
    public var sprTracker:FlxSprite;

    public function new(char:String = 'bf', isPlayer:Bool = false)
    {
        super();
        loadGraphic(Paths.image('credits/icon-' + char), true, 150, 150);

        antialiasing = true;
        animation.add('ty', [0, 1], 0, false, isPlayer);
        animation.add('funkin', [0, 1], 0, false, isPlayer);
        animation.add('ke', [0, 1], 0, false, isPlayer);
        animation.add('psych', [21, 21], 0, false, isPlayer);
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
