package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;

class ModMenuState extends FlxState {
  
  private var modMenuText: FlxText;
  private var backButton: FlxSprite;
  private var modIcons: Array<FlxSprite>; // Array to hold the mod icons
  
  override public function create():Void {
    FlxG.camera.bgColor = 0xff000000;
    
    modMenuText = new FlxText(0, FlxG.height / 2 - 20, FlxG.width, "Mods");
    modMenuText.setFormat(null, 32, 0xffffff, "center");
    add(modMenuText);
    
    backButton = new FlxSprite(FlxG.width / 2 - 40, FlxG.height - 80);
    backButton.makeGraphic(80, 40, 0xffaaaaaa);
    backButton.setFormat(null, 16, 0xffffff, "center");
    backButton.text = "Back";
    backButton.onUp = goBack;
    add(backButton);
    
    modIcons = new Array<FlxSprite>();
    var modList:Array<String> = polymod.Polymod.getMods();
    var yOffset:Int = 100;
    
    for (mod in modList) {
      var modIcon:FlxSprite = new FlxSprite(FlxG.width / 2 - 100, yOffset);
      modIcon.loadGraphic(mod, false, false, 64, 64); // Assuming the mod icon is a 64x64 image
      add(modIcon);
      modIcons.push(modIcon);
      yOffset += 80; // Increase the vertical offset for the next mod icon
    }
  }
  
  private function goBack():Void {
    FlxG.switchState(new MainMenuState());
  }
  
  override public function update(elapsed:Float):Void {
    super.update(elapsed);
    
    // Handle input to go back using the Escape key
    if (FlxG.keys.justPressed.ESCAPE) {
      goBack();
    }
  }
}
