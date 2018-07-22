#include "Menu.hpp"
#include "Play.hpp"
#include <irrKlang.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrKlang.lib")
#endif

static void
Pos_ImageMenu_Curseur(SAppContext& app)
{
  switch (app.Width_Window)
    {
    case 640:
	{
	  app.Image_Curseur = app.Driver->getTexture("../texture/Menu/sword_600.png");
	  app.Gui->clear();
	  switch (app.Position)
	    {
	    case SETTING: app.Pos_Curseur = irr::core::position2d<s32>(158, 182); break;
	    case GAME: app.Pos_Curseur = irr::core::position2d<s32>(158, 116); break;
	    case CREDITS: app.Pos_Curseur = irr::core::position2d<s32>(158, 253); break;
	    case QUIT: app.Pos_Curseur = irr::core::position2d<s32>(158, 331); break;
	    default: break;
	    }
	  break;
	}
    case 800:
	{
	  app.Image_Curseur = app.Driver->getTexture("../texture/Menu/sword_800.png");
	  app.Gui->clear();
	  switch (app.Position)
	    {
	    case SETTING: app.Pos_Curseur = irr::core::position2d<s32>(238, 227); break;
	    case GAME: app.Pos_Curseur = irr::core::position2d<s32>(238, 154); break;
	    case CREDITS: app.Pos_Curseur = irr::core::position2d<s32>(238, 308); break;
	    case QUIT: app.Pos_Curseur = irr::core::position2d<s32>(238, 395); break;
	    default: break;
	    }
	  break;
	}
    case 1024:
	{
	  app.Image_Curseur = app.Driver->getTexture("../texture/Menu/sword_1024.png");
	  app.Gui->clear();
	  switch (app.Position)
	    {
	    case SETTING: app.Pos_Curseur = irr::core::position2d<s32>(285, 292); break;
	    case GAME: app.Pos_Curseur = irr::core::position2d<s32>(285, 203); break;
	    case CREDITS: app.Pos_Curseur = irr::core::position2d<s32>(285, 391); break;
	    case QUIT: app.Pos_Curseur = irr::core::position2d<s32>(285, 496); break;
	    default: break;
	    }
	  break;
	}
    case 1920:
	{
	  app.Image_Curseur = app.Driver->getTexture("../texture/Menu/sword_1920.png");
	  app.Gui->clear();
	  switch (app.Position)
	    {
	    case SETTING: app.Pos_Curseur = irr::core::position2d<s32>(561, 354); break;
	    case GAME: app.Pos_Curseur = irr::core::position2d<s32>(561, 162); break;
	    case CREDITS: app.Pos_Curseur = irr::core::position2d<s32>(561, 557); break;
	    case QUIT: app.Pos_Curseur = irr::core::position2d<s32>(561, 782); break;
	    default: break;
	    }
	  break;
	}
    default: break;
    }
}

static void
Pos_ImageMenu_BG(SAppContext& app)
{
  switch (app.Width_Window)
    {
    case 640: app.Image_Menu = app.Driver->getTexture("../texture/Menu/Menu_640.png"); break;
    case 800: app.Image_Menu = app.Driver->getTexture("../texture/Menu/Menu_800.png"); break;
    case 1024: app.Image_Menu = app.Driver->getTexture("../texture/Menu/Menu_1024.png"); break;
    case 1920: app.Image_Menu = app.Driver->getTexture("../texture/Menu/Menu_1920.png"); break;
    default: break;
    }
}

static int
Settings(SAppContext& app)
{
  SIrrlichtCreationParameters		param;
  map<stringw, dimension2du>::Node*	res;
  map<stringw, s32>::Node*		driver;

  param.DriverType = EDT_SOFTWARE;
  app.Settings = new SettingManager("../Save/settings.xml");
  if (!app.Settings->load())
    return (-1);
  driver = app.Settings->DriverOptions.find(app.Settings->getSetting("driver"));
  if (driver)
    if (irr::IrrlichtDevice::isDriverSupported(static_cast<E_DRIVER_TYPE>
					       (driver->getValue())))
      param.DriverType = static_cast<E_DRIVER_TYPE>(driver->getValue());
  res = app.Settings->ResolutionOptions.find(app.Settings->getSetting("resolution"));
  if (res)
    param.WindowSize = res->getValue();
  param.Fullscreen = app.Settings->getSettingAsBoolean("fullscreen");
  app.Device = createDeviceEx(param);
  if (app.Device == 0)
    return (-1);
  app.Device->setWindowCaption(L"GAME");
  app.Driver = app.Device->getVideoDriver();
  app.Gui = app.Device->getGUIEnvironment();
  app.Position = SETTING;
  app.Width_Window = param.WindowSize.Width;
  app.Height_Window = param.WindowSize.Height;
  app.screan = param.Fullscreen;
  return (0);
}

