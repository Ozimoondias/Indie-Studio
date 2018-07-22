#include <irrlicht.h>
#include <iostream>
#include <list>
#include <fstream>
#include <stdio.h>

#ifdef _WIN32
#include <process.h
#else
#include <unistd.h>
#endif

#include <vector>
#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include <irrKlang.h>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib")

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

enum
  {
    GAME = 1,
    SETTING = 2,
    CREDITS = 3,
    QUIT = 4
  };

class	SettingManager
{

public:

  SettingManager(const stringw& settings_file): SettingsFile(settings_file), NullDevice(0)
	{
	  NullDevice = irr::createDevice(irr::video::EDT_NULL);
	  DriverOptions.insert(L"Software", EDT_SOFTWARE);
	  DriverOptions.insert(L"OpenGL", EDT_OPENGL);
	  DriverOptions.insert(L"LIB_LAPIN", EDT_OPENGL);
	  DriverOptions.insert(L"CACA_LIB", EDT_OPENGL);
	  DriverOptions.insert(L"Direct3D9", EDT_DIRECT3D9);

	  ResolutionOptions.insert(L"640x480", dimension2du(640,480));
	  ResolutionOptions.insert(L"800x600", dimension2du(800,600));
	  ResolutionOptions.insert(L"1024x768", dimension2du(1024,768));
	  ResolutionOptions.insert(L"1920x1080", dimension2du(1920,1080));

	  SettingMap.insert(L"driver", L"Direct3D9");
	  SettingMap.insert(L"resolution", L"640x480");
	  SettingMap.insert(L"fullscreen", L"0");
	}

  ~SettingManager()
  {
    if (NullDevice)
      {
	NullDevice->closeDevice();
	NullDevice->drop();
      }
  }

  bool
  load()
  {
    if (!NullDevice)
      return false;
    irr::io::IXMLReader*	xml = NullDevice->getFileSystem()->createXMLReader(SettingsFile);
    if (!xml)
      return false;

    const stringw		settingTag(L"setting");
    stringw			currentSection;
    const stringw		videoTag(L"video");

    while (xml->read())
      {
	switch (xml->getNodeType())
	  {
	  case irr::io::EXN_ELEMENT:
	    {
	      if (currentSection.empty() && videoTag.equals_ignore_case(xml->getNodeName()))
		currentSection = videoTag;
	      else if (currentSection.equals_ignore_case(videoTag)
		       && settingTag.equals_ignore_case(xml->getNodeName() ))
		{
		  stringw key = xml->getAttributeValueSafe(L"name");
		  if (!key.empty())
		    SettingMap[key] = xml->getAttributeValueSafe(L"value");
		}
	    }
	    break;
	  case irr::io::EXN_ELEMENT_END:
	    currentSection=L"";
	    break;
	  }
      }
    xml->drop();
    return true;
  }

  bool
  save()
  {
    if (!NullDevice)
      return false;
    irr::io::IXMLWriter* xwriter = NullDevice->getFileSystem()->createXMLWriter(SettingsFile);
    if (!xwriter)
      return false;
    xwriter->writeXMLHeader();
    xwriter->writeElement(L"mygame");
    xwriter->writeLineBreak();
    xwriter->writeElement(L"video");
    xwriter->writeLineBreak();
    map<stringw, stringw>::Iterator i = SettingMap.getIterator();
    for(; !i.atEnd(); i++)
      {
	xwriter->writeElement(L"setting",true, L"name",
			      i->getKey().c_str(), L"value",i->getValue().c_str());
	xwriter->writeLineBreak();
      }
    xwriter->writeLineBreak();
    xwriter->writeClosingTag(L"video");
    xwriter->writeLineBreak();
    xwriter->writeClosingTag(L"mygame");
    xwriter->drop();
    return (true);
  }

  void
  setSetting(const stringw& name, const stringw& value)
  {
    SettingMap[name]=value;
  }

  void
  setSetting(const stringw& name, s32 value)
  {
    SettingMap[name]=stringw(value);
  }

  stringw
  getSetting(const stringw& key) const
  {
    map<stringw, stringw>::Node* n;

    n = SettingMap.find(key);
    if (n)
      return n->getValue();
    else
      return (L"");
  }

  bool
  getSettingAsBoolean(const stringw& key ) const
  {
    stringw s;

    s = getSetting(key);
    if (s.empty())
      return false;
    return (s.equals_ignore_case(L"1"));
  }