static void
Image_Play_BG(SAppContext& app)
{
  switch (app.Width_Window)
    {
    case 640: app.Image_Play_BG = app.Driver->getTexture("../texture/Play/Font/font_640.png"); break;
    case 800: app.Image_Play_BG = app.Driver->getTexture("../texture/Play/Font/font_800.png"); break;
    case 1024: app.Image_Play_BG = app.Driver->getTexture("../texture/Play/Font/font_1024.png"); break;
    case 1920: app.Image_Play_BG = app.Driver->getTexture("../texture/Play/Font/font_1920.png"); break;
    default: break;
    }

}

static void
Image_Player_640(SAppContext& app)
{
  if (app.Choise_Character1 == 0 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_640.png");
  if (app.Choise_Character1 == 1 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_640.png");
  if (app.Ok_P1 == true)
    {
      if (app.Choise_Character1 == 0)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_640_ok.png");
      else if (app.Choise_Character1 == 1)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_640_ok.png");
    }
  app.Pos_P1 = irr::core::position2d<s32>(127, 204);
  if (app.P2 == true)
    {
      if (app.Choise_Character2 == 0 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_640.png");
      if (app.Choise_Character2 == 1 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_640.png");
      if (app.Ok_P2 == true)
	{
	  if (app.Choise_Character2 == 0)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_640_ok.png");
	  else if (app.Choise_Character2 == 1)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_640_ok.png");
	}
      app.Pos_P2 = irr::core::position2d<s32>(321, 172);
    }
}

static void
Image_Player_800(SAppContext& app)
{
  if (app.Choise_Character1 == 0 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_800.png");
  if (app.Choise_Character1 == 1 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_800.png");
  if (app.Ok_P1 == true)
    {
      if (app.Choise_Character1 == 0)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_800_ok.png");
      else if (app.Choise_Character1 == 1)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_800_ok.png");
    }
  app.Pos_P1 = irr::core::position2d<s32>(157, 246);
  if (app.P2 == true)
    {
      if (app.Choise_Character2 == 0 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_800.png");
      if (app.Choise_Character2 == 1 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_800.png");
      if (app.Ok_P2 == true)
	{
	  if (app.Choise_Character2 == 0)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_800_ok.png");
	  else if (app.Choise_Character2 == 1)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_800_ok.png");
	}
      app.Pos_P2 = irr::core::position2d<s32>(405, 209);
    }
}

static void
Image_Player_1024(SAppContext& app)
{
  if (app.Choise_Character1 == 0 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1024.png");
  if (app.Choise_Character1 == 1 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_1024.png");
  if (app.Ok_P1 == true)
    {
      if (app.Choise_Character1 == 0)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1024_ok.png");
      else if (app.Choise_Character1 == 1)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_1024_ok.png");
    }
  app.Pos_P1 = irr::core::position2d<s32>(188, 285);
  if (app.P2 == true)
    {
      if (app.Choise_Character2 == 0 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1024.png");
      if (app.Choise_Character2 == 1 && app.Ok_P2 == false)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1024.png");
      if (app.Ok_P2 == true)
	{
	  if (app.Choise_Character2 == 0)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1024_ok.png");
	  else if (app.Choise_Character2 == 1)
	    app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_1024_ok.png");
	}
      app.Pos_P2 = irr::core::position2d<s32>(501, 237);
    }
}

static void
Image_Player_1920(SAppContext& app)
{
  if (app.Choise_Character1 == 0 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1920.png");
  if (app.Choise_Character1 == 1 && app.Ok_P1 == false)
    app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_1920.png");
  if (app.Ok_P1 == true)
    {
      if (app.Choise_Character1 == 0)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1920_ok.png");
      else if (app.Choise_Character1 == 1)
	app.Image_P1 = app.Driver->getTexture("../texture/Play/Mage/Mage_1920_ok.png");
    }
  app.Pos_P1 = irr::core::position2d<s32>(338, 318);
  if (app.P2 == true)
    {
      if (app.Choise_Character2 == 0)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Warrior/Warrior_1920.png");
      if (app.Choise_Character2 == 1)
	app.Image_P2 = app.Driver->getTexture("../texture/Play/Mage/Mage_1920.png");
      app.Pos_P2 = irr::core::position2d<s32>(940, 250);
    }
}

static void
Image_Play_Player(SAppContext& app)
{
  switch (app.Width_Window)
    {
    case 640: Image_Player_640(app); break;
    case 800: Image_Player_800(app); break;
    case 1024: Image_Player_1024(app); break;
    case 1920: Image_Player_1920(app); break;
    default: break;
    }
}

static void
menu_Play(SAppContext& app, MyEventReceiver& receiver)
{
  irr::video::SColor		blanc;

  blanc.set(255, 255, 255, 255);
  app.play = true;
  app.Gui->clear();
  Image_Play_BG(app);
  blanc.set(255, 255, 255, 255);
  app.Driver->draw2DImage(app.Image_Play_BG, irr::core::position2d<irr::s32> (0, 0),
			  irr::core::rect<irr::s32> (0, 0, 1920, 1080),
			  0, blanc, true);
  if (app.one == true)
    {
      Image_Play_Player(app);
      app.one = false;
    }
  if (receiver.IsKeyDown(irr::KEY_KEY_D) && app.Ok_P1 == false)
    {
      app.P1 = true;
      app.Choise_Character1++;
      if (app.Choise_Character1 > 1)
  	app.Choise_Character1 = 0;
      Image_Play_Player(app);
      app.Device->sleep(130);
    }
  if (receiver.IsKeyDown(irr::KEY_KEY_Q) && app.Ok_P1 == false)
    {
      app.P1 = true;
      app.Choise_Character1--;
      if (app.Choise_Character1 < 0)
  	app.Choise_Character1 = 1;
      Image_Play_Player(app);
      app.Device->sleep(130);
    }
  app.Gui->addImage(app.Image_P1, app.Pos_P1);
  if (receiver.IsKeyDown(irr::KEY_KEY_D) && app.Ok_P1 == true)
    {
      app.P2 = true;
      app.Choise_Character2++;
      if (app.Choise_Character2 > 1)
  	app.Choise_Character2 = 0;
      Image_Play_Player(app);
      app.Device->sleep(130);
    }
  if (app.P2 == true)
    app.Gui->addImage(app.Image_P2, app.Pos_P2);
  if (receiver.IsKeyDown(irr::KEY_KEY_Q) && app.Ok_P1 == true)
    {
      app.P2 = true;
      app.Choise_Character2--;
      if (app.Choise_Character2 < 0)
  	app.Choise_Character2 = 1;
      Image_Play_Player(app);
      app.Device->sleep(130);
    }
  if (receiver.IsKeyDown(irr::KEY_RETURN) && app.P1 == true)
    {
      if (app.Ok_P1 == true && app.Ok_P2 == false)
	{
	  Image_Play_Player(app);
	  app.In_Game = true;
	  app.play = false;
	  app.nbr_player = 1;
	  app.Driver->removeTexture(app.Image_P1);
	}
      if (app.Ok_P1 == false)
	{
	  app.Ok_P1 = true;
	  app.Device->sleep(200);
	}
      if (app.Ok_P1 == true && app.P2 == true)
	{
	  Image_Play_Player(app);
	  app.In_Game = true;
	  app.play = false;
	  app.nbr_player = 2;
	  app.Driver->removeTexture(app.Image_P1);
	  app.Driver->removeTexture(app.Image_P2);
	}
      Image_Play_Player(app);
    }
}

static void
menu_Credits(SAppContext& app)
{
  irr::video::SColor                 blanc;

  app.credits = true;
  app.Gui->clear();
  blanc.set(255, 255, 255, 255);
  app.Image_Credits_BG = app.Driver->getTexture("../texture/toto.jpg");
  app.Driver->draw2DImage(app.Image_Credits_BG, irr::core::position2d<irr::s32> (0, 0),
			  irr::core::rect<irr::s32> (0, 0, 1920, 1080),
			  0, blanc, true);
}

static void
menu_Main(SAppContext& app)
{
  irr::video::SColor                 blanc;

  Pos_ImageMenu_Curseur(app);
  Pos_ImageMenu_BG(app);
  blanc.set(255, 255, 255, 255);
  app.Driver->draw2DImage(app.Image_Menu, irr::core::position2d<irr::s32> (0, 0),
			  irr::core::rect<irr::s32> (0, 0, 1920, 1080),
			  0, blanc, true);
  app.Gui->addImage(app.Image_Curseur, app.Pos_Curseur);
}

static void
menu_Settings(SAppContext& app)
{
  map<stringw, s32>::Iterator           i;
  map<stringw, dimension2du>::Iterator  ri;

  app.Gui->clear();
  app.ok = true;
  switch (app.Width_Window)
    {
    case 1920: app.Gui->addImage(app.Driver->getTexture("../texture/Menu/settings_1920.png"),
				   irr::core::position2d<s32>(0, 0)); break;
    case 1024: app.Gui->addImage(app.Driver->getTexture("../texture/Menu/settings_1024.png"),
				   irr::core::position2d<s32>(0, 0)); break;
    case 800: app.Gui->addImage(app.Driver->getTexture("../texture/Menu/settings_800.png"),
				irr::core::position2d<s32>(0, 0)); break;
    case 640: app.Gui->addImage(app.Driver->getTexture("../texture/Menu/settings_640.png"),
				irr::core::position2d<s32>(0, 0)); break;
    default: break;
    }
  for (irr::s32 i = 0; i < irr::gui::EGDC_COUNT ; ++i)
    {
      irr::video::SColor col = app.Gui->getSkin()->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
      col.setAlpha(255);
      app.Gui->getSkin()->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }
  app.Gui->addStaticText (L"GRAPHICS DRIVERS",
			  rect< s32 >(10,50, 200, 60), false, true, 0);
  app.ListboxDriver = app.Gui->addListBox(rect<s32>(10,60,220,120), 0, 1, true);
  i = app.Settings->DriverOptions.getIterator();
  for (; !i.atEnd(); i++)
    app.ListboxDriver->addItem(i->getKey().c_str());
  app.ListboxDriver->setSelected(app.Settings->getSetting("driver").c_str());
  app.Gui->addStaticText (L"RESOLUTION", rect< s32 >(10,130, 200, 140),
			  false, true, 0);
  app.ListboxResolution = app.Gui->addListBox(rect<s32>(10,140,220,200), 0, 1,true);
  ri = app.Settings->ResolutionOptions.getIterator();
  for (; !ri.atEnd(); ri++)
    app.ListboxResolution->addItem(ri->getKey().c_str());
  app.ListboxResolution->setSelected(app.Settings->getSetting("resolution").c_str());
  app.CheckboxFullscreen = app.Gui->addCheckBox(app.Settings->getSettingAsBoolean("fullscreen"),
						rect<s32>(10,220,220,240), 0, -1,
						L"Fullscreen");
  app.ButtonSave = app.Gui->addButton(rect<s32>(100,300,200,320), 0, 2,
				      L"SAVE AND RESTART", L"Save the configuration");
  app.ButtonExit = app.Gui->addButton(rect<s32>(250,350,350,370), 0, 2,
				      L"BACK TO MENU", L"return to the menu");
}

int
main2(int* height, int* width, int* Player1, int* Player2, bool* screan, int* nbr)
{
  SAppContext				app;

  app.engine = irrklang::createIrrKlangDevice();
  app.engine->play2D("../Media/main.ogg", true);
  if (Settings(app) == -1)
    return (-1);

  MyEventReceiver			receiver(app);

  app.ok = false;
  app.play = false;
  app.P2 = false;
  app.one = true;
  app.Ok_P1 = false;
  app.P1 = false;
  app.Ok_P2 = false;
  app.In_Game = false;
  app.credits = false;
  bool indie = true;
  app.Device->setEventReceiver(&receiver);
  app.Position = 1;
  app.Choise_Character1 = 0;
  app.Choise_Character2 = 0;
  irr::video::SColor                    blanc;
  int					tour = 0;
  std::cout << app.Width_Window << std::endl;
  switch (app.Width_Window)
    {
    case 1920:
      {
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie1_1920.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie2_1920.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie3_1920.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie4_1920.png");
	break;
      }
    case 1024:
      {
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie1_1024.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie2_1024.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie3_1024.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie4_1024.png");
	break;
      }
    case 800:
      {
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie1_800.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie2_800.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie3_800.png");
	  app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie4_800.png");
	break;
      }
    case 640:
      {
	app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie1_640.png");
	app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie2_640.png");
	app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie3_640.png");
	app.list_indie_studio_gif_start.push_back("../texture/Demarage/indie4_640.png");
	break;
      }
    default: break;
    }
  blanc.set(255, 255, 255, 255);
  while (!app.ShouldQuit && app.Device->run())
    {
      while (indie == true)
      	{
      	  for (std::list<std::string>::iterator it = app.list_indie_studio_gif_start.begin();
      	       true; ++it)
      	    {
      	      if (it == app.list_indie_studio_gif_start.end())
      		{
      		  tour++;
      		  it = app.list_indie_studio_gif_start.begin();
      		  if (tour == 2)
      		    {
      		      indie = false;
      		      break;
      		    }
      		}
      	      app.image_tempo = app.Driver->getTexture((*it).c_str());
      	      app.Driver->beginScene(true, true, irr::video::SColor(0, 120, 120, 120));
      	      app.Driver->makeColorKeyTexture(app.image_tempo,
      					      irr::core::position2d<irr::s32> (0, 0));
      	      app.Driver->draw2DImage(app.image_tempo, irr::core::position2d<irr::s32> (0, 0),
      				      irr::core::rect<irr::s32> (0, 0, 1920, 1080),
      				      0, blanc, true);
      	      app.Device->sleep(650);
      	      app.Driver->endScene();
      	    }
      	  break;
      	}
      app.Driver->beginScene(true, true, SColor(0,200,200,200));
      if (receiver.IsKeyDown(irr::KEY_ESCAPE) && (app.play == true || app.ok == true
						  || app.credits == true)
	       && app.In_Game == false)
	{
	  app.Gui->clear();
	  app.play = false;
	  app.one = true;
	  app.ok = false;
	  app.credits = false;
	  app.In_Game = false;
	  app.Position = GAME;
	  app.Ok_P2 = false;
	  app.Ok_P1 = false;
	  app.P2 = false;
	}
      else if (receiver.IsKeyDown(irr::KEY_KEY_S) && app.ok == false && app.play == false
	       && app.In_Game == false)
	{
	  app.Position++;
	  if (app.Position > 4)
	    app.Position = 1;
	  app.Device->sleep(130);
	}
      else if (receiver.IsKeyDown(irr::KEY_KEY_Z) && app.ok == false && app.play == false
	       && app.In_Game == false)
	{
	  app.Position--;
	  if (app.Position < 1)
	    app.Position = 4;
	  app.Device->sleep(130);
	}
      else if (receiver.IsKeyDown(irr::KEY_RETURN) && app.ok == false && app.play == false &&
	       app.In_Game == false)
	{
	  if (app.Position == SETTING)
	    menu_Settings(app);
	  else if (app.Position == GAME)
	      menu_Play(app, receiver);
	  else if (app.Position == CREDITS)
	    menu_Credits(app);
	  else if (app.Position == QUIT)
	    return (-1);
	}
      if (app.ok == false && app.play == true && app.In_Game == false)
	menu_Play(app, receiver);
      if (app.ok == false && app.play == false && app.In_Game == false)
	menu_Main(app);
      if (app.ok == false && app.play == false && app.credits == true && app.In_Game == false)
	menu_Credits(app);
      if (app.Device->isWindowActive())
	{
	  app.Gui->drawAll();
	  app.Driver->endScene();
	}
      if (app.In_Game == true)
	{
	  *width = app.Width_Window;
	  *height = app.Height_Window;
	  *nbr = app.nbr_player;
	  *screan = app.screan;
	  if (*nbr == 1)
	    *Player1 = app.Choise_Character1;
	  else if (*nbr == 2)
	    {
	      *Player1 = app.Choise_Character1;
	      *Player2 = app.Choise_Character2;
	    }
	  app.Device->closeDevice();
	  app.engine->drop();
	  return (0);
	}
    }
  return 0;
}

int
main(void)
{
  int Width = 0;
  int Height = 0;
  int Player1 = 0;
  int Player2 = 0;
  int nbr = 1;
  bool screan = false;
  
  if (!main2(&Width, &Height, &Player1, &Player2, &screan, &nbr))
    {
      std::cout << Player1 << std::endl;
      if (nbr == 2)
	{
	  std::cout << "2 PLayer" << std::endl;
	  Two_Player(Width, Height, screan,
		     Player1, Player2);
	}
      else if (nbr == 1)
	{
	  std::cout << "1 Player" << std::endl;
	  One_Player(Width, Height, screan, Player1);
	}
    }
  return (0);
}