  s32
  getSettingAsInteger(const stringw& key) const
  {
    const stringc s = getSetting(key);
    if (s.empty())
      return 0;
    return (strtol10(s.c_str()));
  }

public:

  map<stringw, s32> DriverOptions;
  map<stringw, dimension2du> ResolutionOptions;

private:

  SettingManager(const SettingManager& other);
  SettingManager& operator=(const SettingManager& other);
  map<stringw, stringw> SettingMap;
  stringw SettingsFile;
  irr::IrrlichtDevice* NullDevice;

};

struct SAppContext
{
  SAppContext()
    : Device(0),Gui(0), Driver(0), Settings(0), ShouldQuit(false),
      ButtonSave(0), ButtonExit(0), ListboxDriver(0),
      ListboxResolution(0), CheckboxFullscreen(0)
  {}

  ~SAppContext()
  {
    if (Settings)
      delete Settings;

    if (Device)
      {
	Device->closeDevice();
	Device->drop();
      }
  }

  IrrlichtDevice*		Device;
  IGUIEnvironment*		Gui;
  IVideoDriver*			Driver;
  SettingManager*		Settings;
  bool				ShouldQuit;

  IGUIButton*			ButtonEnter;
  IGUIButton*			ButtonSave;
  IGUIButton*			ButtonExit;
  IGUIListBox*			ListboxDriver;
  IGUIListBox*			ListboxResolution;
  IGUICheckBox*			CheckboxFullscreen;

  irr::video::ITexture*		Image;
  irr::video::ITexture*		Image_Menu;
  irr::video::ITexture*		Image_Credits_BG;
  irr::video::ITexture*		Image_Play_BG;
  unsigned int			Width_Window;
  unsigned int			Height_Window;
  bool				screan;
  bool				ok;
  bool				play;
  bool				credits;

  std::list<std::string>        list_indie_studio_gif_start;
  irr::video::ITexture*         image_tempo;

  irr::video::ITexture*		Image_P1;
  irr::core::position2d<s32>	Pos_P1;
  irr::video::ITexture*		Image_P2;
  irr::core::position2d<s32>	Pos_P2;
  int				Choise_Character1;
  int				Choise_Character2;
  bool				P2;
  bool				one;
  bool				Ok_P1;
  bool				Ok_P2;
  bool				P1;

  irr::video::ITexture*		Image_Curseur;
  unsigned int			Position;
  irr::core::position2d<s32>	Pos_Curseur;

  irrklang::ISoundEngine*       engine;

  bool				In_Game;
  int				nbr_player;
  irr::video::ITexture*		Paused;
  irr::video::ITexture*		Play_Test;

};

class	MyEventReceiver : public IEventReceiver
{
public:

  MyEventReceiver(SAppContext & a) : App(a)
  {
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

  virtual bool OnEvent(const SEvent& event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (event.EventType == EET_GUI_EVENT)
      {
	switch (event.GUIEvent.EventType)
	  {
	  case EGET_BUTTON_CLICKED:
	    {
	      if (event.GUIEvent.Caller == App.ButtonSave)
		{
		  if (App.ListboxDriver->getSelected() != -1)
		    App.Settings->setSetting(L"driver",
					     App.ListboxDriver->getListItem(App.ListboxDriver->
									    getSelected()));
		  if (App.ListboxResolution->getSelected() != -1)
		    App.Settings->setSetting(L"resolution",
					     App.ListboxResolution->
					     getListItem(App.ListboxResolution->getSelected()));
		  App.Settings->setSetting(L"fullscreen",
					   App.CheckboxFullscreen->isChecked());
		  if (App.Settings->save())
		    {
		      App.Gui->addMessageBox(L"settings save",
					     L"settings saved, please restart for settings to change effect","",true);
		      std::vector<const char *> Vector;
		      Vector.push_back("./indie_studio");
		      Vector.push_back(NULL);
		      char **command = (char **)(&Vector[0]);
			#ifdef _WIN32
				_execvp(*command, command);
			#else
				execvp(*command, command);
			#endif
		    }
		  App.ShouldQuit = true;
		}
	      else if (event.GUIEvent.Caller == App.ButtonExit)
		{
		  App.Gui->clear();
		  App.ok = false;
		  App.Position = GAME;
		}
	    }
	    break;
	  }
      }
    return false;
  }

  virtual bool IsKeyDown(EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }

private:

  bool		KeyIsDown[KEY_KEY_CODES_COUNT];
  SAppContext & App;

};
